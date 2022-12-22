# RCC、系统时钟树和外设

## 时钟树

## RCC寄存器

### 总览

| 偏移量 | 名称 | 描述|
| :----: | :--: | :------------------------------------------ |
|0x0|[CR](#时钟控制寄存器rcc_cr)|时钟控制|
|0x4|CFG|时钟配置|
|0x8|CIR|时钟中断|
|0xc|APB2rst|APB2 外设复位|
|0x10|APB1rst|APB1 外设复位|
|0x14|AHB_EN|AHB 外设时钟使能|
|0x18|APB2EN|APB2 外设时钟使能|
|0x1c|APB1EN|APB1 外设时钟使能|
|0x20|BDC|备份域控制|
|0x24|CSR|控制状态|
|0x28|AHB_RST|AHB 外设复位|
|0x2c-0x3c||无作用，保留|
|0x40|SYS_CFG|系统配置|
|0x44|HSI_DLY|HSI 延迟|
|0x48|HSE_DLY|HSE 延迟|

### 寄存器描述

#### 时钟控制寄存器(RCC_CR)

地址偏移：0x00
复位值：0x0000 XX03

<table>
    <tr>
        <th>31</th><th>30</th><th>29</th><th>28</th><th>27</th><th>26</th><th>25</th><th>24</th><th>23</th><th>22</th><th>21</th><th>20</th><th>19</th><th>18</th><th>17</th><th>16</th>
    </tr>
    <tr align="center">
        <td colspan="6">PLL_MUL</td><td>PLL_RDY</td><td>PLL_ON</td><td>Res.</td><td colspan="3">PLL_DIV</td><td>CSS_ON</td><td>HSE_BYP</td><td>HSE_RDY</td><td>HSE_ON</td>
    </tr>
    <tr align="center">
        <td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td>
        <td>r</td><td>rw</td><td></td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>rw</td><td>r</td><td>rw</td>
    </tr>
</table>

<table>
    <tr>
        <th>15</th><th>14</th><th>13</th><th>12</th><th>11</th><th>10</th><th>9</th><th>8</th><th>7</th><th>6</th><th>5</th><th>4</th><th>3</th><th>2</th><th>1</th><th>0</th>
    </tr>
    <tr align="center">
        <td colspan="2">Res.</td><td colspan="6">HSI_CAL</td><td colspan="5">Res.</td><td>HSI_TEN</td><td>HSI_RDY</td><td>HSI_ON</td>
    </tr>
    <tr align="center">
        <td></td><td></td><td>r</td><td>r</td><td>r</td><td>r</td><td>r</td><td>r</td>
        <td></td><td></td><td></td><td></td><td></td>
        <td>rw</td><td>r</td><td>rw</td>
    </tr>
</table>
