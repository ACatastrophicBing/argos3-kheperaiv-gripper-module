#ifndef REAL_KHEPERAIV_TURRET_ENCODER_SENSOR_H
#define REAL_KHEPERAIV_TURRET_ENCODER_SENSOR_H

#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_encoder_sensor.h>
#include <argos3/core/utility/math/vector2.h>

using namespace argos;

class CRealKheperaIVTurretForceSensor :
   public CCI_Sensor,
   public CRealKheperaIVDevice {

public:

   CRealKheperaIVTurretForceSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealKheperaIVTurretForceSensor();

   virtual void Do(Real f_elapsed_time);

private:
   /*
    * m_rParallel_Force holds the most recent force measurment parallel to the gripper,
    * m_rParallel_Force holds the most recent force measurment perpendicular to the gripper
   */
   Real m_rParallel_Force;
   Real m_rPerpendicular_Force;

};

#endif // REAL_KHEPERAIV_ENCODER_SENSOR_H
