#pragma once
/******************************************************************************/
/* File   : LibAutosar_StateMachine.h                                         */
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
#include "CompilerCfg_LibAutosar.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define LibAutosarStateMachine_dStateDefault ((Type_LibAutosarStateMachine_eState)-1)

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
typedef enum{
      LibAutosarStateMachine_eGaurdTrue
   ,  LibAutosarStateMachine_eGaurdFalse
   ,  LibAutosarStateMachine_eGaurdOverwrite
}Type_LibAutosarStateMachine_eGaurd;

typedef enum{ //TBD: Server independent, client configurable
      LibAutosarStateMachine_eStateCallFailsafeUpdater
   ,  LibAutosarStateMachine_eStateCallSwcServiceStartUp
   ,  LibAutosarStateMachine_eStateCallSwcServiceStartUpInitCmac
   ,  LibAutosarStateMachine_eStateCallSwcServiceStartUpInitKey
   ,  LibAutosarStateMachine_eStateCallSwcServiceStartUpStayInBoot
   ,  LibAutosarStateMachine_eStateCallTarget
   ,  LibAutosarStateMachine_eStateCheckApplStartFlag
   ,  LibAutosarStateMachine_eStateCheckKeyAvailability
   ,  LibAutosarStateMachine_eStateCheckReprogFlag
   ,  LibAutosarStateMachine_eStateCheckReprogLbt
   ,  LibAutosarStateMachine_eStateCheckSwcServiceStartUpLbt
   ,  LibAutosarStateMachine_eStateCheckSwcServiceStartUpMacErased
   ,  LibAutosarStateMachine_eStateCheckSwcServiceStartUpValidity
   ,  LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerification
   ,  LibAutosarStateMachine_eStateCheckSwcServiceStartUpVerificationStayInBoot
   ,  LibAutosarStateMachine_eStateFail
   ,  LibAutosarStateMachine_eStateFailsafeUpdaterCheck
   ,  LibAutosarStateMachine_eStateFailsafeUpdaterEnabled
   ,  LibAutosarStateMachine_eStateFailsafeUpdaterSearchInit
   ,  LibAutosarStateMachine_eStateFailsafeUpdaterSearchNext
   ,  LibAutosarStateMachine_eStateInit
   ,  LibAutosarStateMachine_eStateInitSwcServiceStartUpMacEnabled
   ,  LibAutosarStateMachine_eStatePowerOn
   ,  LibAutosarStateMachine_eStateReprogLbtEnabled
   ,  LibAutosarStateMachine_eStateSecureBootEnabled
   ,  LibAutosarStateMachine_eStateStayInBootEnabled
   ,  LibAutosarStateMachine_eStateTargetCheck
   ,  LibAutosarStateMachine_eStateTargetListInit
   ,  LibAutosarStateMachine_eStateTargetListNext
}Type_LibAutosarStateMachine_eState;

typedef enum{
      LibAutosarStateMachine_eEventNone
   ,  LibAutosarStateMachine_eEventEntry
   ,  LibAutosarStateMachine_eEventExit
   ,  LibAutosarStateMachine_eEventAny
   ,  LibAutosarStateMachine_eEventContinue
}Type_LibAutosarStateMachine_eEvent;

typedef struct Type_LibAutosarStateMachine_stContext Type_LibAutosarStateMachine_tContext;
typedef        Type_LibAutosarStateMachine_tContext* Type_LibAutosarStateMachine_tptrContext;

typedef Type_LibAutosarStateMachine_eGaurd (*Type_LibAutosarStateMachine_eEventHandler)(
      Type_LibAutosarStateMachine_tptrContext const ctptrContext
   ,  Type_LibAutosarStateMachine_eEvent            eEvent
);

typedef struct{
         Type_LibAutosarStateMachine_eEventHandler  eHandler;
         Type_LibAutosarStateMachine_eEvent         eEvent;
         Type_LibAutosarStateMachine_eState         eStateNext;
}Type_LibAutosarStateMachine_stInfoEvent;

typedef struct{
         uint16                                     u16NumEvents;
   const Type_LibAutosarStateMachine_stInfoEvent*   ptrcstInfoEvent;
         Type_LibAutosarStateMachine_eState         eStateSuper;
}Type_LibAutosarStateMachine_stInfoState;

struct Type_LibAutosarStateMachine_stContext{
         Type_LibAutosarStateMachine_eState         eState;
         Type_LibAutosarStateMachine_eState         eStatePending;
         Type_LibAutosarStateMachine_eEvent         eEventPending;
         uint16                                     u16NumStates;
   const Type_LibAutosarStateMachine_stInfoState*   pcstInfoState;
};

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
extern FUNC(void, LIBAUTOSAR_CODE) LibAutosarStateMachine_vInitFunction(
            Type_LibAutosarStateMachine_tptrContext const lctptrContext
   ,        Type_LibAutosarStateMachine_eState            leStateInitial
   ,        uint16                                        lu16NumStates
   ,  const Type_LibAutosarStateMachine_stInfoState*      lpcstInfoState
);

extern FUNC(void, LIBAUTOSAR_CODE) LibAutosarStateMachineState_vRunnable(
            Type_LibAutosarStateMachine_tptrContext const lctptrContext
);

extern FUNC(void, LIBAUTOSAR_CODE) LibAutosarStateMachine_vTriggerEvent(
            Type_LibAutosarStateMachine_tptrContext const lctptrContext
   ,        Type_LibAutosarStateMachine_eEvent            leEvent
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

