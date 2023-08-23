#include "real_kheperaiv_turret_gripper_actuator.h"


/****************************************/
/****************************************/

CRealKheperaIVTurretGripperActuator::CRealKheperaIVTurretGripperActuator(knet_dev_t* pt_dspic) :
   CRealKheperaIVDevice(pt_dspic) {
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
         printf("[GRIPPER] Gripper Open\n");
         break;
         case MODE_CLOSED:
         printf("[GRIPPER] Gripper Closed\n");
         cgripper_Close_Gripper();
         break;
         default:
         printf("Invalid gripper mode\n");
         break;
   }
}

/****************************************/
/****************************************/

void CRealKheperaIVTurretGripperActuator::Lock(){
   printf("[GRIPPER] Real robot has gripped\n");
   m_eGrip = MODE_CLOSED;
}


void CRealKheperaIVTurretGripperActuator::Unlock(){
   printf("[GRIPPER] Real robot has unlocked gripper");
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
