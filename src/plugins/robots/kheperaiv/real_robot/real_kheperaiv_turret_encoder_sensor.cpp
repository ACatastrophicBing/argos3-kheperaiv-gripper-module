#include "real_kheperaiv_turret_encoder_sensor.h"
/****************************************/
/****************************************/

CRealKheperaIVTurretEncoderSensor::CRealKheperaIVTurretEncoderSensor(knet_dev_t* pt_dspic) :
   CRealKheperaIVDevice(pt_dspic) {
   m_nTurretEncoder = cgripper_Turret_Get_Position();
   m_fTurretEncoderDegrees = (float) m_nTurretEncoder / 44690.0 * 360.0;
   m_cRotation = CRadians(m_fTurretEncoderDegrees);  
}

/****************************************/
/****************************************/

CRealKheperaIVTurretEncoderSensor::~CRealKheperaIVTurretEncoderSensor() {
}

/****************************************/
/****************************************/

const CRadians& CRealKheperaIVTurretEncoderSensor::GetRotation() {
      return m_cRotation;
}

/****************************************/
/****************************************/

void CRealKheperaIVTurretEncoderSensor::Do(Real f_elapsed_time) {
   /*
    * The encoder function call to the turret gripper module gives us the prediced rotation of the gripper in degrees
    * m_nTurretEncoder is in encoder tics 0 to 44690,
    * m_fTurretEncoderDegrees is in degrees, 0 to 359.99
    */
   m_nTurretEncoder = cgripper_Turret_Get_Position();
   m_fTurretEncoderDegrees = (float) m_nTurretEncoder / 44690.0 * 360.0;
   m_cRotation = CRadians(m_fTurretEncoderDegrees);
}

/****************************************/
/****************************************/
