#ifndef _LIBAUTOSAR_MOVINGAVERAGE_H
#define _LIBAUTOSAR_MOVINGAVERAGE_H
/******************************************************************************/
/* File   : LibAutosar_MovingAverage.h                                        */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
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
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
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
typedef struct{
   uint16* pu16Buffer;
   uint16  u16MovingSum;
   uint16  u16MovingAverage;
   uint8   u8LenBuffer;
   uint8   u8IndexSampleNew;
   uint8   u8NumberSamples;
}LibAutosar_typeContextMovingAverage;

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
extern void LibAutosarInitMovingAverage(
      LibAutosar_typeContextMovingAverage* lpstContext
   ,  uint16*                              lpu16Buffer
   ,  uint8                                lu8LenBuffer
);

extern void LibAutosarCalcMovingAverage(
      LibAutosar_typeContextMovingAverage* lpstContext
   ,  uint16                               lu16SampleNew
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
#endif
