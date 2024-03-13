/**
 * @file <argos3/plugins/robots/foot-bot/simulator/dynamics2d_footbot_model.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef DYNAMICS2D_KHEPERAIV_MODEL_H
#define DYNAMICS2D_KHEPERAIV_MODEL_H

namespace argos {
   class CDynamics2DDifferentialSteeringControl;
   class CDynamics2DGripper;
   class CDynamics2DGrippable;
}

#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_multi_body_object_model.h>
#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_differentialsteering_control.h>
#include <argos3/plugins/robots/kheperaiv/simulator/kheperaiv_entity.h>
#include <argos3/plugins/robots/kheperaiv/simulator/kheperaiv_gripper_entity.h>

namespace argos {

   class CDynamics2DKheperaIVModel : public CDynamics2DMultiBodyObjectModel {

   public:

      CDynamics2DKheperaIVModel(CDynamics2DEngine& c_engine,
                              CKheperaIVEntity& c_entity);
      virtual ~CDynamics2DKheperaIVModel();
      
      virtual void MoveTo(const CVector3& c_position,
                          const CQuaternion& c_orientation);

      virtual void Reset();

      virtual void CalculateBoundingBox();

      virtual void UpdateFromEntityStatus();

      virtual void UpdateEntityStatus();

      void UpdateOriginAnchor(SAnchor& s_anchor);

      void UpdateTurretAnchor(SAnchor& s_anchor);

      inline cpBody* GetActualBaseBody() {
         return m_ptActualBaseBody;
      }

      inline const cpBody* GetActualBaseBody() const {
         return m_ptActualBaseBody;
      }

      inline cpBody* GetActualGripperBody() {
         return m_ptActualGripperBody;
      }

      inline const cpBody* GetActualGripperBody() const {
         return m_ptActualGripperBody;
      }

   private:

      void TurretPassiveToActive();
      void TurretActiveToPassive();

   private:

      CKheperaIVEntity&         m_CKheperaIVEntity;
      CWheeledEntity&         m_cWheeledEntity;
      CKheperaIVGripperEntity& m_cGripperEntity;

      CDynamics2DDifferentialSteeringControl m_cDiffSteering;
      CDynamics2DGripper*                    m_pcGripper;
      CDynamics2DGrippable*                  m_pcGrippable;

      cpFloat  m_fMass;
      cpShape* m_ptBaseShape;
      cpBody*  m_ptActualBaseBody;
      cpBody*  m_ptActualGripperBody;
      cpBody*  m_ptControlGripperBody;
      cpConstraint* m_ptGripperControlAngularMotion;
      cpConstraint* m_ptBaseGripperLinearMotion;
      cpConstraint* m_ptBaseGripperAngularMotion;
      int m_dTick = 0;

      const Real* m_fCurrentWheelVelocity;

      UInt8 m_unLastTurretMode;
      Real m_fPreviousTurretAngleError;

   };

}

#endif
