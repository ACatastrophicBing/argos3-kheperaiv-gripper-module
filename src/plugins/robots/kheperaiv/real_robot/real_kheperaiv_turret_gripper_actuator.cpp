#include "real_kheperaiv_turret_gripper_actuator.h"
// #include "cgripperI2C.c"

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
