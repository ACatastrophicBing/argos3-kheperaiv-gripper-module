/**
 * @file <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_gripper_actuator.h>
 *
 * @brief This file provides the definition of the gripper actuator.

 * This file provides the definition of the gripper actuator. It allows
 * to set the gripper aperture in the range [-pi/2:pi/2]. The gripper
 * can be locked in two directions: positive and negative. In the negative
 * direction the 2 side pins of the gripper move upwards and the middle pin
 * downwards.
 *
 * @author Chandler Garcia
 */

#ifndef CCI_KHEPERAIV_GRIPPER_ACTUATOR_H
#define CCI_KHEPERAIV_GRIPPER_ACTUATOR_H

/* To avoid dependency problems when including */
namespace argos {
   class CCI_KheperaIVGripperActuator;
}

#include <argos3/core/control_interface/ci_actuator.h>
#include <argos3/core/utility/math/angles.h>

namespace argos {

   class CCI_KheperaIVGripperActuator : public CCI_Actuator {

   public:

      enum EGripModes {
      MODE_OPEN = 0,
      MODE_CLOSED = 1
      };

      /* Useful gripper aperture values */
      static CRadians UNLOCKED;
      static CRadians LOCKED_POSITIVE;
      static CRadians LOCKED_NEGATIVE;

   public:

      /**
       * Class constructor.
       */
      CCI_KheperaIVGripperActuator();

      /**
       * Class destructor.
       */
      virtual ~CCI_KheperaIVGripperActuator() {}

      /**
       * Sets the gripper aperture.
       * @param c_aperture The desired aperture.
       */
      void SetAperture(const CRadians& c_aperture);

      /**
       * Enables the ASEBA routine that checks for a gripped object each time the gripper is opened
       */
      virtual void EnableCheckForObjectGrippedRoutine() = 0;

      /**
       * Disables the ASEBA routine that checks for a gripped object each time the gripper is opened
       */
      virtual void DisableCheckForObjectGrippedRoutine() = 0;

      /**
       * Sets gripper aperture to lock, positive direction.
       */
      virtual void Lock();

      /**
       * Unlock gripper: objects are released.
       */
      virtual void Unlock();

      /**
       * @brief Returns if the gripper is locked or unlocked based off
       * messages sent to it, not based on the simulation considering it locked
       * @return true is locked
       * @return false is not locked
       */
      virtual bool GetIsLocked();

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);
#endif

   protected:

      CRadians m_cAperture;

   };

}

#endif
