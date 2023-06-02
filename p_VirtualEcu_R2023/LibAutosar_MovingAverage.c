/******************************************************************************/
/* File   : LibAutosar_MovingAverage.c                                        */
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
/* git@bitbucket.org:raajnaag-huliyapurada-mata/<module_name>.git             */
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
/*                                                                            */
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
