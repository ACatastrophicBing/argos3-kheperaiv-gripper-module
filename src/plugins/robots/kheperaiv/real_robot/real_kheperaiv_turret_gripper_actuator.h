#ifndef REAL_KHEPERAIV_TURRET_GRIPPER_ACTUATOR_H
#define REAL_KHEPERAIV_TURRET_GRIPPER_ACTUATOR_H

#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/plugins/robots/generic/control_interface/ci_gripper_actuator.h>
#include <argos3/core/utility/math/vector2.h>
#include "cgripperI2C.h"

using namespace argos;

class CRealKheperaIVTurretGripperActuator :
   public CCI_GripperActuator,
   public CRealKheperaIVDevice {

public:

   CRealKheperaIVTurretGripperActuator();
   
   virtual ~CRealKheperaIVTurretGripperActuator();

   virtual void Do(Real f_elapsed_time);

   virtual void Lock();

   virtual void Unlock();
   
private:

   

};

#endif
