/******************************************************************************/
/* File   : LibAutosar_MemCopy.c                                              */
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
/* git@github.com:RaajnaagHuliyapuradaMata/<module_name>.git                  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"
#include "LibAutosar_MemCopy.h"

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
void* LibAutosar_ptrvMemCopy(
            void*  ptrvDestination
   ,  const void*  ptrcvSource
   ,        uint32 u32NumByte
){
    uint32* xDest_pu32       = (uint32*)ptrvDestination;
    const uint32* xSrc_pcu32 = (const uint32*)ptrcvSource;
    uint16* xDest_pu16;
    const uint16* xSrc_pcu16;
    uint8* xDest_pu8;
    const uint8* xSrc_pcu8;
    uint32 ctLoop_u32;

    if ((u32NumByte >= 4) && ((((uint32)xDest_pu32 | (uint32)xSrc_pcu32) & 0x03) == 0))
    {
        ctLoop_u32 = u32NumByte / 4;
        u32NumByte &= 0x03;
        do
        {
            *xDest_pu32 = *xSrc_pcu32;
            xDest_pu32++;
            xSrc_pcu32++;
            ctLoop_u32--;
        } while(ctLoop_u32 > 0);
    }

    xDest_pu16 = (uint16*)xDest_pu32;
    xSrc_pcu16 = (const uint16*)xSrc_pcu32;

    if ((u32NumByte >= 2) && ((((uint32)xDest_pu16 | (uint32)xSrc_pcu16) & 0x01) == 0))
    {
        ctLoop_u32 = u32NumByte / 2;
        u32NumByte &= 0x01;
        do
        {
            *xDest_pu16 = *xSrc_pcu16;
            xDest_pu16++;
            xSrc_pcu16++;
            ctLoop_u32--;
        } while(ctLoop_u32 > 0);
    }

    xDest_pu8 = (uint8*)xDest_pu16;
    xSrc_pcu8 = (const uint8*)xSrc_pcu16;

    for(ctLoop_u32 = 0; ctLoop_u32 < u32NumByte; ctLoop_u32++)
    {
        *xDest_pu8 = *xSrc_pcu8;
        xDest_pu8++;
        xSrc_pcu8++;
    }
    return ptrvDestination;
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
