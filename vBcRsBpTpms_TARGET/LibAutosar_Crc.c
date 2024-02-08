/******************************************************************************/
/* File   : LibAutosar_Crc.c                                                  */
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
/* All rights reserved. Copyright � 1982 Raajnaag HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.hpp"

#include "LibAutosar_Crc.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define LibAutosarCrc_dLenTableH04C11DB7                                    256U
#define LibAutosarCrc_dValueXOR32                         ((uint32)0xFFFFFFFFUL)
#define LibAutosarCrc_dValueXOR32P4                       ((uint32)0xFFFFFFFFUL)
#define LibAutosarCrc_dValueJunkH04C11DB7                            ((uint8)8U)
#define LibAutosarCrc_dValueMaskTable32                           ((uint8)0xFFU)
#define LibAutosarCrc_dLenTableH1021                                        256U
#define LibAutosarCrc_dValueJunkH1021                                         8U
#define LibAutosarCrc_dValueMaskTable16                                    0xFFU

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
#define CRC_START_SEC_CONST_32
#include "Crc_MemMap.hpp"
static const uint32  LibAutosarCrc_cau32TableH04C11DB7[LibAutosarCrc_dLenTableH04C11DB7] = {
      0x00000000uL, 0x77073096uL, 0xee0e612cuL, 0x990951bauL
   ,  0x076dc419uL, 0x706af48fuL, 0xe963a535uL, 0x9e6495a3uL
   ,  0x0edb8832uL, 0x79dcb8a4uL, 0xe0d5e91euL, 0x97d2d988uL
   ,  0x09b64c2buL, 0x7eb17cbduL, 0xe7b82d07uL, 0x90bf1d91uL
   ,  0x1db71064uL, 0x6ab020f2uL, 0xf3b97148uL, 0x84be41deuL
   ,  0x1adad47duL, 0x6ddde4ebuL, 0xf4d4b551uL, 0x83d385c7uL
   ,  0x136c9856uL, 0x646ba8c0uL, 0xfd62f97auL, 0x8a65c9ecuL
   ,  0x14015c4fuL, 0x63066cd9uL, 0xfa0f3d63uL, 0x8d080df5uL
   ,  0x3b6e20c8uL, 0x4c69105euL, 0xd56041e4uL, 0xa2677172uL
   ,  0x3c03e4d1uL, 0x4b04d447uL, 0xd20d85fduL, 0xa50ab56buL
   ,  0x35b5a8fauL, 0x42b2986cuL, 0xdbbbc9d6uL, 0xacbcf940uL
   ,  0x32d86ce3uL, 0x45df5c75uL, 0xdcd60dcfuL, 0xabd13d59uL
   ,  0x26d930acuL, 0x51de003auL, 0xc8d75180uL, 0xbfd06116uL
   ,  0x21b4f4b5uL, 0x56b3c423uL, 0xcfba9599uL, 0xb8bda50fuL
   ,  0x2802b89euL, 0x5f058808uL, 0xc60cd9b2uL, 0xb10be924uL
   ,  0x2f6f7c87uL, 0x58684c11uL, 0xc1611dabuL, 0xb6662d3duL
   ,  0x76dc4190uL, 0x01db7106uL, 0x98d220bcuL, 0xefd5102auL
   ,  0x71b18589uL, 0x06b6b51fuL, 0x9fbfe4a5uL, 0xe8b8d433uL
   ,  0x7807c9a2uL, 0x0f00f934uL, 0x9609a88euL, 0xe10e9818uL
   ,  0x7f6a0dbbuL, 0x086d3d2duL, 0x91646c97uL, 0xe6635c01uL
   ,  0x6b6b51f4uL, 0x1c6c6162uL, 0x856530d8uL, 0xf262004euL
   ,  0x6c0695eduL, 0x1b01a57buL, 0x8208f4c1uL, 0xf50fc457uL
   ,  0x65b0d9c6uL, 0x12b7e950uL, 0x8bbeb8eauL, 0xfcb9887cuL
   ,  0x62dd1ddfuL, 0x15da2d49uL, 0x8cd37cf3uL, 0xfbd44c65uL
   ,  0x4db26158uL, 0x3ab551ceuL, 0xa3bc0074uL, 0xd4bb30e2uL
   ,  0x4adfa541uL, 0x3dd895d7uL, 0xa4d1c46duL, 0xd3d6f4fbuL
   ,  0x4369e96auL, 0x346ed9fcuL, 0xad678846uL, 0xda60b8d0uL
   ,  0x44042d73uL, 0x33031de5uL, 0xaa0a4c5fuL, 0xdd0d7cc9uL
   ,  0x5005713cuL, 0x270241aauL, 0xbe0b1010uL, 0xc90c2086uL
   ,  0x5768b525uL, 0x206f85b3uL, 0xb966d409uL, 0xce61e49fuL
   ,  0x5edef90euL, 0x29d9c998uL, 0xb0d09822uL, 0xc7d7a8b4uL
   ,  0x59b33d17uL, 0x2eb40d81uL, 0xb7bd5c3buL, 0xc0ba6caduL
   ,  0xedb88320uL, 0x9abfb3b6uL, 0x03b6e20cuL, 0x74b1d29auL
   ,  0xead54739uL, 0x9dd277afuL, 0x04db2615uL, 0x73dc1683uL
   ,  0xe3630b12uL, 0x94643b84uL, 0x0d6d6a3euL, 0x7a6a5aa8uL
   ,  0xe40ecf0buL, 0x9309ff9duL, 0x0a00ae27uL, 0x7d079eb1uL
   ,  0xf00f9344uL, 0x8708a3d2uL, 0x1e01f268uL, 0x6906c2feuL
   ,  0xf762575duL, 0x806567cbuL, 0x196c3671uL, 0x6e6b06e7uL
   ,  0xfed41b76uL, 0x89d32be0uL, 0x10da7a5auL, 0x67dd4accuL
   ,  0xf9b9df6fuL, 0x8ebeeff9uL, 0x17b7be43uL, 0x60b08ed5uL
   ,  0xd6d6a3e8uL, 0xa1d1937euL, 0x38d8c2c4uL, 0x4fdff252uL
   ,  0xd1bb67f1uL, 0xa6bc5767uL, 0x3fb506dduL, 0x48b2364buL
   ,  0xd80d2bdauL, 0xaf0a1b4cuL, 0x36034af6uL, 0x41047a60uL
   ,  0xdf60efc3uL, 0xa867df55uL, 0x316e8eefuL, 0x4669be79uL
   ,  0xcb61b38cuL, 0xbc66831auL, 0x256fd2a0uL, 0x5268e236uL
   ,  0xcc0c7795uL, 0xbb0b4703uL, 0x220216b9uL, 0x5505262fuL
   ,  0xc5ba3bbeuL, 0xb2bd0b28uL, 0x2bb45a92uL, 0x5cb36a04uL
   ,  0xc2d7ffa7uL, 0xb5d0cf31uL, 0x2cd99e8buL, 0x5bdeae1duL
   ,  0x9b64c2b0uL, 0xec63f226uL, 0x756aa39cuL, 0x026d930auL
   ,  0x9c0906a9uL, 0xeb0e363fuL, 0x72076785uL, 0x05005713uL
   ,  0x95bf4a82uL, 0xe2b87a14uL, 0x7bb12baeuL, 0x0cb61b38uL
   ,  0x92d28e9buL, 0xe5d5be0duL, 0x7cdcefb7uL, 0x0bdbdf21uL
   ,  0x86d3d2d4uL, 0xf1d4e242uL, 0x68ddb3f8uL, 0x1fda836euL
   ,  0x81be16cduL, 0xf6b9265buL, 0x6fb077e1uL, 0x18b74777uL
   ,  0x88085ae6uL, 0xff0f6a70uL, 0x66063bcauL, 0x11010b5cuL
   ,  0x8f659effuL, 0xf862ae69uL, 0x616bffd3uL, 0x166ccf45uL
   ,  0xa00ae278uL, 0xd70dd2eeuL, 0x4e048354uL, 0x3903b3c2uL
   ,  0xa7672661uL, 0xd06016f7uL, 0x4969474duL, 0x3e6e77dbuL
   ,  0xaed16a4auL, 0xd9d65adcuL, 0x40df0b66uL, 0x37d83bf0uL
   ,  0xa9bcae53uL, 0xdebb9ec5uL, 0x47b2cf7fuL, 0x30b5ffe9uL
   ,  0xbdbdf21cuL, 0xcabac28auL, 0x53b39330uL, 0x24b4a3a6uL
   ,  0xbad03605uL, 0xcdd70693uL, 0x54de5729uL, 0x23d967bfuL
   ,  0xb3667a2euL, 0xc4614ab8uL, 0x5d681b02uL, 0x2a6f2b94uL
   ,  0xb40bbe37uL, 0xc30c8ea1uL, 0x5a05df1buL, 0x2d02ef8duL
};

static const uint32  CRC_32_REVHF4ACFB13_Tbl[CRC_32P4_TABLESIZE] = {
     0x00000000uL, 0x30850FF5uL, 0x610A1FEAuL, 0x518F101FuL
   ,    0xC2143FD4uL, 0xF2913021uL, 0xA31E203EuL, 0x939B2FCBuL
   ,    0x159615F7uL, 0x25131A02uL, 0x749C0A1DuL, 0x441905E8uL
   ,    0xD7822A23uL, 0xE70725D6uL, 0xB68835C9uL, 0x860D3A3CuL
   ,    0x2B2C2BEEuL, 0x1BA9241BuL, 0x4A263404uL, 0x7AA33BF1uL
   ,    0xE938143AuL, 0xD9BD1BCFuL, 0x88320BD0uL, 0xB8B70425uL
   ,    0x3EBA3E19uL, 0x0E3F31ECuL, 0x5FB021F3uL, 0x6F352E06uL
   ,    0xFCAE01CDuL, 0xCC2B0E38uL, 0x9DA41E27uL, 0xAD2111D2uL
   ,    0x565857DCuL, 0x66DD5829uL, 0x37524836uL, 0x07D747C3uL
   ,    0x944C6808uL, 0xA4C967FDuL, 0xF54677E2uL, 0xC5C37817uL
   ,    0x43CE422BuL, 0x734B4DDEuL, 0x22C45DC1uL, 0x12415234uL
   ,    0x81DA7DFFuL, 0xB15F720AuL, 0xE0D06215uL, 0xD0556DE0uL
   ,    0x7D747C32uL, 0x4DF173C7uL, 0x1C7E63D8uL, 0x2CFB6C2DuL
   ,    0xBF6043E6uL, 0x8FE54C13uL, 0xDE6A5C0CuL, 0xEEEF53F9uL
   ,    0x68E269C5uL, 0x58676630uL, 0x09E8762FuL, 0x396D79DAuL
   ,    0xAAF65611uL, 0x9A7359E4uL, 0xCBFC49FBuL, 0xFB79460EuL
   ,    0xACB0AFB8uL, 0x9C35A04DuL, 0xCDBAB052uL, 0xFD3FBFA7uL
   ,    0x6EA4906CuL, 0x5E219F99uL, 0x0FAE8F86uL, 0x3F2B8073uL
   ,    0xB926BA4FuL, 0x89A3B5BAuL, 0xD82CA5A5uL, 0xE8A9AA50uL
   ,    0x7B32859BuL, 0x4BB78A6EuL, 0x1A389A71uL, 0x2ABD9584uL
   ,    0x879C8456uL, 0xB7198BA3uL, 0xE6969BBCuL, 0xD6139449uL
   ,    0x4588BB82uL, 0x750DB477uL, 0x2482A468uL, 0x1407AB9DuL
   ,    0x920A91A1uL, 0xA28F9E54uL, 0xF3008E4BuL, 0xC38581BEuL
   ,    0x501EAE75uL, 0x609BA180uL, 0x3114B19FuL, 0x0191BE6AuL
   ,    0xFAE8F864uL, 0xCA6DF791uL, 0x9BE2E78EuL, 0xAB67E87BuL
   ,    0x38FCC7B0uL, 0x0879C845uL, 0x59F6D85AuL, 0x6973D7AFuL
   ,    0xEF7EED93uL, 0xDFFBE266uL, 0x8E74F279uL, 0xBEF1FD8CuL
   ,    0x2D6AD247uL, 0x1DEFDDB2uL, 0x4C60CDADuL, 0x7CE5C258uL
   ,    0xD1C4D38AuL, 0xE141DC7FuL, 0xB0CECC60uL, 0x804BC395uL
   ,    0x13D0EC5EuL, 0x2355E3ABuL, 0x72DAF3B4uL, 0x425FFC41uL
   ,    0xC452C67DuL, 0xF4D7C988uL, 0xA558D997uL, 0x95DDD662uL
   ,    0x0646F9A9uL, 0x36C3F65CuL, 0x674CE643uL, 0x57C9E9B6uL
   ,    0xC8DF352FuL, 0xF85A3ADAuL, 0xA9D52AC5uL, 0x99502530uL
   ,    0x0ACB0AFBuL, 0x3A4E050EuL, 0x6BC11511uL, 0x5B441AE4uL
   ,    0xDD4920D8uL, 0xEDCC2F2DuL, 0xBC433F32uL, 0x8CC630C7uL
   ,    0x1F5D1F0CuL, 0x2FD810F9uL, 0x7E5700E6uL, 0x4ED20F13uL
   ,    0xE3F31EC1uL, 0xD3761134uL, 0x82F9012BuL, 0xB27C0EDEuL
   ,    0x21E72115uL, 0x11622EE0uL, 0x40ED3EFFuL, 0x7068310AuL
   ,    0xF6650B36uL, 0xC6E004C3uL, 0x976F14DCuL, 0xA7EA1B29uL
   ,    0x347134E2uL, 0x04F43B17uL, 0x557B2B08uL, 0x65FE24FDuL
   ,    0x9E8762F3uL, 0xAE026D06uL, 0xFF8D7D19uL, 0xCF0872ECuL
   ,    0x5C935D27uL, 0x6C1652D2uL, 0x3D9942CDuL, 0x0D1C4D38uL
   ,    0x8B117704uL, 0xBB9478F1uL, 0xEA1B68EEuL, 0xDA9E671BuL
   ,    0x490548D0uL, 0x79804725uL, 0x280F573AuL, 0x188A58CFuL
   ,    0xB5AB491DuL, 0x852E46E8uL, 0xD4A156F7uL, 0xE4245902uL
   ,    0x77BF76C9uL, 0x473A793CuL, 0x16B56923uL, 0x263066D6uL
   ,    0xA03D5CEAuL, 0x90B8531FuL, 0xC1374300uL, 0xF1B24CF5uL
   ,    0x6229633EuL, 0x52AC6CCBuL, 0x03237CD4uL, 0x33A67321uL
   ,    0x646F9A97uL, 0x54EA9562uL, 0x0565857DuL, 0x35E08A88uL
   ,    0xA67BA543uL, 0x96FEAAB6uL, 0xC771BAA9uL, 0xF7F4B55CuL
   ,    0x71F98F60uL, 0x417C8095uL, 0x10F3908AuL, 0x20769F7FuL
   ,    0xB3EDB0B4uL, 0x8368BF41uL, 0xD2E7AF5EuL, 0xE262A0ABuL
   ,    0x4F43B179uL, 0x7FC6BE8CuL, 0x2E49AE93uL, 0x1ECCA166uL
   ,    0x8D578EADuL, 0xBDD28158uL, 0xEC5D9147uL, 0xDCD89EB2uL
   ,    0x5AD5A48EuL, 0x6A50AB7BuL, 0x3BDFBB64uL, 0x0B5AB491uL
   ,    0x98C19B5AuL, 0xA84494AFuL, 0xF9CB84B0uL, 0xC94E8B45uL
   ,    0x3237CD4BuL, 0x02B2C2BEuL, 0x533DD2A1uL, 0x63B8DD54uL
   ,    0xF023F29FuL, 0xC0A6FD6AuL, 0x9129ED75uL, 0xA1ACE280uL
   ,    0x27A1D8BCuL, 0x1724D749uL, 0x46ABC756uL, 0x762EC8A3uL
   ,    0xE5B5E768uL, 0xD530E89DuL, 0x84BFF882uL, 0xB43AF777uL
   ,    0x191BE6A5uL, 0x299EE950uL, 0x7811F94FuL, 0x4894F6BAuL
   ,    0xDB0FD971uL, 0xEB8AD684uL, 0xBA05C69BuL, 0x8A80C96EuL
   ,    0x0C8DF352uL, 0x3C08FCA7uL, 0x6D87ECB8uL, 0x5D02E34DuL
   ,    0xCE99CC86uL, 0xFE1CC373uL, 0xAF93D36CuL, 0x9F16DC99uL
};
#define CRC_STOP_SEC_CONST_32
#include "Crc_MemMap.hpp"

#define CRC_START_SEC_CONST_16
#include "Crc_MemMap.hpp"
static const uint16  LibAutosarCrc_cau16TableH1021[LibAutosarCrc_dLenTableH1021] = {
      0x0000u, 0x1021u, 0x2042u, 0x3063u, 0x4084u, 0x50a5u, 0x60c6u, 0x70e7u
   ,  0x8108u, 0x9129u, 0xa14au, 0xb16bu, 0xc18cu, 0xd1adu, 0xe1ceu, 0xf1efu
   ,  0x1231u, 0x0210u, 0x3273u, 0x2252u, 0x52b5u, 0x4294u, 0x72f7u, 0x62d6u
   ,  0x9339u, 0x8318u, 0xb37bu, 0xa35au, 0xd3bdu, 0xc39cu, 0xf3ffu, 0xe3deu
   ,  0x2462u, 0x3443u, 0x0420u, 0x1401u, 0x64e6u, 0x74c7u, 0x44a4u, 0x5485u
   ,  0xa56au, 0xb54bu, 0x8528u, 0x9509u, 0xe5eeu, 0xf5cfu, 0xc5acu, 0xd58du
   ,  0x3653u, 0x2672u, 0x1611u, 0x0630u, 0x76d7u, 0x66f6u, 0x5695u, 0x46b4u
   ,  0xb75bu, 0xa77au, 0x9719u, 0x8738u, 0xf7dfu, 0xe7feu, 0xd79du, 0xc7bcu
   ,  0x48c4u, 0x58e5u, 0x6886u, 0x78a7u, 0x0840u, 0x1861u, 0x2802u, 0x3823u
   ,  0xc9ccu, 0xd9edu, 0xe98eu, 0xf9afu, 0x8948u, 0x9969u, 0xa90au, 0xb92bu
   ,  0x5af5u, 0x4ad4u, 0x7ab7u, 0x6a96u, 0x1a71u, 0x0a50u, 0x3a33u, 0x2a12u
   ,  0xdbfdu, 0xcbdcu, 0xfbbfu, 0xeb9eu, 0x9b79u, 0x8b58u, 0xbb3bu, 0xab1au
   ,  0x6ca6u, 0x7c87u, 0x4ce4u, 0x5cc5u, 0x2c22u, 0x3c03u, 0x0c60u, 0x1c41u
   ,  0xedaeu, 0xfd8fu, 0xcdecu, 0xddcdu, 0xad2au, 0xbd0bu, 0x8d68u, 0x9d49u
   ,  0x7e97u, 0x6eb6u, 0x5ed5u, 0x4ef4u, 0x3e13u, 0x2e32u, 0x1e51u, 0x0e70u
   ,  0xff9fu, 0xefbeu, 0xdfddu, 0xcffcu, 0xbf1bu, 0xaf3au, 0x9f59u, 0x8f78u
   ,  0x9188u, 0x81a9u, 0xb1cau, 0xa1ebu, 0xd10cu, 0xc12du, 0xf14eu, 0xe16fu
   ,  0x1080u, 0x00a1u, 0x30c2u, 0x20e3u, 0x5004u, 0x4025u, 0x7046u, 0x6067u
   ,  0x83b9u, 0x9398u, 0xa3fbu, 0xb3dau, 0xc33du, 0xd31cu, 0xe37fu, 0xf35eu
   ,  0x02b1u, 0x1290u, 0x22f3u, 0x32d2u, 0x4235u, 0x5214u, 0x6277u, 0x7256u
   ,  0xb5eau, 0xa5cbu, 0x95a8u, 0x8589u, 0xf56eu, 0xe54fu, 0xd52cu, 0xc50du
   ,  0x34e2u, 0x24c3u, 0x14a0u, 0x0481u, 0x7466u, 0x6447u, 0x5424u, 0x4405u
   ,  0xa7dbu, 0xb7fau, 0x8799u, 0x97b8u, 0xe75fu, 0xf77eu, 0xc71du, 0xd73cu
   ,  0x26d3u, 0x36f2u, 0x0691u, 0x16b0u, 0x6657u, 0x7676u, 0x4615u, 0x5634u
   ,  0xd94cu, 0xc96du, 0xf90eu, 0xe92fu, 0x99c8u, 0x89e9u, 0xb98au, 0xa9abu
   ,  0x5844u, 0x4865u, 0x7806u, 0x6827u, 0x18c0u, 0x08e1u, 0x3882u, 0x28a3u
   ,  0xcb7du, 0xdb5cu, 0xeb3fu, 0xfb1eu, 0x8bf9u, 0x9bd8u, 0xabbbu, 0xbb9au
   ,  0x4a75u, 0x5a54u, 0x6a37u, 0x7a16u, 0x0af1u, 0x1ad0u, 0x2ab3u, 0x3a92u
   ,  0xfd2eu, 0xed0fu, 0xdd6cu, 0xcd4du, 0xbdaau, 0xad8bu, 0x9de8u, 0x8dc9u
   ,  0x7c26u, 0x6c07u, 0x5c64u, 0x4c45u, 0x3ca2u, 0x2c83u, 0x1ce0u, 0x0cc1u
   ,  0xef1fu, 0xff3eu, 0xcf5du, 0xdf7cu, 0xaf9bu, 0xbfbau, 0x8fd9u, 0x9ff8u
   ,  0x6e17u, 0x7e36u, 0x4e55u, 0x5e74u, 0x2e93u, 0x3eb2u, 0x0ed1u, 0x1ef0u
};
#define CRC_STOP_SEC_CONST_16
#include "Crc_MemMap.hpp"

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.hpp"
uint32 LibAutosarCrc_u32Calculate(
      const uint8*  lptru8Data
   ,        uint32  lu32LengthData
   ,        uint32  lu32ValueInitial
   ,        boolean lbIsCallFirstTime
){
   uint32 lu32IndexData;
   uint32 lu32CrcCalculated = (
      (FALSE != lbIsCallFirstTime)
      ? LibAutosarCrc_dValueInitial32
      : lu32ValueInitial ^ LibAutosarCrc_dValueXOR32
   );
   for(
      lu32IndexData = 0U;
      lu32IndexData < lu32LengthData;
      lu32IndexData ++
   ){
      lu32CrcCalculated ^= lptru8Data[lu32IndexData];
      lu32CrcCalculated = ((lu32CrcCalculated >> LibAutosarCrc_dValueJunkH04C11DB7) ^ LibAutosarCrc_cau32TableH04C11DB7[lu32CrcCalculated & LibAutosarCrc_dValueMaskTable32]);
   }
   return (lu32CrcCalculated ^ LibAutosarCrc_dValueXOR32);
}

uint32 LibAutosarCrc_u32CalculateP4(
      const uint8*  lptru8Data
   ,        uint32  lu32LengthData
   ,        uint32  lu32ValueInitial
   ,        boolean lbIsCallFirstTime
){
   uint32 lu32IndexData;
   uint32 crcTemp;
   uint32 lu32CrcCalculated;
   if(FALSE != lbIsCallFirstTime){
        crcTemp = LibAutosarCrc_dValueInitial32P4;
   }
   else{
        crcTemp = lu32ValueInitial ^ LibAutosarCrc_dValueXOR32P4;
   }
   for(lu32IndexData = 0U; lu32IndexData < lu32LengthData; ++lu32IndexData){
        crcTemp ^= lptru8Data[lu32IndexData];
        crcTemp = (crcTemp >> ((uint8)CRC_32P4_CHUNK)) ^
                   CRC_32_REVHF4ACFB13_Tbl[crcTemp & ((uint8)CRC_32P4_TABLEMASK)];
   }
   lu32CrcCalculated = crcTemp ^ LibAutosarCrc_dValueXOR32P4;
   return lu32CrcCalculated;
}

uint16 LibAutosarCrc_u16Calculate(
      const uint8*  lptru8Data
   ,        uint32  lu32LengthData
   ,        uint16  lu16ValueInitial
   ,        boolean lbIsCallFirstTime
){
   uint32 lu32IndexData;
   uint16 lu16CrcCalculated = (
      (FALSE != lbIsCallFirstTime)
      ? LibAutosarCrc_dValueInitial16
      : lu16ValueInitial
   );
   for(
      lu32IndexData = 0U;
      lu32IndexData < lu32LengthData;
      lu32IndexData ++
   ){
      lu16CrcCalculated ^= ((uint16)lptru8Data[lu32IndexData]) << LibAutosarCrc_dValueJunkH1021REST;
      lu16CrcCalculated  = (
            (lu16CrcCalculated << LibAutosarCrc_dValueJunkH1021)
         ^  LibAutosarCrc_cau16TableH1021[(lu16CrcCalculated >> LibAutosarCrc_dValueJunkH1021REST) & LibAutosarCrc_dValueMaskTable16]
      );
   }
   return lu16CrcCalculated;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.hpp"

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

