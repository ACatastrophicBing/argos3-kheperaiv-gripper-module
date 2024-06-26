/**
 * @file <argos3/plugins/robots/kheperaiv/simulator/kheperaiv_gripper_default_actuator.cpp>
 *
 * @author Chandler Garcia */

#include "kheperaiv_gripper_default_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/simulator/entity/composable_entity.h>

namespace argos {

   /****************************************/
   /****************************************/

   CKheperaIVGripperDefaultActuator::CKheperaIVGripperDefaultActuator() :
      m_pcGripperEquippedEntity(nullptr) {}

   /****************************************/
   /****************************************/

   void CKheperaIVGripperDefaultActuator::SetRobot(CComposableEntity& c_entity) {
      m_pcGripperEquippedEntity = &(c_entity.GetComponent<CGripperEquippedEntity>("gripper"));
      m_pcGripperEquippedEntity->Enable();
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperDefaultActuator::Update() {
      // printf("Gripper Is Updating");
      // LOG << "[SIMULATION] Khepera Gripper has a locked state of " << m_cAperture << std::endl;
      // LOG << "[SIMULATION] CGripperEntity has a locked state of " << m_pcGripperEquippedEntity->GetLockState() << std::endl;
      m_pcGripperEquippedEntity->SetLockState(Abs(m_cAperture) / CRadians::PI_OVER_TWO);
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperDefaultActuator::Reset() {
      Unlock();
   }

   /****************************************/
   /****************************************/

}

REGISTER_ACTUATOR(CKheperaIVGripperDefaultActuator,
                  "kheperaiv_gripper", "default",
                  "Chandler Garcia [crgarcia@wpi.edu]",
                  "1.0",
                  "The kheperaiv gripper actuator.",
                  "This actuator controls the kheperaiv gripper. For a complete description of its\n"
                  "usage, refer to the ci_kheperaiv_gripper_actuator.h file.\n\n"
                  "REQUIRED XML CONFIGURATION\n\n"
                  "  <controllers>\n"
                  "    ...\n"
                  "    <my_controller ...>\n"
                  "      ...\n"
                  "      <actuators>\n"
                  "        ...\n"
                  "        <kheperaiv_gripper implementation=\"default\" />\n"
                  "        ...\n"
                  "      </actuators>\n"
                  "      ...\n"
                  "    </my_controller>\n"
                  "    ...\n"
                  "  </controllers>\n\n"
                  "OPTIONAL XML CONFIGURATION\n\n"
                  "None.\n",
                  "Usable"
   );

