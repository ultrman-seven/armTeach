#include "stdio.h"
#include "stdint.h"

int main(int argc, char const *argv[])
{
    uint16_t dat[] = {0xfeab, 0x1234, 0x9876};
    uint32_t d0 = *(uint32_t *)(dat + 1);

    printf("d0 = 0x%x\n", d0);
}
