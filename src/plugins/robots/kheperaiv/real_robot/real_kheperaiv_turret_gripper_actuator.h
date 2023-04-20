#ifndef REAL_KHEPERAIV_TURRET_GRIPPER_ACTUATOR_H
#define REAL_KHEPERAIV_TURRET_GRIPPER_ACTUATOR_H

#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_gripper_actuator.h>
#include <argos3/core/utility/math/vector2.h>
#include "cgripperI2C.h"

using namespace argos;

class CRealKheperaIVTurretGripperActuator :
   public CCI_KheperaIVGripperActuator,
   public CRealKheperaIVDevice {

public:

   CRealKheperaIVTurretGripperActuator(knet_dev_t* pt_dspic);
   
   virtual ~CRealKheperaIVTurretGripperActuator();

   virtual void Do(Real f_elapsed_time);

   /**
    * Lock the gripper
    */
   virtual void Lock();

   /**
    * Unlock the gripper
    */
   virtual void Unlock();

   /**
    * Enables the ASEBA routine that checks for a gripped object each time the gripper is opened
    */
   virtual void EnableCheckForObjectGrippedRoutine();

   /**
    * Disables the ASEBA routine that checks for a gripped object each time the gripper is opened
    */
   virtual void DisableCheckForObjectGrippedRoutine();

   
private:

   

};

#endif
