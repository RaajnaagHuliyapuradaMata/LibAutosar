/******************************************************************************/
/* File   : LibAutosar_MovingAverage.c                                        */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"
#include "LibAutosar_MovingAverage.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

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
void LibAutosarInitMovingAverage(
      LibAutosar_typeContextMovingAverage* lpstContext
   ,  uint16*                              lpu16Buffer
   ,  uint8                                lu8LenBuffer
){
   lpstContext->pu16Buffer       = lpu16Buffer;
   lpstContext->u8LenBuffer      = lu8LenBuffer;
   lpstContext->u8IndexSampleNew = 0;
   lpstContext->u8NumberSamples  = 0;
   lpstContext->u16MovingSum     = 0;
   lpstContext->u16MovingAverage = 0;
}

void LibAutosarCalcMovingAverage(
      LibAutosar_typeContextMovingAverage* lpstContext
   ,  uint16                               lu16SampleNew
){
   uint16 lu16SampleOld = lpstContext->pu16Buffer[lpstContext->u8IndexSampleNew];
   uint8  lu8SizeWindow = lpstContext->u8LenBuffer;
   lpstContext->pu16Buffer[lpstContext->u8IndexSampleNew] = lu16SampleNew;
   if(lu8SizeWindow > lpstContext->u8NumberSamples){
      lpstContext->u8NumberSamples++;
      lu16SampleOld = 0;
      lu8SizeWindow = lpstContext->u8NumberSamples;
   }
   lpstContext->u16MovingSum    += lu16SampleNew - lu16SampleOld;
   lpstContext->u16MovingAverage = lpstContext->u16MovingSum / lu8SizeWindow;
   lpstContext->u8IndexSampleNew++;
   lpstContext->u8IndexSampleNew %= lpstContext->u8LenBuffer;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
