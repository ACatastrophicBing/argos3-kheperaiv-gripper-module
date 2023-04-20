#ifndef REAL_KHEPERAIV_TURRET_ENCODER_SENSOR_H
#define REAL_KHEPERAIV_TURRET_ENCODER_SENSOR_H

#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_encoder_sensor.h>
#include <argos3/core/utility/math/vector2.h>
#include "cgripperI2C.h"

using namespace argos;

class CRealKheperaIVTurretEncoderSensor :
   public CCI_KheperaIVTurretEncoderSensor,
   public CRealKheperaIVDevice {

public:

   CRealKheperaIVTurretEncoderSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealKheperaIVTurretEncoderSensor();

   /**
    * @brief Get the current turret's rotation
    * Will return as a value between 0 to 2 pi depending on the
    * encoder counts read
    * @return const CRadians& 
    */
   virtual const CRadians& GetRotation();

   virtual void Do(Real f_elapsed_time);

private:

   CRadians m_cRotation;

   unsigned short m_nTurretEncoder;
   Real m_fTurretEncoderDegrees;

};

#endif // REAL_KHEPERAIV_ENCODER_SENSOR_H
