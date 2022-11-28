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

void key_Init(KeyStructTypedef*key)
{
    GPIO_InitStructTypedef g;
    g.pin = key->pin;
    g.mode = (key->m == keyIPD) ? GPIO_Mode_IPD : GPIO_Mode_IPU;
    GPIO_Init(key->gpioN, &g);
    key->flag = 0;
}

void key_DetAndRunByFlag(KeyStructTypedef*key)
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
