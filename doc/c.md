# C语言简单复习

## 指针

1. 指针是如何被储存的

## 位运算

- 问题

1. 移位与乘除法的等效
   怎么优化以下代码，以提高运算速度？

   ```c
    uint8_t remainder;
    uint8_t quotient;

    remainder = 103 % 2;
    quotient = 103 / 2;
   ```
2. 整数平方根

## 宏定义

C语言中宏定义的使用

1. 啥都不带
2. 直接替换
3. 带参数的宏定义

   1. 直接替换参数
   2. 使用 `#`连接参数
   3. 使用 `##`连接参数

## 条件编译指令

条件编译指令的逻辑与C语言中的 `if--else`逻辑基本相同。例如：

```C
#if A //A是一个常量表达式
a = b;
#elif B//B也是一个常量表达式
a = c;
#else
a = d;
#endif
```

其中，关于常量表达式，他可以是以下的形式。

1. 立即数
   如 `1`、`0`、`0x1f`，只要是非0值就会被判为真值
2. 由宏定义的立即数
   如下面的例子

   ```C
   #define __USE_PLAN_A 1

   #if __USE_PLAN_A
   a = planA();
   #else
   a = planB();
   #endif
   ```

   效果同上
3. 宏定义相关
   `defined` 用于判断有没有定义过某个宏，例如：

   ```C
   #define __PLAN_A_

   #if defined __PLAN_A_
   int planA(void)
   {
      //code
   }
   #endif
   ```
4. 运算表达式
   常量表达式中可以使用逻辑运算符对上述几种形式的值进行运算，如“或 `||`”、“与 `&&`”、“非 `!`”等。

   注意这里的逻辑运算**不是按位逻辑**“按位或 `|`”、“按位与 `&`”、“按位取反 `~`”。
5. 其他语句
   `#if`和 `defined`可以组合成 `#ifdef`
   `#if`和 `!defined`可以组合成 `#ifndef`

条件编译指令既可以放在函数外，控制一些全局变量的设定，也可以放在函数内，灵活调整函数内容。

## 头文件

头文件使用[条件编译指令](#条件编译指令)来防止一个头文件被反复多次包含。之所以要防止这一动作，是因为头文件中可能会定义变量这样的只能进行一次的操作，重复包含之后变量就被重复定义了。具体格式如下：

```C
#ifndef __XX_HEADER_H_
#define __XX_HEADER_H_

#include "header1youNeed.h"
#include "header2youNeed.h"

int variable1thatYouDefine = 0x23;
int variable2thatYouDefine = 0xff;

extern int v1;
extern int v2;

void yourFunction1(void);
void yourFunction2(int a, const char *p);
//and so on...
#endif
```
