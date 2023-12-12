#if !defined (CRC_H)
#define CRC_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "CfgLibAutosarCrc.hpp"

#define SYSSERVICE_ASRCRC_VERSION         (0x0400u)
#define SYSSERVICE_ASRCRC_RELEASE_VERSION (0x01u)
#define CRC_VENDOR_ID               (1u)
#define CRC_MODULE_ID               (201u)
#define CRC_INSTANCE_ID             (0u)
#define CRC_AR_MAJOR_VERSION        (3u)
#define CRC_AR_MINOR_VERSION        (0u)
#define CRC_AR_PATCH_VERSION        (0u)
#define CRC_SW_MAJOR_VERSION        (SYSSERVICE_ASRCRC_VERSION >> 8u)
#define CRC_SW_MINOR_VERSION        (SYSSERVICE_ASRCRC_VERSION & 0x00FF)
#define CRC_SW_PATCH_VERSION        SYSSERVICE_ASRCRC_RELEASE_VERSION
#define CRC_INITIAL_VALUE8          (0x0)
#define CRC_INITIAL_VALUE16         (0xFFFF)
#define CRC_INITIAL_VALUE32         (0xFFFFFFFFL)

typedef P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataRefType;

#define CRC_START_SEC_CODE
#include "MemMap.hpp"

FUNC(uint16, LIBAUTOSARCRC_CODE) LibAutosarCrc_CalculateCRC16
                (
                     Crc_DataRefType Crc_DataPtr
   ,                    uint32 Crc_Length
   ,                    uint16 Crc_StartValue16
   ,                    uint8 Crc_Status
                );

FUNC(uint32, LIBAUTOSARCRC_CODE) LibAutosarCrc_CalculateCRC32
                (
                     Crc_DataRefType Crc_DataPtr
   ,                    uint32 Crc_Length
   ,                    uint32 Crc_StartValue32
                );

FUNC(uint8, LIBAUTOSARCRC_CODE) LibAutosarCrc_CalculateCRC8
                (
                     Crc_DataRefType Crc_DataPtr
   ,                    uint32 Crc_Length
   ,                    uint8 Crc_StartValue8
                );

#if(CRC_VERSION_INFO_API == STD_ON)
    FUNC(void, LIBAUTOSARCRC_CODE) LibAutosarCrc_GetVersionInfo
                (
                     P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_APPL_DATA) versioninfo
                );
#endif

#define CRC_STOP_SEC_CODE
#include "MemMap.hpp"

#ifdef __cplusplus
}
#endif
#endif

