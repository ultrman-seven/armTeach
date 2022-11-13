# 指针（地址）与数据存储

## C语言中创建变量的过程

在下列程序中

```C
#include "stdio.h"

int main(int argc, char const *argv[])
{
    int a;
    a = 100;

    printf("a = %d", a);
    return 0;
}

```

程序运行经过的流程：

## 指针

数CPU的不同位，代表寻址的能力
-----------------------------

| CPU位数/bit | 地址位数 | 举例                  | 寻址范围    |
| ----------- | -------- | --------------------- | ----------- |
| 8           | 8        | 0x23                  | 0~255 bit   |
| 32          | 32       | 0x4008 8238           | 0~4G        |
| 64          | 64       | 0x4008 8238 2300 ffff | 0~16777216T |

```c
#include "stdio.h"

int main(int argc, char const *argv[])
{
    int a;
    int *b;
    unsigned long long c, address;
    unsigned int d;

    a = 100;
    b = &a;

    c = (unsigned long long)b;
    d = (unsigned int)(c & 0x0000ffff);

    printf("a = %d\n", a);
    *b = 200;
    printf("a = %d\n", a);
    *(int *)c = 300;
    printf("a = %d\n", a);
    address = c;
    *(int *)address = 400;
    printf("a = %d\n", a);

    // printf("b = %d\n", a);
    printf("last 4 bytes of c = 0x%x\n", d);
    return 0;
}
```

## 数组与地址

```c
#include "stdio.h"

int main(int argc, char const *argv[])
{
    int a[10];
    unsigned long long c, address;
    unsigned int d;

    c = (unsigned long long)a;
    d = (unsigned int)c & 0xffff;
    printf("last 4 bytes of a0 = 0x%x\n", d);

    c = (unsigned long long)(&a[1]);
    d = (unsigned int)c & 0xffff;
    printf("last 4 bytes of a1 = 0x%x\n", d);

    c = (unsigned long long)(a+1);
    // c = c + 1;
    d = (unsigned int)c & 0xffff;
    printf("last 4 bytes of a1 = 0x%x\n", d);
    return 0;
}

```

> C 语言
>
> [宏定义](./c.md#def "点击查看详情")
>
> #define def(n) a##n
>
> def(AB) --> aAB
>
> #define def(n) #n
>
> def(AB) --> "AB"

```c
#include "stdio.h"

#define GET_SIZE(__typeName) \
    __typeName a_##__typeName[10];        \
    printf("size of %s is :%d\n", #__typeName, (unsigned long long)(a##__typeName + 1) - (unsigned long long)a##__typeName)



int main(int argc, char const *argv[])
{
    GET_SIZE(float);
    GET_SIZE(int);
    GET_SIZE(short);
    GET_SIZE(char);
    GET_SIZE(double);
    GET_SIZE(long);
}
```

## 不同平台下

# 单片机

# 思考问题

1. 在 STM32 中，`uint8_t *`、`double *`和 `uint16_t **`所占用储存单元的大小分别是：
2. 给 32 位 CPU 的电脑插上 8G 的内存条，结果是：

   A. 擦电开机轻松秒杀

   B. 进不去系统

   C. 可以进系统，但是内存条只能用一半

   D. 午安大电流
3. 以下程序的运行结果是：(运行环境：Core i5(64bit)，Windows10)

   ```C
   #include "stdio.h"
   #include "stdint.h"

    int main(int argc, char const _argv[])
    {
        uint32_t dat = 0x12345678;
        uint64_t dat_add = (uint64_t)&dat;
        uint16_t d0 = _(uint16_t _)dat_add;
        uint8_t d1 = _(uint8_t _)dat_add;
        uint8_t d2 = _(uint8_t \*)(dat_add + 4);

            printf("d0 = 0x%x\n", d0);
            printf("d1 = 0x%x\n", d1);
            printf("d2 = 0x%x\n", d2);

    }
   ```
4. 以下程序的运行结果是：(运行环境：MM32f3277(32bit arm cpu))

   ```C
   #include "stdio.h"
   #include "stdint.h"

   int main(int argc, char const *argv[])
   {
       uint32_t dat;
       uint32_t dat_add = (uint32_t)&dat;
       uint16_t *d0;
       uint8_t *d1, *d2;

       d1 = (uint8_t *)dat;
       d2 = (uint8_t *)(dat + 3);
       d0 = (uint16_t *)(dat + 1);

       *d0 = 0xfe;
       *d1 = 0x12;
       *d2 = 0x56;

       printf("dat = 0x%x\n", dat);
   }
   ```
5. 以下程序的运行结果是：(运行环境：MM32f3277(32bit arm cpu))

   ```C
   #include "stdio.h"
   #include "stdint.h"

   int main(int argc, char const *argv[])
   {
       uint16_t dat[] = {0xfeab, 0x1234, 0x9876};
       uint32_t d0 = *(uint32_t *)(dat + 1);

       printf("d0 = 0x%x\n", d0);
   }
   ```
6. 以下程序的运行结果是：(运行环境：Core i5(64bit)，Windows10)

   ```C
   #include "stdio.h"
   #include "stdint.h"

   int main(int argc, char const *argv[])
   {
       uint32_t dat;
       uint64_t dat_add = (uint64_t)&dat;
       uint16_t *d0;
       uint8_t *d1;
       int8_t *d2;

       d1 = (uint8_t *)dat;
       d2 = (uint8_t *)(dat + 3);
       d0 = (uint16_t *)(dat + 1);

       *d0 = 0xfe;
       *d1 = 0x12;
       *d2 = -1;

       printf("dat = 0x%x\n", dat);
   }
   ```
7. 对照stm32f103手册，写程序使PB5和PB1输出高电平
