#include "stdio.h"
#include "stdint.h"

typedef union
{
    uint64_t u64Dat;
    uint32_t u32Dat;
    uint16_t u16Dat;
    uint16_t u16Unit[8];
    uint8_t u8Unit[8];
} tmpUnionDef;

int main(int argc, char const *argv[])
{
    tmpUnionDef tmp;
    uint64_t tmpAdd, d0Add, d1Add, d2Add, d3Add;
    uint64_t num;
    uint8_t *p;

    tmpAdd = (uint64_t)&tmp;

    d0Add = (uint64_t) & (tmp.u64Dat);
    d1Add = (uint64_t) & (tmp.u32Dat);
    d2Add = (uint64_t) & (tmp.u16Dat);
    d3Add = (uint64_t)tmp.u16Unit;

    printf("tmp:0x%x\n", *(uint32_t *)&tmpAdd);
    printf("d0:0x%x\n", *(uint32_t *)&d0Add);
    printf("d1:0x%x\n", *(uint32_t *)&d1Add);
    printf("d2:0x%x\n", *(uint32_t *)&d2Add);
    printf("d3:0x%x\n", *(uint32_t *)&d3Add);

    tmp.u64Dat = 0x123456789abcdef;
    num = tmp.u64Dat;
    p = (uint8_t *)&num;

    printf("u32=0x%x\n", tmp.u32Dat);
    printf("u16=0x%x\n", tmp.u16Dat);
    printf("u8 1:0x%x\n", tmp.u8Unit[1]);
    printf("u8 1:0x%x", p[1]);
}
