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

#ifndef CCI_KHEPERAIV_GRIPPER_FORCE_SENSOR_H
#define CCI_KHEPERAIV_GRIPPER_FORCE_SENSOR_H

/* To avoid dependency problems when including */
namespace argos {
   class CCI_KheperaIVGripperForceSensor;
}

#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/math/vector2.h>
#include <vector>

namespace argos {

   class CCI_KheperaIVGripperForceSensor : public CCI_Sensor {

   public:

      /**
       * Class constructor.
       */
      CCI_KheperaIVGripperForceSensor();

      /**
       * Class destructor.
       */
      virtual ~CCI_KheperaIVGripperForceSensor() {}

      const CVector2& GetReadings() const;

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);
#endif

   protected:

      Real m_fPerpendicularForce;
      Real m_fParallelForce;
      CVector2 m_cForceVector;
   };

}

#endif
