#include "wy_key.h"

void keyIPU_DetAndRun(GPIO_StructTypedef *gpioN, uint16_t pin, void (*callback)(void))
{
    if (!GPIO_readInputDataBit(gpioN, pin))
    {
        callback();
        while (!GPIO_readInputDataBit(gpioN, pin))
            ;
    }
}
void keyIPD_DetAndRun(GPIO_StructTypedef *gpioN, uint16_t pin)
{
    if (GPIO_readInputDataBit(gpioN, pin))
    {
        // GPIO_flip(RED_LED);
        while (GPIO_readInputDataBit(gpioN, pin))
            ;
    }
}

void key_Init(KeyStructTypedef *key)
{
    GPIO_InitStructTypedef g;
    g.pin = key->pin;
    g.mode = (key->m == keyIPD) ? GPIO_Mode_IPD : GPIO_Mode_IPU;
    GPIO_Init(key->gpioN, &g);
    key->flag = 0;
}

void key_DetAndRunByFlag(KeyStructTypedef *key)
{
    // 不按是高电平，按下才是低电平
    uint8_t ks = GPIO_readInputDataBit(key->gpioN, key->pin);
    if (key->m == keyIPU)
        ks = !ks;

    if (ks)
    {
        if (!key->flag)
        {
            key->callback();
            key->flag++;
        }
    }
    else
        key->flag = 0;
}

#define RCC_BASE (0x40021000)
#define RCC_AHBENR (*(uint32_t *)(RCC_BASE + 0x14))

#define RCC_AHB_GPIOA_Pos (17)
#define RCC_AHB_GPIOB_Pos (18)
#define RCC_AHB_GPIOC_Pos (19)
#define RCC_AHB_GPIOD_Pos (20)

const uint32_t GPIO_BASEs[] = {GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE};
const uint32_t RCC_AHB_GPIOs[] = {0x01 << RCC_AHB_GPIOA_Pos, 0x01 << RCC_AHB_GPIOB_Pos, 0x01 << RCC_AHB_GPIOC_Pos, 0x01 << RCC_AHB_GPIOD_Pos};
void key_StructInit(KeyStructTypedef *key, const char *p, KEY_Mode m, void (*callback)(void))
{

    GPIO_InitStructTypedef g;

    // 找GPIO几
    if (*p >= 'a' && *p <= 'd')
    {
        key->gpioN = (GPIO_StructTypedef *)GPIO_BASEs[*p - 'a'];
        RCC_AHBENR |= RCC_AHB_GPIOs[*p - 'a'];
    }
    else if (*p >= 'A' && *p <= 'D')
    {
        key->gpioN = (GPIO_StructTypedef *)GPIO_BASEs[*p - 'A'];
        RCC_AHBENR |= RCC_AHB_GPIOs[*p - 'A'];
    }

    // 找pin几
    key->pin = *++p - '0';
    while (*++p)
    {
        key->pin *= 10;
        key->pin += *p - '0';
    }

    key->pin = (uint16_t)0x01 << key->pin;

    g.mode = (m == keyIPU) ? GPIO_Mode_IPU : GPIO_Mode_IPD;
    g.pin = key->pin;

    GPIO_Init(key->gpioN, &g);
    key->m = m;
    key->flag = 0;
    key->callback = callback;
}
