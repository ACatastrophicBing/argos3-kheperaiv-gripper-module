#ifndef REAL_KHEPERAIV_TURRET_ENCODER_SENSOR_H
#define REAL_KHEPERAIV_TURRET_ENCODER_SENSOR_H

#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_encoder_sensor.h>
#include <argos3/core/utility/math/vector2.h>

using namespace argos;

class CRealKheperaIVTurretEncoderSensor :
   public CCI_Sensor,
   public CRealKheperaIVDevice {

public:

   CRealKheperaIVTurretEncoderSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealKheperaIVTurretEncoderSensor();

   // virtual const CRadians& GetRotation() const;

   virtual void Do(Real f_elapsed_time);

private:

   CRadians m_cRotation;

   unsigned short m_nTurretEncoder;
   Real m_fTurretEncoderDegrees;

};

#endif // REAL_KHEPERAIV_ENCODER_SENSOR_H
