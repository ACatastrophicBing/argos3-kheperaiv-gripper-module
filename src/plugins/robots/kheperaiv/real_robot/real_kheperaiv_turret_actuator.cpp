/**
 * @file <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_actuator.cpp>
 *
 * @author Chandler Garcia
 */

#include "real_kheperaiv_turret_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>
// #include "cgripperI2C.c"

  /****************************************/
  /****************************************/

  // const CRange<SInt32> CRealKheperaIVTurretActuator::SPEED_RANGE(-4,4);
  // const CRange<Real>   CRealKheperaIVTurretActuator::NORMALIZED_SPEED_RANGE(-1.0,1.0);

  CRealKheperaIVTurretActuator::CRealKheperaIVTurretActuator(knet_dev_t* pt_dspic) :
   CRealKheperaIVDevice(pt_dspic) {
  // CRealKheperaIVTurretActuator::CRealKheperaIVTurretActuator() {
    /* Turret does nada, and if its position was changed while off, we don't want it to instantly turn on */
    cgripper_Turret_Disable();
  }

  CRealKheperaIVTurretActuator::~CRealKheperaIVTurretActuator(){
    
  }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::SetActiveWithRotation(const CRadians& c_angle) {
    cgripper_Turret_Position_Mode();
    SetRotation(c_angle);
  }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::SetRotationSpeed(SInt32 speed) {
    cgripper_Turret_Speed_Mode();
    unsigned short tSpeed = (unsigned short) speed;
    cgripper_Turret_Set_Speed(tSpeed);
  }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::SetMode(ETurretModes e_mode){
    switch(e_mode){
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
        break;
      case MODE_POSITION_CONTROL:
        printf("Position turret mode\n");
        cgripper_Turret_Position_Mode();
        break;
      default:
        printf("Invalid turret mode\n");
        break;
    }
  }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::SetRotation(const CRadians& c_angle) {
    /*
     * Change radians into encoders
    */
      LOG << "[TURRET] Setting rotation to /" << c_angle << std::endl;
      unsigned short sEncoderCount = (unsigned short) (c_angle.GetValue() - CRadians:PI) / CRadians:PI * 44690;
      LOG << "[TURRET] The current encoder count send message is /" << sEncoderCount << std::endl;
      cgripper_Gripper_Set_Position(sEncoderCount);
   }

  /****************************************/
  /****************************************/

  void CRealKheperaIVTurretActuator::Do(Real f_elapsed_time) {    
    /* Do Nothing */
  }

