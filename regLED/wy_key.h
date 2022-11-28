#ifndef BEAF1338_BCAA_4CDE_BB91_A8527C4CD144
#define BEAF1338_BCAA_4CDE_BB91_A8527C4CD144
#include "wy_gpio.h"
typedef enum
{
    keyIPU, keyIPD
}
KEY_Mode;

typedef struct 
{
    uint8_t flag;
    GPIO_StructTypedef *gpioN;
    uint16_t pin;
    void (*callback)(void);
    KEY_Mode m;
}KeyStructTypedef;
void keyIPU_DetAndRun(GPIO_StructTypedef *gpioN, uint16_t pin, void (*callback)(void));
void key_Init(KeyStructTypedef *key);
void key_DetAndRunByFlag(KeyStructTypedef *key);
#endif /* BEAF1338_BCAA_4CDE_BB91_A8527C4CD144 */
