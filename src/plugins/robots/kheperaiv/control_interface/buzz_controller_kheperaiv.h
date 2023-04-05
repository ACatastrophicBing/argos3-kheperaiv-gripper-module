#ifndef BUZZ_CONTROLLER_KHEPERAIV_H
#define BUZZ_CONTROLLER_KHEPERAIV_H

#include <buzz/argos/buzz_controller.h>
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
#include <argos3/plugins/robots/generic/control_interface/ci_leds_actuator.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_ground_sensor.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_proximity_sensor.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_light_sensor.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_ultrasound_sensor.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_lidar_sensor.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_gripper_actuator.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_actuator.h>


using namespace argos;

class CBuzzControllerKheperaIV : public CBuzzController {

public:

   struct SWheelTurningParams {
      /*
       * The turning mechanism.
       * The robot can be in three different turning states.
       */
      enum ETurningMechanism
      {
         NO_TURN = 0, // go straight
         SOFT_TURN,   // both wheels are turning forwards, but at different speeds
         HARD_TURN    // wheels are turning with opposite speeds
      } TurningMechanism;
      /*
       * Angular thresholds to change turning state.
       */
      CRadians HardTurnOnAngleThreshold;
      CRadians SoftTurnOnAngleThreshold;
      CRadians NoTurnAngleThreshold;
      /* Maximum wheel speed */
      Real MaxSpeed;

      SWheelTurningParams();
      void Init(TConfigurationNode& t_tree);
   };

public:

   CBuzzControllerKheperaIV();
   virtual ~CBuzzControllerKheperaIV();

   virtual void Init(TConfigurationNode& t_node);

   virtual void UpdateSensors();

   void SetWheels(Real f_left_speed, Real f_right_speed);
   void GetWheels();
   void SetWheelSpeedsFromVector(const CVector2& c_heading);
   void SetLEDs(const CColor& c_color);
   void GripperLock();
   void GripperUnlock();
   void TurretEnable();
   void TurretDisable();
   void TurretSet(Real f_rotation);

private:

   virtual buzzvm_state RegisterFunctions();

protected:

   /* Pointer to the differential steering actuator */
   CCI_DifferentialSteeringActuator* m_pcWheels;
   /* Pointer to the LEDs actuator */
   CCI_LEDsActuator* m_pcLEDs;
   /* Pointer to the foot-bot gripper actuator */
   CCI_KheperaIVGripperActuator* m_pcGripper;
   /* Pointer to the foot-bot turret actuator */
   CCI_KheperaIVTurretActuator* m_pcTurret;
   /* Pointer to the ground sensor */
   CCI_KheperaIVGroundSensor* m_pcGround;
   /* Pointer to the proximity sensor */
   CCI_KheperaIVProximitySensor* m_pcProximity;
   /* Pointer to the light sensor */
   CCI_KheperaIVLightSensor* m_pcLight;
   /* Pointer to the ultrasound sensor */
   CCI_KheperaIVUltrasoundSensor* m_pcUltrasound;
   /* Pointer to the lidar sensor */
   CCI_KheperaIVLIDARSensor* m_pcLIDAR;

   /* The turning parameters. */
   SWheelTurningParams m_sWheelTurningParams;

};

#endif
