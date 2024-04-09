#pragma once
/******************************************************************************/
/* File   : LibAutosar_Fifo.hpp                                               */
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
typedef uint8 LibAutosarFifo_tItem;

typedef enum{
      LibAutosarFifo_eStatus_OK
   ,  LibAutosarFifo_eStatus_InitNotDone
   ,  LibAutosarFifo_eStatus_NullPointer
   ,  LibAutosarFifo_eStatus_Overflow
   ,  LibAutosarFifo_eStatus_Underflow
}LibAutosarFifo_teStatus;

typedef struct{
   LibAutosarFifo_tItem* ptBuffer; //TBD: Based on size of Item, it is possible to extend ring buffer for generic Item types
   uint8                 u8NumMaxItems; //TBD: max length init
   uint8                 u8IndexWrite;
   uint8                 u8IndexRead;
}LibAutosarFifo_t;

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
extern LibAutosarFifo_teStatus LibAutosarFifo_InitFunction(
      LibAutosarFifo_t*     lpstFifo
   ,  LibAutosarFifo_tItem* lptBuffer
   ,  uint8                 lu8NumMaxItems
);

extern LibAutosarFifo_teStatus LibAutosarFifo_Get(
      LibAutosarFifo_t*     lpstFifo
   ,  LibAutosarFifo_tItem* lptItem
);

extern LibAutosarFifo_teStatus LibAutosarFifo_Put(
      LibAutosarFifo_t* lpstFifo
   ,  uint8             lu8Item
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
