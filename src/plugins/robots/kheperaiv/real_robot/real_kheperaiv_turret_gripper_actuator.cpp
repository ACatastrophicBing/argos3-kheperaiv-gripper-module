#include "real_kheperaiv_turret_gripper_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>


/****************************************/
/****************************************/

CRealKheperaIVTurretGripperActuator::CRealKheperaIVTurretGripperActuator(knet_dev_t* pt_dspic) :
   CRealKheperaIVDevice(pt_dspic) {
   cgripper_init();
   /* The gripper once on is automatically initialized */
}
   
/****************************************/
/****************************************/

CRealKheperaIVTurretGripperActuator::~CRealKheperaIVTurretGripperActuator() {
}
   
/****************************************/
/****************************************/

void CRealKheperaIVTurretGripperActuator::Do(Real f_elapsed_time) {
   switch(m_eGrip){
      case MODE_OPEN:
         cgripper_Open_Gripper();
         LOG << "[GRIPPER] Gripper Open\n" << std::endl;
         break;
         case MODE_CLOSED:
         LOG << "[GRIPPER] Gripper Closed\n" << std::endl;
         cgripper_Close_Gripper();
         break;
         default:
         LOG << "Invalid gripper mode\n" << std::endl;
         break;
   }
}

/****************************************/
/****************************************/

void CRealKheperaIVTurretGripperActuator::Lock(){
   LOG << "[GRIPPER] Real robot has gripped\n" << std::endl;
   m_eGrip = MODE_CLOSED;
}


void CRealKheperaIVTurretGripperActuator::Unlock(){
   LOG << "[GRIPPER] Real robot has unlocked gripper" << std::endl;
   m_eGrip = MODE_OPEN;
}


void CRealKheperaIVTurretGripperActuator::EnableCheckForObjectGrippedRoutine(){
   /**
    * TODO : Needs to use the parallel force sensor to check if a connection is properly made
    */
}


void CRealKheperaIVTurretGripperActuator::DisableCheckForObjectGrippedRoutine(){
   /**
    * TODO : Needs to use the parallel force sensor to check if a connection is properly made
    */
}
