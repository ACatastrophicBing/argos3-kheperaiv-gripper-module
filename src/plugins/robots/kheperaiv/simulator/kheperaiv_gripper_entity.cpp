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
      CEntity(pc_parent) { // m_pcBatteryEquippedEntity WAS down here
      Reset();
      Disable();
   }

   /****************************************/
   /****************************************/
   
   CKheperaIVGripperEntity::CKheperaIVGripperEntity(CComposableEntity* pc_parent,
                                              const std::string& str_id) :
      CEntity(pc_parent, str_id) {
      try{
         Reset();
         Disable();
      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Failed to initialize entity \"" << GetId() << "\".", ex);
      }
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Init(TConfigurationNode& t_tree) {
      
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Reset() {
      m_fExtension = 0.0;
      m_cAnchor1 = CVector3::Zero;
      m_cAnchor2 = CVector3::Zero;
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::Destroy() {
      m_fExtension = 0.0;
      m_cAnchor1 = CVector3::Zero;
      m_cAnchor2 = CVector3::Zero;
   }

   /****************************************/
   /****************************************/

   void CKheperaIVGripperEntity::UpdateComponents() {
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

   /****************************************/
   /****************************************/
    
   // TODO : Add Turret Entity to registration
   REGISTER_ENTITY(CKheperaIVGripperEntity,
                   "kheperaiv",
                   "Carlo Pinciroli [ilpincy@gmail.com]",
                   "1.0",
                   "The Khepera IV robot.",
                   "The Khepera IV is a commercial, extensible robot produced by K-Teams. More\n"
                   "information is available at https://www.k-team.com/khepera-iv.\n\n"
                   "REQUIRED XML CONFIGURATION\n\n"
                   "  <arena ...>\n"
                   "    ...\n"
                   "    <kheperaiv id=\"eb0\">\n"
                   "      <body position=\"0.4,2.3,0.25\" orientation=\"45,90,0\" />\n"
                   "      <controller config=\"mycntrl\" />\n"
                   "    </kheperaiv>\n"
                   "    ...\n"
                   "  </arena>\n\n"
                   "The 'id' attribute is necessary and must be unique among the entities. If two\n"
                   "entities share the same id, initialization aborts.\n"
                   "The 'body/position' attribute specifies the position of the pucktom point of the\n"
                   "Khepera IV in the arena. When the robot is untranslated and unrotated, the\n"
                   "pucktom point is in the origin and it is defined as the middle point between\n"
                   "the two wheels on the XY plane and the lowest point of the robot on the Z\n"
                   "axis, that is the point where the wheels touch the floor. The attribute values\n"
                   "are in the X,Y,Z order.\n"
                   "The 'body/orientation' attribute specifies the orientation of the Khepera IV.\n"
                   "All rotations are performed with respect to the pucktom point. The order of the\n"
                   "angles is Z,Y,X, which means that the first number corresponds to the rotation\n"
                   "around the Z axis, the second around Y and the last around X. This reflects\n"
                   "the internal convention used in ARGoS, in which rotations are performed in\n"
                   "that order. Angles are expressed in degrees. When the robot is unrotated, it\n"
                   "is oriented along the X axis.\n"
                   "The 'controller/config' attribute is used to assign a controller to the\n"
                   "Khepera IV. The value of the attribute must be set to the id of a previously\n"
                   "defined controller. Controllers are defined in the <controllers> XML subtree.\n\n"
                   "OPTIONAL XML CONFIGURATION\n\n"
                   "You can set the emission range of the range-and-bearing system. By default, a\n"
                   "message sent by a Khepera IV can be received up to 3m. By using the 'rab_range'\n"
                   "attribute, you can change it to, i.e., 4m as follows:\n\n"
                   "  <arena ...>\n"
                   "    ...\n"
                   "    <kheperaiv id=\"kh0\" rab_range=\"4\">\n"
                   "      <body position=\"0.4,2.3,0.25\" orientation=\"45,0,0\" />\n"
                   "      <controller config=\"mycntrl\" />\n"
                   "    </kheperaiv>\n"
                   "    ...\n"
                   "  </arena>\n\n"
                   "You can also set the data sent at each time step through the range-and-bearing"
                   "system. By default, a message sent by a khepera is 50 bytes long. By using the"
                   "'rab_data_size' attribute, you can change it to, i.e., 100 bytes as follows:\n\n"
                   "  <arena ...>\n"
                   "    ...\n"
                   "    <kheperaiv id=\"kh0\" rab_data_size=\"100\">\n"
                   "      <body position=\"0.4,2.3,0.25\" orientation=\"45,0,0\" />\n"
                   "      <controller config=\"mycntrl\" />\n"
                   "    </kheperaiv>\n"
                   "    ...\n"
                   "  </arena>\n\n"
                   "You can also configure the battery of the robot. By default, the battery never\n"
                   "depletes. You can choose among several battery discharge models, such as\n"
                   "- time: the battery depletes by a fixed amount at each time step\n"
                   "- motion: the battery depletes according to how the robot moves\n"
                   "- time_motion: a combination of the above models.\n"
                   "You can define your own models too. Follow the examples in the file\n"
                   "argos3/src/plugins/simulator/entities/battery_equipped_entity.cpp.\n\n"
                   "  <arena ...>\n"
                   "    ...\n"
                   "    <kheperaiv id=\"kh0\"\n"
                   "      <body position=\"0.4,2.3,0.25\" orientation=\"45,0,0\" />\n"
                   "      <controller config=\"mycntrl\" />\n"
                   "      <battery model=\"time\" factor=\"1e-5\"/>\n"
                   "    </kheperaiv>\n"
                   "    ...\n"
                   "  </arena>\n\n"
                   "  <arena ...>\n"
                   "    ...\n"
                   "    <kheperaiv id=\"kh0\"\n"
                   "      <body position=\"0.4,2.3,0.25\" orientation=\"45,0,0\" />\n"
                   "      <controller config=\"mycntrl\" />\n"
                   "      <battery model=\"motion\" pos_factor=\"1e-3\"\n"
                   "                              orient_factor=\"1e-3\"/>\n"
                   "    </kheperaiv>\n"
                   "    ...\n"
                   "  </arena>\n\n"
                   "  <arena ...>\n"
                   "    ...\n"
                   "    <kheperaiv id=\"kh0\"\n"
                   "      <body position=\"0.4,2.3,0.25\" orientation=\"45,0,0\" />\n"
                   "      <controller config=\"mycntrl\" />\n"
                   "      <battery model=\"time_motion\" time_factor=\"1e-5\"\n"
                   "                                   pos_factor=\"1e-3\"\n"
                   "                                   orient_factor=\"1e-3\"/>\n"
                   "    </kheperaiv>\n"
                   "    ...\n"
                   "  </arena>\n\n",
                   "Under development"
      );

   /****************************************/
   /****************************************/

   REGISTER_STANDARD_SPACE_OPERATIONS_ON_COMPOSABLE(CKheperaIVEntity);

   /****************************************/
   /****************************************/

}
