/**
 * @file <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_actuator.cpp>
 *
 * @author Chandler Garcia
 */

#include "real_kheperaiv_turret_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>


  /****************************************/
  /****************************************/

  // const CRange<SInt32> CRealKheperaIVTurretActuator::SPEED_RANGE(-4,4);
  // const CRange<Real>   CRealKheperaIVTurretActuator::NORMALIZED_SPEED_RANGE(-1.0,1.0);

  CRealKheperaIVTurretActuator::CRealKheperaIVTurretActuator(knet_dev_t* pt_dspic) :
   CRealKheperaIVDevice(pt_dspic) {
    /* Turret does nada, and if its position was changed while off, we don't want it to instantly turn on */
    cgripper_Turret_Disable();
  }

  CRealKheperaIVTurretActuator::~CRealKheperaIVTurretActuator(){
    
  }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::SetActiveWithRotation(const CRadians& c_angle) {
    m_eMode = MODE_PASSIVE;
    SetRotation(c_angle);
  }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::SetRotationSpeed(SInt32 n_speed) {
    m_unSpeed = (unsigned short) n_speed;
  }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::SetMode(ETurretModes e_mode){
    m_eMode = e_mode;
  }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::SetRotation(const CRadians& c_angle) {
    /*
     * Change radians into encoders
    */
      LOG << "[TURRET] Setting rotation to /" << c_angle << std::endl;
      if(c_angle.GetValue() < 0){
        m_unEncoderCount = (unsigned short) ((2 * CRadians::PI.GetValue() + c_angle.GetValue()) / CRadians::PI.GetValue() * 22345) + 22345;
      }
        m_unEncoderCount = (unsigned short) (c_angle.GetValue()) / CRadians::PI.GetValue() * 22345;
      LOG << "[TURRET] The current encoder count send message is /" << m_unEncoderCount << std::endl;
   }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::Do(Real f_elapsed_time) {   
      switch(m_eMode){
      case MODE_OFF:
        cgripper_Turret_Disable();
        printf("Turret off\n");
        break;
      case MODE_PASSIVE:
        printf("Passive turret mode\n");
        cgripper_Turret_Disable();
        break;
      case MODE_SPEED_CONTROL:
        printf("Speed turret mode\n");
        cgripper_Turret_Speed_Mode();
        cgripper_Turret_Set_Speed(m_unSpeed);
        break;
      case MODE_POSITION_CONTROL:
        printf("Position turret mode\n");
        cgripper_Gripper_Set_Position(m_unEncoderCount); 
        cgripper_Turret_Position_Mode();
        break;
      default:
        printf("Invalid turret mode\n");
        break;
    }
  }

