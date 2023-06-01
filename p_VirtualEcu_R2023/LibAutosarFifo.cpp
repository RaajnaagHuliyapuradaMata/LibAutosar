/******************************************************************************/
/* File   : LibAutosarFifo.cpp                                                */
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
#include "Std_Types.hpp"

#include "LibAutosarFifo.hpp"

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
LibAutosarFifo_teStatus LibAutosarFifo_InitFunction(
      LibAutosarFifo_t*     lpstFifo
   ,  LibAutosarFifo_tItem* lptBuffer
   ,  uint8                 lu8NumMaxItems
){
   LibAutosarFifo_teStatus lValueReturn;
   if(
         NULL_PTR
      != lpstFifo
   ){
      if(
            NULL_PTR
         != lptBuffer
      ){
         lpstFifo->ptBuffer      = lptBuffer;
         lpstFifo->u8NumMaxItems = lu8NumMaxItems; //TBD: Length chack needed
         lpstFifo->u8IndexWrite  =  0;
         lpstFifo->u8IndexRead   = lu8NumMaxItems-1;
      }
      else{
         lValueReturn = LibAutosarFifo_eStatus_NullPointer;
      }
   }
   else{
      lValueReturn = LibAutosarFifo_eStatus_InitNotDone;
   }
   return lValueReturn;
}

LibAutosarFifo_teStatus LibAutosarFifo_Get(
      LibAutosarFifo_t*     lpstFifo
   ,  LibAutosarFifo_tItem* lptItem
){
   LibAutosarFifo_teStatus lValueReturn;
   if(
         NULL_PTR
      != lpstFifo
   ){
      if(
            NULL_PTR
         != lpstFifo->ptBuffer
      ){
         if(
               lpstFifo->u8IndexWrite
            != (
                     (lpstFifo->u8IndexRead + 1)
                  %  lpstFifo->u8NumMaxItems
               )
         ){
            lpstFifo->u8IndexRead = (lpstFifo->u8IndexRead + 1) % lpstFifo->u8NumMaxItems;
            *lptItem = lpstFifo->ptBuffer[lpstFifo->u8IndexRead];
            lValueReturn = LibAutosarFifo_eStatus_OK;
         }else{
            lValueReturn = LibAutosarFifo_eStatus_Underflow;
         }
      }
      else{
         lValueReturn = LibAutosarFifo_eStatus_NullPointer;
      }
   }
   else{
      lValueReturn = LibAutosarFifo_eStatus_InitNotDone;
   }
   return lValueReturn;
}

LibAutosarFifo_teStatus LibAutosarFifo_Put(
      LibAutosarFifo_t* lpstFifo
   ,  uint8             lu8Item
){
   LibAutosarFifo_teStatus lValueReturn;
   if(
         NULL_PTR
      != lpstFifo
   ){
      if(
            NULL_PTR
         != lpstFifo->ptBuffer
      ){
         if(
               lpstFifo->u8IndexRead
            != lpstFifo->u8IndexWrite
         ){
            lpstFifo->ptBuffer[lpstFifo->u8IndexWrite] = lu8Item;
            lpstFifo->u8IndexWrite = (lpstFifo->u8IndexWrite + 1) % lpstFifo->u8NumMaxItems;
            lValueReturn = LibAutosarFifo_eStatus_OK;
         }else{
            lValueReturn = LibAutosarFifo_eStatus_Overflow;
         }
      }
      else{
         lValueReturn = LibAutosarFifo_eStatus_NullPointer;
      }
   }
   else{
      lValueReturn = LibAutosarFifo_eStatus_InitNotDone;
   }
   return lValueReturn;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
