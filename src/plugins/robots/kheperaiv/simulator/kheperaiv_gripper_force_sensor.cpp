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
      m_cForceVector = m_pcGripperEquippedEntity->GetForceSensor();
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
