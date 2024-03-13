/**
 * @file <argos3-kheperaiv/src/plugins/robots/simulator/kheperaiv_entity.cpp>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "kheperaiv_entity.h"
#include "kheperaiv_measures.h"

#include "kheperaiv_gripper_entity.h" // This should be correct

namespace argos {

   /****************************************/
   /****************************************/

   CKheperaIVGripperEntity::CKheperaIVGripperEntity(CComposableEntity* pc_parent) :
      CGripperEquippedEntity(nullptr) {
      Reset();
      Disable();
   }

   /****************************************/
   /****************************************/
   
   CKheperaIVGripperEntity::CKheperaIVGripperEntity(CComposableEntity* pc_parent,
                                                  const std::string& str_id,
                                                  const CVector3& c_offset,
                                                  const CVector3& c_direction,
                                                  Real f_lock_threshold) :
      CGripperEquippedEntity(pc_parent, str_id, c_offset, c_direction, f_lock_threshold) {
      Disable();
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Init(TConfigurationNode& t_tree) {
      
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Reset() {
      CGripperEquippedEntity::Reset();
      // printf("Reseting the Gripper Entity\n");
      m_cForceVector = CVector2(0.0,0.0);
      m_fForceMag = 0;
      // printf("Gripper Entity Reset\n");
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Destroy() {
      printf("Destroying the Gripper Entity\n");
      m_cForceVector = CVector2(0.0,0.0);
      m_fForceMag = 0;
      printf("Gripper Entity Destroyed\n");
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Update() {
      
      // All updating is done manually through the Set functions
   }

   void CKheperaIVGripperEntity::SetForceMag(Real f_ForceMag){
      m_fForceMag = f_ForceMag;
   }

   void CKheperaIVGripperEntity::SetForceSensor(CVector2 c_ForceVector){
      m_cForceVector = c_ForceVector;
   }

   CVector2 CKheperaIVGripperEntity::GetForceSensor(){
      return m_cForceVector * m_fForceMag;
   }

   Real CKheperaIVGripperEntity::GetForceMag(){
      return m_fForceMag;
   }

   /****************************************/
   /****************************************/

   REGISTER_STANDARD_SPACE_OPERATIONS_ON_ENTITY(CKheperaIVGripperEntity);

   /****************************************/
   /****************************************/

}
