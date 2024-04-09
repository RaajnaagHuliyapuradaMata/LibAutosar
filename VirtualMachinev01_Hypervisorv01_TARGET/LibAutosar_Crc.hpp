#pragma once
/******************************************************************************/
/* File   : LibAutosar_Crc.hpp                                                */
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
/* All rights reserved. Copyright � 1982 Nagaraja HULIYAPURADA MATA           */
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
#define LibAutosarCrc_dValueInitial32P4                   ((uint32)0xFFFFFFFFUL)
#define LibAutosarCrc_dValueInitial32                     ((uint32)0xFFFFFFFFUL)
#define LibAutosarCrc_dValueInitial16                          ((uint16)0xFFFFU)
#define LibAutosarCrc_dValueJunkH1021REST                                     8U
#define CRC_32P4_CHUNK                                               ((uint8)8U)
#define CRC_32P4_TABLESIZE                                                  256U
#define CRC_32P4_TABLEMASK                                                 0xFFU

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
extern uint32 LibAutosarCrc_u32Calculate(
      const uint8*  lptru8Data
   ,        uint32  lu32LengthData
   ,        uint32  lu32ValueInitial
   ,        boolean lbIsCallFirstTime
);

extern uint32 LibAutosarCrc_u32CalculateP4(
      const uint8*  lptru8Data
   ,        uint32  lu32LengthData
   ,        uint32  lu32ValueInitial
   ,        boolean lbIsCallFirstTime
);

extern uint16 LibAutosarCrc_u16Calculate(
      const uint8*  lptru8Data
   ,        uint32  lu32LengthData
   ,        uint16  lu16ValueInitial
   ,        boolean lbIsCallFirstTime
);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

