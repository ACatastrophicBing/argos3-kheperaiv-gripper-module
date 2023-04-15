#ifndef REAL_KHEPERAIV_TURRET_ENCODER_SENSOR_H
#define REAL_KHEPERAIV_TURRET_ENCODER_SENSOR_H

#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/core/utility/math/vector2.h>

using namespace argos;

class CRealKheperaIVTurretEncoderSensor :
   public CRealKheperaIVDevice {

public:

   CRealKheperaIVTurretEncoderSensor();
   
   virtual ~CRealKheperaIVTurretEncoderSensor();

   const CRadians& GetRotation() const;

   virtual void Do();

private:

   CRadians m_cRotation;

   unsigned short m_nTurretEncoder;
   float m_fTurretEncoderDegrees;

};

#endif // REAL_KHEPERAIV_ENCODER_SENSOR_H
