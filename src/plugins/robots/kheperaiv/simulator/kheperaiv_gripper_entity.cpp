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
      m_fExtension = 0.0;
      m_cAnchor1 = CVector3::ZERO;
      m_cAnchor2 = CVector3::ZERO;
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Destroy() {
      m_fExtension = 0.0;
      m_cAnchor1 = CVector3::ZERO;
      m_cAnchor2 = CVector3::ZERO;
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Update() {
      
      // All updating is done manually through the Set functions
   }

   void CKheperaIVGripperEntity::SetExtension(Real f_extension){
      m_fExtension = f_extension;
   }

   void CKheperaIVGripperEntity::SetAnchor1(CVector3 c_Anchor1){
      m_cAnchor1 = c_Anchor1;
   }

   void CKheperaIVGripperEntity::SetAnchor2(CVector3 c_Anchor2){
      m_cAnchor2 = c_Anchor2;
   }

   void CKheperaIVGripperEntity::SetOriginAnchorRob(CVector3 c_AnchorOrigin){
      m_cOriginAnchor = c_AnchorOrigin;
   }

   void CKheperaIVGripperEntity::SetForceSensor(CVector3 c_Anchor){
      m_cForceVector = c_Anchor;
   }

   CVector3 CKheperaIVGripperEntity::GetAnchor1(){
      return m_cAnchor1;
   }

   CVector3 CKheperaIVGripperEntity::GetAnchor2(){
      return m_cAnchor2;
   }

   CVector3 CKheperaIVGripperEntity::GetOriginAnchorRob(){
      return m_cOriginAnchor;
   }

   CVector3 CKheperaIVGripperEntity::GetForceSensor(){
      return m_cForceVector;
   }

   Real CKheperaIVGripperEntity::GetExtension(){
      return m_fExtension;
   }

   /****************************************/
   /****************************************/

   REGISTER_STANDARD_SPACE_OPERATIONS_ON_ENTITY(CKheperaIVGripperEntity);

   /****************************************/
   /****************************************/

}
