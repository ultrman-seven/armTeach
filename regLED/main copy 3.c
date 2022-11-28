#include "stdint.h"
#include "wy_gpio.h"

void SystemInit(void);

#define RCC_BASE (0x40021000)
#define RCC_AHBENR (*(uint32_t *)(RCC_BASE + 0x14))

#define RCC_AHB_GPIOA_Pos (17)
#define RCC_AHB_GPIOB_Pos (18)
#define RCC_AHB_GPIOC_Pos (19)
#define RCC_AHB_GPIOD_Pos (20)

#define RED_PIN GPIO_Pin6
#define RED_PORT GPIOC
#define RED_LED RED_PORT, RED_PIN

#define GREEN_PIN GPIO_Pin8
#define GREEN_PORT GPIOC
#define GREEN_LED GREEN_PORT, GREEN_PIN

#define BLUE_PIN GPIO_Pin7
#define BLUE_PORT GPIOC
#define BLUE_LED BLUE_PORT, BLUE_PIN

#define UP_PIN GPIO_Pin6
#define UP_PORT GPIOD
#define KEY_UP UP_PORT, UP_PIN

#define DOWN_PIN GPIO_Pin11
#define DOWN_PORT GPIOC
#define KEY_DOWN DOWN_PORT, DOWN_PIN

#define LEFT_PIN GPIO_Pin12
#define LEFT_PORT GPIOC
#define KEY_LEFT LEFT_PORT, LEFT_PIN

void GPIO_flip(GPIO_StructTypedef *gpioN, uint16_t pin);
void GPIO_flip(GPIO_StructTypedef *gpioN, uint16_t pin)
{
    // HAL 版本
    if (GPIO_readOutputDataBit(gpioN, pin))
        GPIO_Resetbit(gpioN, pin);
    else
        GPIO_Setbit(gpioN, pin);

    // 寄存器版本
    // if (gpioN->ODR & pin)
    //     gpioN->BRR = pin;
    // else
    //     gpioN->BSRR = pin;
}

int main()
{
    GPIO_InitStructTypedef g;
    // 开时钟
    RCC_AHBENR |= (1 << RCC_AHB_GPIOC_Pos);
    RCC_AHBENR |= (1 << RCC_AHB_GPIOD_Pos);

    // 初始化GPIO
    g.pin = GPIO_Pin7 | RED_PIN | GREEN_PIN;
    g.mode = GPIO_Mode_pull_push;
    g.speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &g);

    g.pin = RED_PIN;
    GPIO_Init(RED_PORT, &g);

    g.pin = GPIO_Pin6;
    g.mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOD, &g);

    g.pin = DOWN_PIN | LEFT_PIN;
    GPIO_Init(GPIOC, &g);

    GPIO_Resetbit(GPIOC, GPIO_Pin7 | GPIO_Pin8 | GPIO_Pin6);

    while (1)
    {

        if (!GPIO_readInputDataBit(KEY_UP))
        {
            GPIO_flip(RED_LED);
            while (!GPIO_readInputDataBit(KEY_UP))
                ;
        }
        if (!GPIO_readInputDataBit(KEY_DOWN))
        {
            GPIO_flip(BLUE_LED);
            while (!GPIO_readInputDataBit(KEY_DOWN))
                ;
        }
        if (!GPIO_readInputDataBit(KEY_LEFT))
        {
            GPIO_flip(GREEN_LED);
            while (!GPIO_readInputDataBit(KEY_LEFT))
                ;
        }

    }
}

void SystemInit(void)
{
}
