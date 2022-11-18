#ifndef __WY_GPIO_H__
#define __WY_GPIO_H__
#include "stdint.h"

typedef struct
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
    uint32_t AFRL;
    uint32_t AFRH;
} GPIO_StructTypedef;
#define GPIOA_BASE (0x48000000)
#define GPIOB_BASE (0x48000400)
#define GPIOC_BASE (0x48000800)
#define GPIOD_BASE (0x48000C00)

#define GPIOA ((GPIO_StructTypedef *)GPIOA_BASE)
#define GPIOB ((GPIO_StructTypedef *)GPIOB_BASE)
#define GPIOC ((GPIO_StructTypedef *)GPIOC_BASE)
#define GPIOD ((GPIO_StructTypedef *)GPIOD_BASE)

typedef enum
{
    GPIO_Mode_Ain = 0x00,
    GPIO_Mode_pull_push = 0x01,
    GPIO_Mode_floating = 0x04,
    GPIO_Mode_OD = 0x05,
    GPIO_Mode_AF_pull_push = 0x09,
    GPIO_Mode_AF_OD = 0x0d,

    GPIO_Mode_IPU,
    GPIO_Mode_IPD
} GPIO_Mode;
typedef enum
{
    GPIO_Speed_2MHz,
    GPIO_Speed_20MHz,
    GPIO_Speed_50MHz
} GPIO_Speed;

#define GPIO_Pin0 0x1   // 0b 0000 0000 0000 0001
#define GPIO_Pin1 0x2   // 0b 0000 0000 0000 0010
#define GPIO_Pin2 0x4   // 0b 0000 0000 0000 0100
#define GPIO_Pin3 0x8   // 0b 0000 0000 0000 1000
#define GPIO_Pin4 0x10  // 0b 0000 0000 0001 0000
#define GPIO_Pin5 0x20  // 0b 0000 0000 0010 0000
#define GPIO_Pin6 0x40  // 0b 0000 0000 0100 0000
#define GPIO_Pin7 0x80  // 0b 0000 0000 1000 0000
#define GPIO_Pin8 0x100 // 0b 0000 0001 0000 0000
#define GPIO_Pin9 0x200
#define GPIO_Pin10 0x400
#define GPIO_Pin11 0x800
#define GPIO_Pin12 0x1000
#define GPIO_Pin13 0x2000
#define GPIO_Pin14 0x4000
#define GPIO_Pin15 0x8000

#define GPIO_PinAll 0xffff

typedef struct
{
    uint16_t pin;
    GPIO_Mode mode;
    GPIO_Speed speed;
} GPIO_InitStructTypedef;

void GPIO_Init(GPIO_StructTypedef *gpioN, GPIO_InitStructTypedef *gpioInit);
void GPIO_Setbit(GPIO_StructTypedef *gpioN, uint16_t pin);
void GPIO_Resetbit(GPIO_StructTypedef *gpioN, uint16_t pin);
// void GPIO_readInputDataBit();
// void GPIO_readOutputDataBit();

#endif //__WY_GPIO_H__