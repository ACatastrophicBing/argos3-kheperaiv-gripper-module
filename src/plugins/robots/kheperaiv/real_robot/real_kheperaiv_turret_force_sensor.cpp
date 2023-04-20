#include "real_kheperaiv_turret_force_sensor.h"
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

Real CRealKheperaIVTurretForceSensor::GetParallelForce() {
   return m_rParallel_Force;
}

Real CRealKheperaIVTurretForceSensor::GetPerpendicularForce() {
   return m_rPerpendicular_Force;
}

/****************************************/
/****************************************/

void CRealKheperaIVTurretForceSensor::Do(Real f_elapsed_time) {
   /*
    * Reads the perpendicular and parallel force sensors
    */
   m_rParallel_Force = (Real)(cgripper_ForceSensor_Get_Parallel_Force() - 2048) * 2.92496;
   m_rPerpendicular_Force = (Real)(cgripper_ForceSensor_Get_Perpendicular_Force() - 2048) * 2.92496;
}

/****************************************/
/****************************************/
