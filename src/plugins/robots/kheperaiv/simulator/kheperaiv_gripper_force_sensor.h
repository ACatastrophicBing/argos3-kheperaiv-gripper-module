/**
 * @file <argos3/plugins/robots/kheperaiv/simulator/kheperaiv__ground_rotzonly_sensor.h>
 *
 * @author Chandler Garcia - <crgarcia@wpi.edu>
 */

#ifndef KHEPERAIV_GRIPPER_FORCE_SENSOR_H
#define KHEPERAIV_GRIPPER_FORCE_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CKheperaIVGripperForceSensor;
}

#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_gripper_force_sensor.h>
#include <argos3/core/simulator/sensor.h>
#include <argos3/plugins/simulator/entities/gripper_equipped_entity.h>


namespace argos {

   class CKheperaIVGripperForceSensor : public CSimulatedSensor,
                                          public CCI_KheperaIVGripperForceSensor {

   public:

      CKheperaIVGripperForceSensor();

      virtual ~CKheperaIVGripperForceSensor() {}

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();
      virtual void Reset();

   private:
      CGripperEquippedEntity* m_pcGripperEquippedEntity;
      Real m_fExtension;
      
   };

}

#endif
