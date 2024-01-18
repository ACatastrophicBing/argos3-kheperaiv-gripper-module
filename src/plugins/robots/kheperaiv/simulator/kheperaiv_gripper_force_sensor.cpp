/**
 * @file <argos3/plugins/robots/kheperaiv/simulator/kheperaiv__ground_rotzonly_sensor.cpp>
 *
 * @author Chandler Garcia - <crgarcia@wpi.edu>
 */

#include <argos3/core/simulator/simulator.h>
#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/core/simulator/entity/embodied_entity.h>
#include <argos3/core/simulator/entity/floor_entity.h>
#include <argos3/plugins/simulator/entities/ground_sensor_equipped_entity.h>

#include "kheperaiv_gripper_force_sensor.h"

namespace argos {

   /****************************************/
   /****************************************/

   CKheperaIVGripperForceSensor::CKheperaIVGripperForceSensor() :
     m_pcGripperEquippedEntity(nullptr),
     m_fExtension() {}

   /****************************************/
   /****************************************/

   void CKheperaIVGripperForceSensor::SetRobot(CComposableEntity& c_entity) {
      m_pcGripperEquippedEntity = &(c_entity.GetComponent<CGripperEquippedEntity>("gripper"));
      m_pcGripperEquippedEntity->Enable();
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperForceSensor::Init(TConfigurationNode& t_tree) {
      
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperForceSensor::Update() {
      m_fExtension = m_pcGripperEquippedEntity->GetExtension(); // Gets the extension, 
      //should be a normalized force but if it isn't, fix it peasant
      // Now get the location of the center of the robot
      // Get the location of the anchor point of the gripper
      // Get the location of the anchor point of the gripped object
      // Find the vector of gripper to gripped object with respect to center to gripper
      // Multiply vector by extension and set m_fPerpendicularForce m_fParallelForce m_cForceVector properly
      m_pcGripperEquippedEntity->m_pcGrippee(); // Calculates anchor point on grippable body
      cpConstraint* constraint = m_pcGripperEquippedEntity->GetConstraint(); // Gets the constraint
      cpVect gripper_anchr = constraint->anchr1;
      cpVect grippee_anchr = constraint->anchr2;
      SAnchor robot_anchor = m_pcGripperEquippedEntity.GetParent().GetOriginAnchor();
      // robot_anchor.GetX, robot_anchor.GetY
      // gripper_anchr.x, gripper_anchr.y
      // grippee_anchr.x, grippee_anchr.y
      cpVect robot_anchr = cpv(robot_anchor.GetX(), robot_anchor.GetY());
      // Figure out the math, I can't do this in controls holy fuck
      gripper_anchr = cpvsub(gripper_anchr,robot_anchr);
      cpFloat gripper_angle = cpvtoangle(gripper_anchr);
      grippee_anchr = cpvsub(grippee_anchr,robot_anchr);
      cpFloat grippee_angle = cpvtoangle(grippee_anchr);
      CRadians angle = CRadians(dynamic_cast<Real>((gripper_angle-grippee_angle)*CRadians::Pi));
      m_cForceVector = CVector2(1.0, angle);


      /*
      struct cpDampedSpring {
         cpConstraint constraint;
         cpVect anchr1, anchr2;
         cpFloat restLength;
         cpFloat stiffness;
         cpFloat damping;
         cpDampedSpringForceFunc springForceFunc;
         
         cpFloat target_vrn;
         cpFloat v_coef;
         
         cpVect r1, r2;
         cpFloat nMass;
         cpVect n;
      };
      */

   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperForceSensor::Reset() {
      
   }

   /****************************************/
   /****************************************/

   REGISTER_SENSOR(CKheperaIVGripperForceSensor,
                   "kheperaiv_gripper_force_sensor", "force",
                   "Chandler Garcia [crgarcia@wpi.edu]",
                   "1.0",
                   "The KheperaIV gripper force sensor.",
                   "TODO : Write a description of it here",
                   "Testing"
		  );

}
