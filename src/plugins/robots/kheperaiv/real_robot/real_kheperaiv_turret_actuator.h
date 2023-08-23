#ifndef REAL_KHEPERAIV_TURRET_ACTUATOR_H
#define REAL_KHEPERAIV_TURRET_ACTUATOR_H

#include <argos3/core/utility/math/angles.h>
#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_actuator.h>
// #include "cgripperI2C.h"

using namespace argos;

class CRealKheperaIVTurretActuator :
   public CCI_KheperaIVTurretActuator,
   public CRealKheperaIVDevice {

//    static const CRange<SInt32> SPEED_RANGE;
//    static const CRange<Real>   NORMALIZED_SPEED_RANGE;

public:

   CRealKheperaIVTurretActuator(knet_dev_t* pt_dspic);

   virtual ~CRealKheperaIVTurretActuator();

   virtual void Do(Real f_elapsed_time);

   /**
    * @brief Sets the turret rotation
    * Turret rotation is expressed in radians, positive values rotate the turret clockwise
    * when looking from above.
    * @param c_angle desired turret rotation
    * Takes in a c_angle between 0 to 2 pi
    */
   virtual void SetRotation(const CRadians& c_angle);

   /**
    * @brief Sets the turret control mode to active, and sets the target rotation to the given one
    * @param c_angle desired turret rotation
    * @see SetRotation
    */
   virtual void SetActiveWithRotation(const CRadians& c_angle);

   /**
    * @brief Sets the turret rotation speed
    * Turret rotation speed is expressed in motor pulses, positive values rotate the turret clockwise
    * when looking from above.
    * @param n_speed_pulses desired turret rotation speed - in motor frequency speed units
    */
   virtual void SetRotationSpeed(SInt32 n_speed);

   /**
    * @brief Sets the turret control mode
    * Modes are: angular position control, rotation speed control, passive mode, off
    * @param un_mode turret control mode, possible values are defined in CCI_KheperaIVTurretActuator
    */
   virtual void SetMode(ETurretModes e_mode);

private:
   ETurretModes m_eMode;
   unsigned short m_unEncoderCount;
   unsigned short m_unSpeed;
   };

#endif
