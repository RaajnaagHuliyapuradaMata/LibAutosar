#pragma once
/******************************************************************************/
/* File   : LibAutosar_Fifo.hpp                                               */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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
