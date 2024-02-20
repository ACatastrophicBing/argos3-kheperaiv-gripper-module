/**
 * @file <argos3/plugins/robots/kheperaiv/simulator/kheperaiv__ground_rotzonly_sensor.cpp>
 *
 * @author Chandler Garcia - <crgarcia@wpi.edu>
 */

#include <argos3/core/simulator/simulator.h>
#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/core/simulator/entity/embodied_entity.h>

#include "kheperaiv_gripper_force_sensor.h"

namespace argos {

   /****************************************/
   /****************************************/

   CKheperaIVGripperForceSensor::CKheperaIVGripperForceSensor() :
     m_pcGripperEquippedEntity(nullptr) {}
     
   /****************************************/
   /****************************************/

   CKheperaIVGripperForceSensor::~CKheperaIVGripperForceSensor() {
      delete m_pcGripperEquippedEntity;
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperForceSensor::SetRobot(CComposableEntity& c_entity) {
      m_pcGripperEquippedEntity = &(c_entity.GetComponent<CKheperaIVGripperEntity>("gripper"));
      m_pcGripperEquippedEntity->Enable();
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperForceSensor::Init(TConfigurationNode& t_tree) {
      
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperForceSensor::Update() {
      Real m_fExtension = m_pcGripperEquippedEntity->GetExtension(); // Gets the extension, probably don't need this
      //should be a normalized force but if it isn't, fix it peasant
      // Now get the location of the center of the robot
      // Get the location of the anchor point of the gripper
      // Get the location of the anchor point of the gripped object
      // Find the vector of gripper to gripped object with respect to center to gripper
      // Multiply vector by extension and set m_fPerpendicularForce m_fParallelForce m_cForceVector properly
      // m_pcGripperEquippedEntity->m_pcGrippee(); // Calculates anchor point on grippable body
      // cpConstraint* constraint = m_pcGripperEquippedEntity->GetConstraint(); // Gets the constraint
      // cpVect gripper_anchr = constraint->anchr1;
      // cpVect grippee_anchr = constraint->anchr2;
      CVector3 gripper_anchr = m_pcGripperEquippedEntity->GetAnchor1();
      CVector3 grippee_anchr = m_pcGripperEquippedEntity->GetAnchor2();
      CVector3 robot_anchor = m_pcGripperEquippedEntity->GetOriginAnchorRob();
      CVector3 vector_attachment = gripper_anchr - grippee_anchr;
      CVector3 vector_grip_direction = gripper_anchr - robot_anchor;
      CRadians vector_direction = vector_grip_direction.GetAngleWith(vector_attachment);
      m_cForceVector = CVector2(vector_attachment.Length(), vector_direction);
      // m_pcGripperEquippedEntity




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
      m_cForceVector = CVector2(0.0, 0.0);
   }

   /****************************************/
   /****************************************/

   REGISTER_SENSOR(CKheperaIVGripperForceSensor,
                   "kheperaiv_gripper_force", "default",
                   "Chandler Garcia [crgarcia@wpi.edu]",
                   "1.0",
                   "The KheperaIV GAARA Force sensor.",
                   "This sensor accesses the GAARA module force sensor. For a complete description\n"
                   "of its usage, refer to the ci_kheperaiv_gripper_force_sensor.h interface.  "
                   "REQUIRED XML CONFIGURATION\n\n"
                     "  <controllers>\n"
                     "    ...\n"
                     "    <my_controller ...>\n"
                     "      ...\n"
                     "      <actuators>\n"
                     "        ...\n"
                     "        <kheperaiv_grippper_force implementation=\"default\" />\n"
                     "        ...\n"
                     "      </actuators>\n"
                     "      ...\n"
                     "    </my_controller>\n"
                     "    ...\n"
                     "  </controllers>\n\n",
                   "Usable"
		  );

}
