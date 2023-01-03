#include "stdint.h"

typedef struct
{
    uint32_t CR;
    uint32_t CFG;
    uint32_t CIR;
    uint32_t APB2rst;
    uint32_t APB1rst;
    uint32_t AHB_EN;
    uint32_t APB2EN;
    uint32_t APB1EN;
    uint32_t BDC;
    uint32_t CSR;
    uint32_t AHB_RST;
    uint32_t __RESERVED[5];
    uint32_t SYS_CFG;
    uint32_t HSI_DLY;
    uint32_t HSE_DLY;
}RCC_StructTypedef;
