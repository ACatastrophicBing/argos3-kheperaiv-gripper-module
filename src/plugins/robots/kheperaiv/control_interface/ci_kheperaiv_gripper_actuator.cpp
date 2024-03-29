/**
 * @file <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_gripper_actuator.cpp>
 *
 * @author Chandler Garcia & Yasmine Aoua
 */

#include "ci_kheperaiv_gripper_actuator.h"

#ifdef ARGOS_WITH_LUA
#include <argos3/core/wrappers/lua/lua_utility.h>
#endif

namespace argos {

  /****************************************/
  /****************************************/
   
  CRadians CCI_KheperaIVGripperActuator::LOCKED_NEGATIVE(-ARGOS_PI * 0.6f);
  CRadians CCI_KheperaIVGripperActuator::LOCKED_POSITIVE(ARGOS_PI * 0.6f);
  CRadians CCI_KheperaIVGripperActuator::UNLOCKED(0.0f);

  CRange<CRadians> APERTURE_RANGE(CCI_KheperaIVGripperActuator::LOCKED_NEGATIVE,
				  CCI_KheperaIVGripperActuator::LOCKED_POSITIVE);
   
  /****************************************/
  /****************************************/

#ifdef ARGOS_WITH_LUA
  /*
   * The stack must have no values
   */
  int LuaGripperLock(lua_State* pt_lua_state) {
    /* Get wheel speed from stack */
    if(lua_gettop(pt_lua_state) != 0) {
      return luaL_error(pt_lua_state, "robot.gripper.lock() expects no arguments");
    }
    /* Perform action */
    CLuaUtility::GetDeviceInstance<CCI_KheperaIVGripperActuator>(pt_lua_state, "gripper")->Lock();
    return 0;
  }

  /*
   * The stack must have no values
   */
  int LuaGripperUnlock(lua_State* pt_lua_state) {
    /* Get wheel speed from stack */
    if(lua_gettop(pt_lua_state) != 0) {
      return luaL_error(pt_lua_state, "robot.gripper.unlock() expects no arguments");
    }
    /* Perform action */
    CLuaUtility::GetDeviceInstance<CCI_KheperaIVGripperActuator>(pt_lua_state, "gripper")->Unlock();
    return 0;
  }
#endif

  /****************************************/
  /****************************************/

  CCI_KheperaIVGripperActuator::CCI_KheperaIVGripperActuator() :
    m_cAperture(UNLOCKED) {}

  /****************************************/
  /****************************************/

  void CCI_KheperaIVGripperActuator::SetAperture(const CRadians& c_aperture) {
    m_cAperture = c_aperture;
    m_cAperture.SignedNormalize();
    APERTURE_RANGE.TruncValue(m_cAperture);
    // LOG << "Setting the gripper aperture to " << c_aperture << std::endl;
  }

  /****************************************/
  /****************************************/

  void CCI_KheperaIVGripperActuator::Lock() {
    // printf("Gripper Should have locked\n");
    SetAperture(LOCKED_POSITIVE);
  }

  /****************************************/
  /****************************************/

  void CCI_KheperaIVGripperActuator::Unlock() {
    SetAperture(UNLOCKED);
  }

  /****************************************/
  /****************************************/

  bool CCI_KheperaIVGripperActuator::GetIsLocked() {
    return (m_cAperture.GetValue() > 1.0);
  }  

  /****************************************/
  /****************************************/

#ifdef ARGOS_WITH_LUA
  void CCI_KheperaIVGripperActuator::CreateLuaState(lua_State* pt_lua_state) {
    CLuaUtility::OpenRobotStateTable (pt_lua_state, "gripper"                               );
    CLuaUtility::AddToTable          (pt_lua_state, "_instance",     this                   );
    CLuaUtility::AddToTable          (pt_lua_state, "lock", &LuaGripperLock);
    CLuaUtility::AddToTable          (pt_lua_state, "unlock",        &LuaGripperUnlock      );
    CLuaUtility::CloseRobotStateTable(pt_lua_state                                          );
  }
#endif

  /****************************************/
  /****************************************/

}
