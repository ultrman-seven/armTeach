#include "stdint.h"
#include "wy_gpio.h"

void SystemInit(void);

#define RCC_BASE (0x40021000)
#define RCC_AHBENR (*(uint32_t *)(RCC_BASE + 0x14))

#define RCC_AHB_GPIOA_Pos (17)
#define RCC_AHB_GPIOB_Pos (18)
#define RCC_AHB_GPIOC_Pos (19)
#define RCC_AHB_GPIOD_Pos (20)

int main()
{
    GPIO_InitStructTypedef g;
    // 开时钟
    RCC_AHBENR |= (1 << RCC_AHB_GPIOC_Pos);
    RCC_AHBENR |= (1 << RCC_AHB_GPIOD_Pos);

    // 初始化GPIO
    g.pin = GPIO_Pin7 | GPIO_Pin6 | GPIO_Pin8;
    g.mode = GPIO_Mode_pull_push;
    g.speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &g);

    g.pin = GPIO_Pin6;
    g.mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOD, &g);

    // GPIO_Setbit(GPIOC, GPIO_Pin7 | GPIO_Pin8 | GPIO_Pin6);


    while (1)
    {
        if(GPIO_readInputDataBit(GPIOD,GPIO_Pin6))
        {
            GPIO_Setbit(GPIOC, GPIO_Pin6);
            GPIO_Resetbit(GPIOC, GPIO_Pin8);
        }
        else
        {
            GPIO_Resetbit(GPIOC, GPIO_Pin6);
            GPIO_Setbit(GPIOC, GPIO_Pin8);
        }
    }
}

void SystemInit(void)
{
}
