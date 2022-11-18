#include "stdio.h"
#include "stdint.h"

typedef enum
{
    m1=2,
    m2,
    m3,
    m4,
    m5
} GPIO_Mode;

int main(int argc, char const *argv[])
{
    printf("%d\n", m1);
    printf("%d\n", m2);
    printf("%d\n", m3);
    printf("%d\n", m4);
    printf("%d\n", m5);
}