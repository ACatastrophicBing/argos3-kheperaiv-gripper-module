#include "real_kheperaiv_turret_gripper_actuator.h"

/****************************************/
/****************************************/

CRealKheperaIVTurretGripperActuator::CRealKheperaIVTurretGripperActuator(){
   /* The gripper once on is automatically initialized */
}
   
/****************************************/
/****************************************/

CRealKheperaIVTurretGripperActuator::~CRealKheperaIVTurretGripperActuator() {
}
   
/****************************************/
/****************************************/

void CRealKheperaIVTurretGripperActuator::Do(Real f_elapsed_time) {
}

/****************************************/
/****************************************/

void CRealKheperaIVTurretGripperActuator::Lock(){
   printf("Real robot has gripped\n");
   cgripper_Close_Gripper();
}


void CRealKheperaIVTurretGripperActuator::Unlock(){
   cgripper_Open_Gripper();
}
