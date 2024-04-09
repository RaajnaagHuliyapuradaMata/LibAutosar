/******************************************************************************/
/* File   : LibAutosar_FindElementInArray.c                                   */
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
#include "Std_Types.h"
#include "LibAutosar_FindElementInArray.h"

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
uint16 LibAutosar_u16FindElementInArray(
      uint16* lptru16Array
   ,  uint16  lu16NumElements
   ,  uint16  lu16ValueElement
){
   uint16 u16ReturnValueIndexElement = -1;
   uint16 u16IndexElement;
   for(
      u16IndexElement = 0u;
      u16IndexElement < lu16NumElements;
      u16IndexElement ++
   ){
      if(
            lptru16Array[u16IndexElement]
         == lu16ValueElement
      ){
         u16ReturnValueIndexElement = u16IndexElement;
         break;
      }
   }
   return u16ReturnValueIndexElement;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
