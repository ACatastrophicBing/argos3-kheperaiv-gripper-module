#ifndef REAL_KHEPERAIV_TURRET_FORCE_SENSOR_H
#define REAL_KHEPERAIV_TURRET_FORCE_SENSOR_H

#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/math/vector2.h>
// #include "cgripperI2C.h"

using namespace argos;

class CRealKheperaIVTurretForceSensor :
   public CCI_Sensor,
   public CRealKheperaIVDevice {

public:

   CRealKheperaIVTurretForceSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealKheperaIVTurretForceSensor();

   virtual void Do(Real f_elapsed_time);

   virtual Real GetParallelForce();

   virtual Real GetPerpendicularForce();

private:
   /*
    * m_rParallel_Force holds the most recent force measurment parallel to the gripper,
    * m_rParallel_Force holds the most recent force measurment perpendicular to the gripper
    * Both are in grams
   */
   Real m_rParallel_Force;
   Real m_rPerpendicular_Force;

};

#endif // REAL_KHEPERAIV_ENCODER_SENSOR_H
