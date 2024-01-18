/**
 * @file <argos3-kheperaiv/src/plugins/robots/simulator/kheperaiv_gripper_entity.h>
 *
 * @author Chandler Garcia - <crgarcia@wpi.edu>
 */

#ifndef KHEPERAIV_GRIPPER_ENTITY_H
#define KHEPERAIV_GRIPPER_ENTITY_H

namespace argos {
   CKheperaIVGripperEntity
}

#include <argos3/plugins/simulator/entities/gripper_equipped_entity.h>

namespace argos {

   class CKheperaIVGripperEntity : public CGripperEquippedEntity {

   public:

   public:

      CKheperaIVGripperEntity(CComposableEntity* pc_parent);

      CKheperaIVGripperEntity(CComposableEntity* pc_parent,
                           const std::string& str_id);
      
      virtual void Init(TConfigurationNode& t_tree);
      virtual void Reset();
      virtual void Destroy();

      virtual void UpdateComponents();

      void SetExtension(Real f_extension);

      void SetAnchor1(CVector3 c_Anchor1);

      void SetAnchor2(CVector3 c_Anchor2);

   private:
   
      CVector3 m_cAnchor1;
      CVector3 m_cAnchor2;
      Real     m_fExtension;

   };

}

#endif
