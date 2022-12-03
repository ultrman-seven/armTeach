#include "wy_gpio.h"

void GPIO_Init(GPIO_StructTypedef *gpioN, GPIO_InitStructTypedef *gpioInit)
{
    uint8_t pinPosition;
    uint8_t cnt;
    uint64_t mask;
    uint64_t *gpioCR = (uint64_t *)((uint32_t) & (gpioN->CRL));
    for (cnt = 0; cnt < 16; cnt++)
        if (gpioInit->pin & ((0x01) << cnt))
        {
            pinPosition = (uint8_t)(cnt << 2);
            mask = (uint64_t)0x0f << pinPosition;
            mask = ~mask;
            *gpioCR &= mask;

            if (gpioInit->mode == GPIO_Mode_IPD || gpioInit->mode == GPIO_Mode_IPU)
            {
                mask = (uint64_t)0x08 << pinPosition;
                *gpioCR |= mask;
            }
            else
            {
                mask = (uint64_t)(gpioInit->mode) << pinPosition;
                *gpioCR |= mask;
            }
        }
    if (gpioInit->mode == GPIO_Mode_IPU)
        gpioN->ODR |= gpioInit->pin;
    if (gpioInit->mode == GPIO_Mode_IPD)
        gpioN->ODR &= ~(gpioInit->pin);
}

void GPIO_Setbit(GPIO_StructTypedef *gpioN, uint16_t pin) { gpioN->BSRR = pin; }

void GPIO_Resetbit(GPIO_StructTypedef *gpioN, uint16_t pin) { gpioN->BRR = pin; }

uint8_t GPIO_readInputDataBit(GPIO_StructTypedef *gpioN, uint16_t pin) { return (gpioN->IDR & pin) ? 1 : 0; }

uint8_t GPIO_readOutputDataBit(GPIO_StructTypedef *gpioN, uint16_t pin) { return (gpioN->ODR & pin) ? 1 : 0; }

uint16_t GPIO_readInputData(GPIO_StructTypedef *gpioN) { return (uint16_t)gpioN->IDR; }

uint16_t GPIO_readOutputData(GPIO_StructTypedef *gpioN) { return (uint16_t)gpioN->ODR; }

void GPIO_LOCK(GPIO_StructTypedef *gpioN, uint16_t pin, FunctionalState s)
{
    gpioN->LCKR &= ~(uint32_t)(0x0100);
    if (!(gpioN->LCKR & 0x0100))
    {
        if (s)
            gpioN->LCKR |= pin;
        else
            gpioN->LCKR &= ~(uint32_t)pin;
    }
    gpioN->LCKR |= (uint32_t)(0x0100);
}

void GPIO_AF_Config(GPIO_StructTypedef *gpioN, uint8_t pinSource, uint8_t af)
{
    uint64_t *afr = (uint64_t *)(uint32_t) & (gpioN->AFRL);
    uint64_t mask;
    pinSource *= 4;
    mask = 0x0f;
    mask <<= pinSource;
    *afr &= ~mask;
    mask = af;
    mask <<= pinSource;
    *afr |= mask;
}

void GPIO_WriteBit(GPIO_StructTypedef *gpioN, uint16_t pin, uint8_t pinVal)
{
    if (pinVal)
        gpioN->BSRR = pin;
    else
        gpioN->BRR = pin;
}

void GPIO_Write(GPIO_StructTypedef *gpioN, uint16_t portVal) { gpioN->ODR = portVal; }
