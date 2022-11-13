#include "stdint.h"
// 将 PC9 输出1

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


int main()
{
    // // 首先，开GPIOC的时钟
    // *(uint32_t *)(0x40021000 + 0x14) |= (1 << 19);
    // // 然后,配置PC9工作模式
    // *(uint32_t *)(0x48000800 + 0x04) |= (1 << 4);
    // *(uint32_t *)(0x48000800 + 0x04) &= ~(7 << 5);
    // // 最后,输出1
    // *(uint32_t *)(0x48000800 + 0x0C) |= (1 << 9);
    *(uint32_t *)(0x40021000 + 0x14) |= (1 << 19);

    // *(uint32_t *)(0x48000800 + 0x00) |= (1 << 24);
    GPIOC->CRL |= (1 << 24);

    // *(uint32_t *)(0x48000800 + 0x00) &= ~(7 << 25);
    GPIOC->CRL &= ~(7 << 25);

    // *(uint32_t *)(0x48000800 + 0x0C) |= (1 << 6);
    GPIOC->ODR |= (1 << 6);
    while (1)
    {
    }
}

void SystemInit()
{
}
