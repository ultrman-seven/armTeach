#include "stdint.h"
#include "wy_gpio.h"
#include "wy_key.h"

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

#define LED_SINGLE_PIN GPIO_Pin9
#define LED_SINGLE_PORT GPIOC
#define LED_SINGLE LED_SINGLE_PORT, LED_SINGLE_PIN

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

// void redFlip(void)
// {
//     GPIO_flip(RED_LED);
// }

#define LED_FLIP(COLOR)           \
    void LED_##COLOR##_Flip(void) \
    {                             \
        GPIO_flip(COLOR##_LED);   \
    }

LED_FLIP(RED)
LED_FLIP(BLUE)
LED_FLIP(GREEN)

void delay_bad(volatile uint32_t time)
{
    while (time--)
        ;
}

int main()
{
    GPIO_InitStructTypedef g;
    // 开时钟
    RCC_AHBENR |= (1 << RCC_AHB_GPIOC_Pos);

    // 初始化GPIO
    g.pin = BLUE_PIN | RED_PIN | GREEN_PIN | LED_SINGLE_PIN;
    g.mode = GPIO_Mode_pull_push;
    g.speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &g);

    KeyStructTypedef keyUp,keyDown,keyLeft,keyRight,keyMid;
    //C99特性
    // KeyStructTypedef keyDown = {.callback = LED_GREEN_Flip, .gpioN = DOWN_PORT, .pin = DOWN_PIN, .m = keyIPU};
    // key_Init(&keyDown);

    key_StructInit(&keyUp, "D6", keyIPU, LED_BLUE_Flip);
    key_StructInit(&keyDown, "a15", keyIPU, LED_RED_Flip);
    key_StructInit(&keyLeft, "c12", keyIPU, LED_GREEN_Flip);
    // key_StructInit(&keyRight, "", keyIPU, );
    // key_StructInit(&keyMid, "", keyIPU, );

    GPIO_Resetbit(GPIOC, GPIO_Pin7 | GPIO_Pin8 | GPIO_Pin6);

    while (1)
    {
        key_DetAndRunByFlag(&keyUp);
        key_DetAndRunByFlag(&keyDown);
        key_DetAndRunByFlag(&keyLeft);

        GPIO_flip(LED_SINGLE);
        delay_bad(0xffff);
    }
}

void SystemInit(void)
{
}
