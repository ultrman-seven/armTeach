# GPIO

## GPIO 的输出方式

有个外围电路去驱动负载

1. 推挽输出
2. 开漏输出
3. 如果 GPIO

## GPIO 的输入方式

1. 输入数字量
2. 输入模拟量

## GPIO 寄存器解读

# HAL 库

Hardware Abstract Layer
硬件抽象层库

> C 语言
>
> 头文件书写

GPIO 初始化配置 CR 寄存器，有如下几种状态：

| CFG | MODE | 工作方式                             | 名称 |
| --- | ---- | ------------------------------------ | ---- |
| 00  | 00   | <font color=red>模拟输入</font>      |      |
| 00  | 01   | <font color=blue>通用推挽输出</font> |      |
| 00  | 10   | 保留                                 |      |
| 00  | 11   | 保留                                 |      |
| 01  | 00   | <font color=red>浮空输入</font>      |      |
| 01  | 01   | <font color=blue>通用开漏输出</font> |      |
| 01  | 10   | 保留                                 |      |
| 01  | 11   | 保留                                 |      |
| 10  | 00   | <font color=red>上下拉输入</font>    |      |
| 10  | 01   | <font color=blue>复用推挽输出</font> |      |
| 10  | 10   | 保留                                 |      |
| 10  | 11   | 保留                                 |      |
| 11  | 00   | 保留                                 |      |
| 11  | 01   | <font color=blue>复用开漏输出</font> |      |
| 11  | 10   | 保留                                 |      |
| 11  | 11   | 保留                                 |      |
