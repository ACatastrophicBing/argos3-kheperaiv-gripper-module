/**
 * @file <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_gripper_actuator.cpp>
 *
 * @author Chandler Garcia & Yasmine Aoua
 */

#include "ci_kheperaiv_gripper_force_sensor.h"

#ifdef ARGOS_WITH_LUA
#include <argos3/core/wrappers/lua/lua_utility.h>
#endif

namespace argos {

  /****************************************/
  /****************************************/

  /****************************************/
  /****************************************/

  CCI_KheperaIVGripperForceSensor::CCI_KheperaIVGripperForceSensor() :
    m_cForceVector() {

    }

  /****************************************/
  /****************************************/

  const CVector2& CCI_KheperaIVGripperForceSensor::GetReadings() const {
    return m_cForceVector;
  }

  /****************************************/
  /****************************************/

#ifdef ARGOS_WITH_LUA
   void CCI_KheperaIVGripperForceSensor::CreateLuaState(lua_State* pt_lua_state) {
      // 
   }
#endif

   /****************************************/
   /****************************************/

#ifdef ARGOS_WITH_LUA
   void CCI_KheperaIVGripperForceSensor::ReadingsToLuaState(lua_State* pt_lua_state) {
      // 
   }
#endif

  /****************************************/
  /****************************************/

}
