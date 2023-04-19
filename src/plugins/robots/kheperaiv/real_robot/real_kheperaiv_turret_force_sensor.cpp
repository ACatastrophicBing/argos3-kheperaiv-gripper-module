#include "real_kheperaiv_turret_force_sensor.h"
#include "cgripperI2C.h"
/****************************************/
/****************************************/

CRealKheperaIVTurretForceSensor::CRealKheperaIVTurretForceSensor(knet_dev_t* pt_dspic) :
   CRealKheperaIVDevice(pt_dspic) {
   m_rParallel_Force = 0;
   m_rPerpendicular_Force = 0;
}

/****************************************/
/****************************************/

CRealKheperaIVTurretForceSensor::~CRealKheperaIVTurretForceSensor() {
}

/****************************************/
/****************************************/

void CRealKheperaIVTurretForceSensor::Do(Real f_elapsed_time) {
   /*
    * Reads the perpendicular and parallel force sensors
    */
   m_rParallel_Force = cgripper_ForceSensor_Get_Parallel_Force();
   m_rPerpendicular_Force = cgripper_ForceSensor_Get_Perpendicular_Force();
}

/****************************************/
/****************************************/
