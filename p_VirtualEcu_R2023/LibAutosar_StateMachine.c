/******************************************************************************/
/* File   : LibAutosar_StateMachine.c                                         */
/*                                                                            */
/* Author : Raajnaag HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "LibAutosar_StateMachine.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define LibAutosarStateMachine_dMaxDepthHierarchy                             8u //TBD: Move to Cfg

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      eHierarchy_Disabled
   ,  eHierarchy_Enabled
}Type_eHierarchy;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
static void lvHandlevent(
      Type_LibAutosarStateMachine_tptrContext const lctptrContext
   ,  Type_LibAutosarStateMachine_eEvent            leEvent
   ,  Type_eHierarchy                               leHierarchy
){
   const Type_LibAutosarStateMachine_stInfoState*   lptrstInfoState;
   const Type_LibAutosarStateMachine_stInfoEvent*   lptrcstInfoEvent;
         Type_LibAutosarStateMachine_eGaurd         leGaurd;
         Type_LibAutosarStateMachine_eState         leState      = lctptrContext->eState;
         uint16                                     u16Hierarchy = 0u;
         uint16                                     u16IndexEvent;

   while(
         (
               LibAutosarStateMachine_dStateDefault
            != leState
         )
      && (
               leState
            <  lctptrContext->u16NumStates
        )
   ){
      lptrstInfoState  = &lctptrContext->pcstInfoState[leState];
      lptrcstInfoEvent = lptrstInfoState->ptrcstInfoEvent;
      for(
         u16IndexEvent = 0u;
         u16IndexEvent < lptrstInfoState->u16NumEvents;
         u16IndexEvent ++
      ){
         if(
               (
                     lptrcstInfoEvent[u16IndexEvent].eEvent
                  == leEvent
               )
            || (
                     lptrcstInfoEvent[u16IndexEvent].eEvent
                  == LibAutosarStateMachine_eEventAny
               )
         ){
            leGaurd = lptrcstInfoEvent[u16IndexEvent].eHandler(
                  lctptrContext
               ,  leEvent
            );
            if(
                  LibAutosarStateMachine_eGaurdFalse
               != leGaurd
            ){
               if(
                     LibAutosarStateMachine_eGaurdTrue
                  == leGaurd
               ){
                  lctptrContext->eStatePending = lptrcstInfoEvent[u16IndexEvent].eStateNext;
               }
               leState = LibAutosarStateMachine_dStateDefault;
               break;
            }
         }
      }
      if(
            LibAutosarStateMachine_dStateDefault
         != leState
      ){
         if(
               eHierarchy_Enabled
            == leHierarchy
         ){
            u16Hierarchy++;
            if(
                  u16Hierarchy
               <  LibAutosarStateMachine_dMaxDepthHierarchy
            ){
               leState = lptrstInfoState->eStateSuper;
            }
            else{
               leState = LibAutosarStateMachine_dStateDefault;
            }
         }
         else{
            leState = LibAutosarStateMachine_dStateDefault;
         }
      }
   }
}

static uint8 lu8GetStateHierachy(
      const Type_LibAutosarStateMachine_tContext* const lctptrContext
   ,        Type_LibAutosarStateMachine_eState          leState
   ,        Type_LibAutosarStateMachine_eState*         lptreStateHierarchy
){
   uint8 lu8IndexHierarchy = 0u;
   while(
         LibAutosarStateMachine_dStateDefault
      != leState
   ){
      if(
            (
                  lu8IndexHierarchy
               >= LibAutosarStateMachine_dMaxDepthHierarchy
            )
         || (
                  leState
               >= lctptrContext->u16NumStates
            )
      ){
         lu8IndexHierarchy = 0u;
         leState = LibAutosarStateMachine_dStateDefault;
      }
      else{
         lptreStateHierarchy[lu8IndexHierarchy] = leState;
         lu8IndexHierarchy++;
         leState = lctptrContext->pcstInfoState[leState].eStateSuper;
      }
   }
   return lu8IndexHierarchy;
}

void LibAutosarStateMachine_vInitFunction(
            Type_LibAutosarStateMachine_tptrContext const lctptrContext
   ,        Type_LibAutosarStateMachine_eState            leStateInitial
   ,        uint16                                        lu16NumStates
   ,  const Type_LibAutosarStateMachine_stInfoState*      lpcstInfoState
){
   lctptrContext->eState        = LibAutosarStateMachine_dStateDefault;
   lctptrContext->eStatePending = leStateInitial;
   lctptrContext->eEventPending = LibAutosarStateMachine_eEventNone;
   lctptrContext->u16NumStates  = lu16NumStates;
   lctptrContext->pcstInfoState = lpcstInfoState;

   LibAutosarStateMachineState_vRunnable(lctptrContext);
}

void LibAutosarStateMachineState_vRunnable(
   Type_LibAutosarStateMachine_tptrContext const lctptrContext
){
   Type_LibAutosarStateMachine_eState laeStateHierarchyExit[LibAutosarStateMachine_dMaxDepthHierarchy];
   Type_LibAutosarStateMachine_eState laeStateHierarchyEntry[LibAutosarStateMachine_dMaxDepthHierarchy];
   Type_LibAutosarStateMachine_eState leStateCurrent;
   Type_LibAutosarStateMachine_eState leStatePending;
   uint8                              lu8CountEntry;
   uint8                              lu8CountExit;
   sint8                              ls8IndexHierarchy;
   sint8                              ls8IndexEntry;
   sint8                              ls8IndexExit;

   if(
         LibAutosarStateMachine_eEventNone
      != lctptrContext->eEventPending
   ){
      lctptrContext->eEventPending = LibAutosarStateMachine_eEventNone;
      lvHandlevent(
            lctptrContext
         ,  lctptrContext->eEventPending
         ,  eHierarchy_Enabled
      );
   }

   while(
         LibAutosarStateMachine_dStateDefault
      != lctptrContext->eStatePending
   ){
      leStateCurrent               = lctptrContext->eState;
      leStatePending               = lctptrContext->eStatePending;
      lctptrContext->eStatePending = LibAutosarStateMachine_dStateDefault;

      lu8CountExit = lu8GetStateHierachy(
            lctptrContext
         ,  leStateCurrent
         ,  laeStateHierarchyExit
      );

      lu8CountEntry = lu8GetStateHierachy(
            lctptrContext
         ,  leStatePending
         ,  laeStateHierarchyEntry
      );

      if(
            leStateCurrent
         == leStatePending
      ){
         ls8IndexExit  = 0;
         ls8IndexEntry = 0;
      }
      else{
         ls8IndexExit  = (sint8)(lu8CountExit  - 1);
         ls8IndexEntry = (sint8)(lu8CountEntry - 1);
         while(
               (
                  ls8IndexExit
                  >= 0
               )
            && (
                     laeStateHierarchyExit[ls8IndexExit]
                  == laeStateHierarchyEntry[ls8IndexEntry]
               )
         ){
            ls8IndexExit--;
            ls8IndexEntry--;
         }
      }

      for(
         ls8IndexHierarchy  = 0;
         ls8IndexHierarchy <= ls8IndexExit;
         ls8IndexHierarchy ++
      ){
         lctptrContext->eState = laeStateHierarchyExit[ls8IndexHierarchy];
         lvHandlevent(
               lctptrContext
            ,  LibAutosarStateMachine_eEventExit
            ,  eHierarchy_Disabled
         );
      }

      for(
         ls8IndexHierarchy  = ls8IndexEntry;
         ls8IndexHierarchy >= 0;
         ls8IndexHierarchy --
      ){
         lctptrContext->eState = laeStateHierarchyEntry[ls8IndexHierarchy];
         lvHandlevent(
               lctptrContext
            ,  LibAutosarStateMachine_eEventEntry
            ,  eHierarchy_Disabled
         );
      }
      lctptrContext->eState = leStatePending;
   }
}

void LibAutosarStateMachine_vTriggerEvent(
      Type_LibAutosarStateMachine_tptrContext const lctptrContext
   ,  Type_LibAutosarStateMachine_eEvent            leEvent
){
   lctptrContext->eEventPending = leEvent;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

