/**
 * @file <argos3-kheperaiv/src/plugins/robots/simulator/kheperaiv_gripper_entity.h>
 *
 * @author Chandler Garcia - <crgarcia@wpi.edu>
 */

#ifndef KHEPERAIV_GRIPPER_ENTITY_H
#define KHEPERAIV_GRIPPER_ENTITY_H

namespace argos {
   class CKheperaIVGripperEntity;
}

#include <argos3/plugins/simulator/entities/gripper_equipped_entity.h>

namespace argos {

   class CKheperaIVGripperEntity : public CGripperEquippedEntity {

   public:

      CKheperaIVGripperEntity(CComposableEntity* pc_parent);

      CKheperaIVGripperEntity(CComposableEntity* pc_parent,
                             const std::string& str_id,
                             const CVector3& c_offset,
                             const CVector3& c_direction,
                             Real f_lock_threshold = 0.5f);
      
      virtual void Init(TConfigurationNode& t_tree);

      virtual void Reset();

      virtual void Destroy();

      virtual void Update();

      void SetExtension(Real f_extension);

      void SetAnchor1(CVector3 c_Anchor1);

      void SetAnchor2(CVector3 c_Anchor2);

      void SetOriginAnchorRob(CVector3 c_AnchorOrigin);

      void SetForceSensor(CVector3 c_Anchor);

      CVector3 GetAnchor1();

      CVector3 GetAnchor2();

      CVector3 GetOriginAnchorRob();

      CVector3 GetForceSensor();

      Real GetExtension();

   private:
   
      CVector3 m_cAnchor1;
      CVector3 m_cAnchor2;
      CVector3 m_cOriginAnchor;
      CVector3 m_cForceVector;
      Real     m_fExtension;

   };

}

#endif
