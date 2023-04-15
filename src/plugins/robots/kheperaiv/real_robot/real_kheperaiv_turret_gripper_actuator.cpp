#include "real_kheperaiv_turret_gripper_actuator.h"

/****************************************/
/****************************************/

CRealKheperaIVGripperTurretActuator::CRealKheperaIVGripperTurretActuator(){
   /* The gripper once on is automatically initialized */
}
   
/****************************************/
/****************************************/

CRealKheperaIVGripperTurretActuator::~CRealKheperaIVGripperTurretActuator() {
}
   
/****************************************/
/****************************************/

void CRealKheperaIVGripperTurretActuator::Do(Real f_elapsed_time) {
}

/****************************************/
/****************************************/

void CRealKheperaIVGripperTurretActuator::Lock(){
   printf("Real robot has gripped\n");
   cgripper_Close_Gripper();
}


void CRealKheperaIVGripperTurretActuator::Unlock(){
   cgripper_Open_Gripper();
}
