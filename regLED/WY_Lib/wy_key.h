#ifndef __WY_KEY_H__
#define __WY_KEY_H__
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
void key_StructInit(KeyStructTypedef *key,const char * p, KEY_Mode m,void (*callback)(void));
void key_DetAndRunByFlag(KeyStructTypedef *key);
#endif /* __WY_KEY_H__ */
