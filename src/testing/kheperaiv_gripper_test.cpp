/* Include the controller definition */
#include "kheperaiv_gripper_test.h"
/* Function definitions for XML parsing */
#include <argos3/core/utility/configuration/argos_configuration.h>
/* 2D vector definition */
#include <argos3/core/utility/math/vector2.h>
/* Logging */
#include <argos3/core/utility/logging/argos_log.h>

/****************************************/
/****************************************/

CKheperaIVGripping::CKheperaIVGripping() :
   m_pcWheels(NULL),
   m_pcProximity(NULL),
   m_cAlpha(10.0f),
   m_fDelta(0.5f),
   m_fWheelVelocity(2.5f),
   m_cGoStraightAngleRange(-ToRadians(m_cAlpha),
                           ToRadians(m_cAlpha)) {}

/****************************************/
/****************************************/

void CKheperaIVGripping::Init(TConfigurationNode& t_node) {
   /*
    * Get sensor/actuator handles
    *
    * The passed string (ex. "differential_steering") corresponds to the
    * XML tag of the device whose handle we want to have. For a list of
    * allowed values, type at the command prompt:
    *
    * $ argos3 -q actuators
    *
    * to have a list of all the possible actuators, or
    *
    * $ argos3 -q sensors
    *
    * to have a list of all the possible sensors.
    *
    * NOTE: ARGoS creates and initializes actuators and sensors
    * internally, on the basis of the lists provided the configuration
    * file at the <controllers><kheperaiv_diffusion><actuators> and
    * <controllers><kheperaiv_diffusion><sensors> sections. If you forgot to
    * list a device in the XML and then you request it here, an error
    * occurs.
    */
   m_pcWheels           = GetActuator<CCI_DifferentialSteeringActuator>("differential_steering");
   m_pcEncoder          = GetSensor  <CCI_DifferentialSteeringSensor  >("differential_steering");
   m_pcProximity        = GetSensor  <CCI_KheperaIVProximitySensor    >("kheperaiv_proximity"  );
   m_pcUltrasound       = GetSensor  <CCI_KheperaIVUltrasoundSensor   >("kheperaiv_ultrasound" );
   m_pcGripper          = GetActuator<CCI_KheperaIVGripperActuator    >("kheperaiv_gripper");
   m_pcTurret           = GetActuator<CCI_KheperaIVTurretActuator     >("kheperaiv_turret");
   m_pcTurretEncoder    = GetSensor  <CCI_KheperaIVTurretEncoderSensor>("kheperaiv_turret");

   /*
    * Parse the configuration file
    *
    * The user defines this part. Here, the algorithm accepts three
    * parameters and it's nice to put them in the config file so we don't
    * have to recompile if we want to try other settings.
    */
   GetNodeAttributeOrDefault(t_node, "alpha", m_cAlpha, m_cAlpha);
   m_cGoStraightAngleRange.Set(-ToRadians(m_cAlpha), ToRadians(m_cAlpha));
   GetNodeAttributeOrDefault(t_node, "delta", m_fDelta, m_fDelta);
   GetNodeAttributeOrDefault(t_node, "velocity", m_fWheelVelocity, m_fWheelVelocity);

   m_pcTurret->SetMode(m_pcTurret->MODE_POSITION_CONTROL);

   counter = 0;

   RLOG << "Initialized" << std::endl;
}

/****************************************/
/****************************************/

void CKheperaIVGripping::ControlStep() {
   
   /* Print our turret values*/
   RLOG << "Turret values: "
   << "Heading=" << m_pcTurretEncoder->GetRotation().GetValue()
   << std::endl;
   
   if(counter < 50){
      m_pcTurret->SetRotation(CRadians::PI);
      m_pcGripper->Lock();
      RLOG << "Test: "
   << "turning" 
   << std::endl;
   } else{
      m_pcTurret->SetRotation(CRadians::ZERO);
      m_pcGripper->Unlock();
      RLOG << "Test: "
   << "not turning=" << counter
   << std::endl;
   }
   counter = counter +1; // Literally bare bones keep it as simple as possible
   m_pcWheels->SetLinearVelocity(10,10);

   RLOG << "Running" << std::endl;
}

/****************************************/
/****************************************/

void CKheperaIVGripping::Destroy(){
   m_pcTurret->SetMode(m_pcTurret->MODE_OFF);
   m_pcWheels->SetLinearVelocity(0,0);
}

/****************************************/
/****************************************/

/*
 * This statement notifies ARGoS of the existence of the controller.
 * It binds the class passed as first argument to the string passed as
 * second argument.
 * The string is then usable in the configuration file to refer to this
 * controller.
 * When ARGoS reads that string in the configuration file, it knows which
 * controller class to instantiate.
 * See also the configuration files for an example of how this is used.
 */
REGISTER_CONTROLLER(CKheperaIVGripping, "kheperaiv_gripper_test_controller")
