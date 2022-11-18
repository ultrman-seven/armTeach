#include "stdint.h"
#include "wy_gpio.h"

int main()
{
    GPIO_InitStructTypedef g;
    *(uint32_t *)(0x40021000 + 0x14) |= (1 << 19);

    g.pin = GPIO_Pin7 | GPIO_Pin6 | GPIO_Pin8;
    g.mode = GPIO_Mode_pull_push;
    g.speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &g);

    GPIO_Setbit(GPIOC, GPIO_Pin7 | GPIO_Pin8| GPIO_Pin6);
    //GPIO_Resetbit(GPIOC, GPIO_Pin6);

    while (1)
    {
    }
}

void SystemInit()
{
}
