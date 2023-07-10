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

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

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
      LibAutosarStateMachine_eStatePowerOn
   ,  LibAutosarStateMachine_eStateINIT
   ,  LibAutosarStateMachine_eStateCHECK_SWCSERVICESTARTUP_VALIDITY
   ,  LibAutosarStateMachine_eStateFailSAFE_UPDATER_ENABLED
   ,  LibAutosarStateMachine_eStateFailSAFE_UPDATER_SEARCH_INIT
   ,  LibAutosarStateMachine_eStateFailSAFE_UPDATER_CHECK
   ,  LibAutosarStateMachine_eStateFailSAFE_UPDATER_SEARCH_NEXT
   ,  LibAutosarStateMachine_eStateCALL_FAILSAFE_UPDATER
   ,  LibAutosarStateMachine_eStateSECURE_BOOT_ENABLED
   ,  LibAutosarStateMachine_eStateCHECK_KEY_AVAILABILITY
   ,  LibAutosarStateMachine_eStateCALL_SWCSERVICESTARTUP_INIT_KEY
   ,  LibAutosarStateMachine_eStateINIT_SWCSERVICESTARTUP_MAC_ENABLED
   ,  LibAutosarStateMachine_eStateCHECK_SWCSERVICESTARTUP_MAC_ERASED
   ,  LibAutosarStateMachine_eStateCALL_SWCSERVICESTARTUP_INIT_CMAC
   ,  LibAutosarStateMachine_eStateSTAY_IN_BOOT_ENABLED
   ,  LibAutosarStateMachine_eStateCHECK_APPL_START_FLAG
   ,  LibAutosarStateMachine_eStateCHECK_SWCSERVICESTARTUP_LBT
   ,  LibAutosarStateMachine_eStateCHECK_REPROG_FLAG
   ,  LibAutosarStateMachine_eStateREPROG_LBT_ENABLED
   ,  LibAutosarStateMachine_eStateCHECK_REPROG_LBT
   ,  LibAutosarStateMachine_eStateTARGET_LIST_INIT
   ,  LibAutosarStateMachine_eStateTARGET_CHECK
   ,  LibAutosarStateMachine_eStateTARGET_LIST_NEXT
   ,  LibAutosarStateMachine_eStateCALL_TARGET
   ,  LibAutosarStateMachine_eStateCHECK_SWCSERVICESTARTUP_VERIFICATION
   ,  LibAutosarStateMachine_eStateCHECK_SWCSERVICESTARTUP_VERIFICATION_STAY_IN_BOOT
   ,  LibAutosarStateMachine_eStateCALL_SWCSERVICESTARTUP
   ,  LibAutosarStateMachine_eStateCALL_SWCSERVICESTARTUP_STAY_IN_BOOT
   ,  LibAutosarStateMachine_eStateFail
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
         Type_LibAutosarStateMachine_eEvent         eEvent; // trigger
         Type_LibAutosarStateMachine_eState         eStateNext;
}LibAutosarStateMachine_stEventEntry;

typedef struct{
         Type_LibAutosarStateMachine_eState         eStateSuper;
         uint16                                     u16NumTrigger;
   const LibAutosarStateMachine_stEventEntry*       ptrcstEventEntry;
}Type_LibAutosarStateMachine_stInfoState;

struct Type_LibAutosarStateMachine_stContext{
   const Type_LibAutosarStateMachine_stInfoState*   pcstInfoState;
         uint16                                     u16NumStates;
         Type_LibAutosarStateMachine_eState         eState;
         Type_LibAutosarStateMachine_eState         eStatePending;
         Type_LibAutosarStateMachine_eEvent         eEventPending;
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
extern void LibAutosarStateMachine_vInitFunction(
      Type_LibAutosarStateMachine_tptrContext const lctptrContext
   ,  Type_LibAutosarStateMachine_eState            leStateInitial
);

extern void LibAutosarStateMachineState_vRunnable(
      Type_LibAutosarStateMachine_tptrContext const lctptrContext
);

extern void LibAutosarStateMachine_vTriggerEvent(
      Type_LibAutosarStateMachine_tptrContext const lctptrContext
   ,  Type_LibAutosarStateMachine_eEvent            leEvent
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

