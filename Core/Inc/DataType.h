#ifndef  DATATYPE_H
#define  DATATYPE_H

#include "stm32f4xx_hal.h"
//#include <stdint.h>


#define  TRUE       0
#define  FALSE      1
#define  BUSY       2
#define  ILDE       3
#define  OVER_FLOW  4
#define  DATA_ERR   5
#define  OVER_TIME  6


#define  HIGH   1
#define  LOW    0

#define	Bit_0	0x0001
#define	Bit_1	0x0002
#define	Bit_2	0x0004
#define	Bit_3	0x0008
#define	Bit_4	0x0010
#define	Bit_5	0x0020
#define	Bit_6	0x0040
#define	Bit_7	0x0080
#define	Bit_8	0x0100
#define	Bit_9	0x0200
#define	Bit_10	0x0400
#define	Bit_11	0x0800
#define	Bit_12	0x1000
#define	Bit_13	0x2000
#define	Bit_14	0x4000
#define	Bit_15	0x8000


typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< Read Only */
typedef const int16_t sc16;  /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< Read Only */
typedef __I int16_t vsc16;  /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< Read Only */
typedef const uint16_t uc16;  /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< Read Only */
typedef __I uint16_t vuc16;  /*!< Read Only */
typedef __I uint8_t vuc8;   /*!< Read Only */



typedef union 
{
    u8  B08[2];
    u16 B16;
}B16_B08;

typedef union 
{
    u8  B08[4];
    u32 B32;
}B32_B08;

typedef union 
{
    u16 B16[2];
    u32 B32;
}B32_B16;




#endif






