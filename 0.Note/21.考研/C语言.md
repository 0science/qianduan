[TOC]

# 一、概述

## 1.程序语言

| 程序语言 | 特点                                                 | 举例                      |
| -------- | ---------------------------------------------------- | ------------------------- |
| 机器语言 | 低级语言，0和1组成的二进制代码，计算机直接识别。     | 如：`10110000 01100001`   |
| 汇编语言 | 面向机器的程序设计语言，用英文和字符代替二进制代码。 | 如：`MOV AL, 61h`         |
| 高级语言 | 语法类似英文，贴近自然语言。                         | 如：C语言、Python、Java等 |
## 2.特点
| 优点       | 缺点           |
| ---------- | -------------- |
| 代码量小   | 代码实现周期长 |
| 运行速度快 | 平台库依赖较多 |
| 功能丰富   |                |

## 3.应用
+ 嵌入式
+ web开发
+ 高性能服务
+ 分布式应用
+ 游戏服务器
+ 游戏引擎
+ 游戏脚本
+ 移动开发
+ 桌面开发
+ 操作系统
+ 虚拟技术
+ 数据库
+ 编译器



## 4.集成开发环境


集成开发环境（IDE，Integrated Development Environment ）是用于提供程序开发环境的应用程序，一般包括代码编辑器、编译器、调试器和图形用户界面工具。集成了代码编写功能、分析功能、编译功能、调试功能等一体化的开发软件服务套。所有具备这一特性的软件或者软件套（组）都可以叫集成开发环境。

## 5.第一个C程序


### 5.1 hello.c


```
#include<stdio.h>            /*包含头文件stdio.h*/
int main()                   /*主函数main*/              
{
	printf("Hello World!");  /*显示输出字符串*/
	return 0;                /*程序返回0*/     
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306291339100.png)



### 5.2 calculate.c


```
#include <stdio.h>                         /*包含头文件stdio.h*/
#define Height 10                          /*定义常量Height*/
int calculate(int Long, int Width);        /*用户自定义函数calculate声明*/
int main()                                 /*主函数main*/
{
    int m_Long;                            /*定义整型变量m_Long,表示长度*/
    int m_Width;                           /*定义整型变量m Width,表示宽度*/
    int result;                            /*定义整型变量result,表示体积*/
    printf("长方形的高度为：%d\n", Height); /*产显示提示*/
    printf("请输入长度\n");                 /*显示提示*/
    scanf("%d", &m_Long);                  /*输入长方体的长度*/
    printf("请输入宽度\n");                 /*显示提示*/
    scanf("%d", &m_Width);                 /*输入长方体的宽度*/
    result = calculate(m_Long, m_Width);   /*调用calculate函数，计算体积*/
    printf("长方体的体积是：");             /*显示提示*/
    printf("%d\n", result);                /*输出体积大小*/
    return 0;                              /*程序返回0*/
}
int calculate(int Long, int Width)         /*自定义计算体积函数calculate*/
{
    int result = Long * Width * Height;    /*计算体积*/
    return result;                         /*将计算的体积结果返回*/
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306291423261.png)  
![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306291434563.png)



### 5.3 代码分析
| 代码              | 含义                                                                               |
| ----------------- | ---------------------------------------------------------------------------------- |
| #include<stido.h> | 包含stdio.h这个头文件                                                              |
| main()函数        | 主函数，有且只有一个，是C语言程序的入口，程序是从main函数开始执行，                |
| {}                | 代码块，一个代码块内部可以有一条或者多条语句，每句以分号结尾                       |
| //     /**/       | 行注释与块注释，编译器忽视的内容，用于解释说明代码内容                             |
| printf函数        | C语言库函数，功能是向标准输出设备输出一个字符串                                    |
| \n                | 回车换行                                                                           |
| return语句        | 代表函数执行完毕，返回return代表函数的终止，0代表程序执行成功， -1代表程序执行失败 |
| system函数        | 在已经运行的程序中执行另外一个外部程序                                             |




## 6.编译过程


### 6.1 编译步骤


C代码编译成可执行程序经过4步：



1.**预处理**：宏定义展开、头文件展开、条件编译等，同时将代码中的注释删除，这里并不会检查语法
2.**编译**：检查语法，将预处理后文件编译生成汇编文件
3.**汇编**：将汇编文件生成目标文件(二进制文件)
4.**链接**：C语言写的程序是需要依赖各种库的，所以编译之后还需要把库链接到最终的可执行程序中去  

### 6.2 编译指令

**GCC命令**  
预处理：gcc -E hello.c -o hello.i  
编  译：gcc -S hello.i -o hello.s  
汇  编：gcc -c hello.s -o hello.o  
链  接：gcc hello.o -o hello  
一步编译：gcc hello.c -o hello

| 选项    | 含义                       |
| ------- | -------------------------- |
| -u file | 指定生成的输出文件名为file |
| -E      | 只进行预处理               |
| -S      | 只进行预处理和编译         |
| -c      | 只进行预处理、编译和汇编   |


| 文件后缀 | 含义                  |
| -------- | --------------------- |
| .c       | C 语言文件            |
| .i       | 预处理后的 C 语言文件 |
| .s       | 编译后的汇编文件      |
| .o       | 编译后的目标文件      |

# 二、数据类型


### 1.标识符

**标识符**：程序员在程序中给函数、变量等起名字就是标识符

+ 只能由字母(a~z、 A~Z)、数字、下划线组成
+ 不能包含除下划线以外的其它特殊字符串
+ 不能以数字开头
+ 不能是C语言中的关键字
+ 严格区分大小写

### 2.关键字

**关键字**：指一些被C语言赋予了特殊含义的单词

+ 全部都是小写
+ 在开发工具中会显示特殊颜色
+ 不能用作变量名、函数名等

## 3.数据类型

**构造类型**：使用基本类型或已构造好的数据类型，进行添加，设计，构造出新的数据类型

**指针类型**：值为内存地址

**空类型**：关键字void，对函数的返回和参数限定

![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306300914163.png)



## 4.常量


**常量**：值在程序运行过程中不可改变的量，分为数值型常量、字符型常量、符号常量



### 4.1 整型常量


**整型常量**：直接使用的整型常数，分为长整型、短整型、符号整型和无符号整形

| 整型常量     | 所需类型                   |
| ------------ | -------------------------- |
| 10           | 代表int类型                |
| 10l, 10L     | 代表long类型               |
| 10ll, 10LL   | 代表long long类型          |
| 10u, 10U     | 代表unsigned int类型       |
| 10ul, 10UL   | 代表unsigned long类型      |
| 10ull, 10ULL | 代表unsigned long long类型 |

八进制：以0开头，包含数字0~7  
十进制：无前缀，包含数字0~9  
十六进制：以0x开头，包含数字0<sub>9和字母a</sub>f（不区分大小写）

### 4.2 浮点型常量


**浮点型**：由整数部分和小数部分组成，分为单精度浮点数(F结尾)，双精度浮点数



科学计数法：十进制小数方法



指数方式：以幂的形式表示, 以字母e或字母E后跟一个10为底的幂数



+ 字母e或字母E后面的指数必须为整数
+ 字母e或字母E前后必须要有数字
+ 字母e或字母E前后不能有空格



```
SciNum = 123.45            //科学计数法 
SciNum = 1.2345e2          //指数方式
FloatNum = 1.2345e2F       //单精度
LongDoubleNum =123.45e-1L  //长双精度   
DoubleNum = 1234.5e2       //双精度
```



> 后缀大小写通用
>



### 4.3 字符型常量


字符型常量分为字符常量、字符串常量



**字符常量**：单引号内加一个字符



**字符串常量**：双引号内加多个字符



> 系统会在字符串结尾加上\0，所以字符串长度会加1
>



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301447568.png)



### 4.4 转义字符


![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301445634.png)



### 4.5 符号常量


**符号常量**：用符号名代替固定的常量值



```
#include<stdio.h>
#define Pai 3.14
int main()
{
	double fRadius;
	double fResult=0;
	printf("请输入圆的半径：");
	scanf("%lf",&fRadius);
	fResult=fRadius*fRadius*Pai;
	printf("圆的面积为：%lf\n",fResult);
	return 0; 
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301500979.png)



## 5.变量


### 5.1 整型变量


**整型变量**：存储整型数值的变量

| 名称           | 数据类型       | 占用空间 | 取值范围               |
| -------------- | -------------- | -------- | ---------------------- |
| 有符号短整型   | short          | 2Byte    | -32768~32767           |
| 有符号基本整型 | int            | 4Byte    | -2147483648~2147483647 |
| 有符号长整型   | long           | 4Byte    | -2147483648~2147483647 |
| 有符号短整型   | unsigned short | 2Byte    | 0~65535                |
| 无符号基本整型 | unsigned int   | 4Byte    | 0~4294967295           |
| 无符号长整型   | unsigned long  | 4Byte    | 0~4294967295           |




```
int Num1 = 1;                 //定义有符号基本整型
unsigned Num2 = 2;            //定义无符号基本整型
short Num3 = 3;               //定义有符号短整型
unsigned short Num4 = 4;      //定义无符号短整型
long Num5 = 5;                //定义有符号长整型
unsigned long Num6 = 6;       //定义无符号长整型
```



### 5.2 浮点型变量


**浮点型变量**：存储浮点型数值的变量

| 名称         | 数据类型    | 占用空间 | 取值范围 |
| ------------ | ----------- | -------- | -------- |
| 单精度类型   | float       | 4Byte    |          |
| 双精度类型   | double      | 8Byte    |          |
| 长双精度类型 | long double | 8Byte    |          |




```
float Num1 = 1.23f;           
double Num2 = 1.23;
long double Num3 = 1.23;
```



### 5.3 字符型变量


**字符型变量**：将一个字符常量存储到一个字符变量中



```
char a1='a'      
char a2=97;
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301550896.png)



## 6.变量的存储类别


### 6.1 静态存储与动态存储


**静态存储**：程序运行时为其分配固定的存储空间  
**动态存储**：程序运行时根据需要动态分配空间



### 6.2 auto变量


**auto**：动态变量，定义一个局部变量为自动



```
#include<stdio.h>
void AddOne()
{
    auto int i = 1;
    i = i+1;
    printf("%d\n",i);
}
int main()
{
    printf("第一次调用：");
    AddOne();
    printf("第二次调用：");
    AddOne();
    return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301615232.png)



### 6.3 staticus变量


**static**：静态变量



```
#include<stdio.h>
void AddOne()
{
    static int i = 1;
    i = i+1;
    printf("%d\n",i);
}
int main()
{
    printf("第一次调用：");
    AddOne();
    printf("第二次调用：");
    AddOne();
    return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301639265.png)



### 6.4 register变量


**register**：寄存器存储类变量，把局部变量指定存放在寄存器中，而不是内存中



```
#include<stdio.h>
int main()
{
	register int i;
	i=100;
	printf("%d",i);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301653143.png)



### 6.5 extern变量


**extern**：外部存储变量



```
//文件1
#include<stdio.h>
int main()
{
	extern int i;
	printf("%d\n",i);
	return 0;
}
```



```
//文件2
#include<stdio.h>
int i = 100;
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301652346.png)



## 7.混合运算


不同类型之间进行混合运算，要先转换为同一类型



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301657086.png)



```
#include<stdio.h>
int main()
{
	int a = 1;
	char b = 'A';
	float c = 2.5f;
	double result = a+b+c;
	printf("%f",result);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301926190.png)



# 三、运算符与表达式


## 1.表达式


表达式由操作符和操作数组成，表达式只返回结果值



## 2.赋值运算符（=）


**赋值表达式**  
`类型 变量名 = 常数/表达式`



> 数据大小超过数值类型的取值范围时会发生截断
>



**强制类型转换**



```
#include<stdio.h>
int main()
{
	float i = 10.1f;
	int j = (int)i;         //强制类型转换 
	printf("%d",j);            
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306301956847.png)



## 3.算术运算符


**分类**



算数运算符包括单目运算符、双目运算符  
单目运算符包括正、负  
双目运算符包括乘、除、取模、加、减



```
//华氏度转摄氏度
#include<stdio.h>
int main()
{
	int Celsius,Fahrenheit;
	printf("请输入华氏度：");
	scanf("%d",&Fahrenheit);
	Celsius =5*(Fahrenheit-32)/9;
	printf("摄氏度是：%d",Celsius);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306302011487.png)



**优先级**



+ 先乘除取余，后加减，括号优先
+ 优先级相同，从左到右依次计算



**自增/自减运算符**



```
#include<stdio.h>
int main()
{
	int i = 3;
	int j = 3;
	int  A,B,C,D;
	A = ++i;           //先加1，再赋值 
	B = j++;           //先赋值，再加1，下次用 
	printf("A自增后的值为%d\n自增后的表达式值为%d\n",i,A);
	printf("B自增后的值为%d\n自增后的表达式值为%d\n",j,B);
	i = 3; 
	j = 3;
	C = --i;
	D = j--;
	printf("C自减后的值为%d\n自减后的表达式值为%d\n",i,C);
	printf("D自减后的值为%d\n自减后的表达式值为%d",j,D);
	return 0; 
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307010913015.png)



## 4.关系运算符
| 符号 | 功能     |
| ---- | -------- |
| >    | 大于     |
| <    | 小于     |
| >=   | 大于等于 |
| <=   | 小于等于 |
| ==   | 等于     |
| !=   | 不等于   |




```
//比较成绩大小
#include<stdio.h>
int main() 
{
	int i = 0;
	for(i=0;i<3;i++){
	int Chinese,English;
	printf("请输入语文成绩：",Chinese);
	scanf("%d",&Chinese);
	printf("请输入英语成绩：",English);
	scanf("%d",&English);
	if(Chinese>English)
	{
		printf("语文成绩更高！\n");
	}
	if(Chinese<English)
	{
		printf("英语成绩更高！\n");
	}
	if(Chinese==English)
	{
		printf("成绩相同！\n");
	}
}
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307010929526.png)



## 5.逻辑运算符
| 符号 | 功能   |
| ---- | ------ |
| &&   | 逻辑与 |
|      |        |  | 逻辑或 |
| !    | 逻辑非 |




```
#include<stdio.h>
int main()
{
	int i=1;
	int j=10;
	printf("1为正确，0为错误！\n");
	printf("5<i与j是%d\n",5<i&&j);
	printf("5<i或j是%d\n",5<i||j);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307010957203.png)



## 6.位逻辑运算符


**位逻辑运算符**可以实现位的设置、清零、取反、取补操作  
位逻辑运算符一般用作开关的标志

| 符号 | 功能     |
| ---- | -------- |
| &    | 位逻辑与 |
|      |          | 位逻辑或 |
| ^    | 位逻辑非 |
| ~    | 取补     |




## 7.逗号运算符（,）


逗号将多个表达式分隔开来



## 8.复合赋值运算符


复合运算符是C语言独有的，是一种缩写形式



```
Value = Value +3;        //常规写法
Value += 3;              //缩写形式
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011012546.png)



# 四、程序结构


## 1.输入/输出函数


### 1.1 字符输出（putchar）


**putchar函数**：向显示设备输出一个字符



`int putchar(int ch);`



```
#include<stdio.h>
int main()
{
	char a,b,c,d;
	a = 'H';
	b = 'e';
	c = 'l';
	d = 'o';
	putchar(a);
	putchar(b);
	putchar(c);
	putchar(c);
	putchar(d);
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011128597.png)



### 1.2 字符输入（getchar）


**getchar**：从输入设备中输入一个字符



`int getchar()`



```
#include<stdio.h>
int main()
{
	char a;
	a = getchar();
	putchar(a);
	putchar('\n');
	getchar();          //获取回车字符 
	putchar(getchar());
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011344105.png)



### 1.3 字符串输出（puts）


**字符串输出**：输出一个字符串到屏幕上



`int puts(char *str)`



```
#include<stdio.h>
int main()
{
	char *a = "I Love You!";    //定义字符串指针 
	puts("I Love You!");        //第一次输出 
	puts(a);                    //第二次输出 
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011355900.png)



### 1.4 字符串输入（gets）


**字符串输入**：将读取的字符保存在形式参数中



`gets()`



```
#include<stdio.h>
int main()
{
	char a[30];         //定义一个数组 
	gets(a);            //获取字符串 
	puts(a);            //输出字符串 
	return 0;           
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011402016.png)



### 1.5 格式输出函数（printf）


**printf函数**：输出若干任意类型的数据  
**格式控制**：将输出的数据转换为指定格式  
**输出列表**：需要输出的数据



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011414309.png)



> printf("%3.2f",num);   //保留三位数，两位是小数
>



`print(格式控制 输出列表)`



```
#include<stdio.h>
int main()
{
	int i = 10;
	float j = 1.23f;
	printf("%d\n",i);
	printf("%f\n",j);
	printf("%s","hello world");
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011422797.png)



**附加格式**



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011424875.png)



> 字母l，整数m、n
>



### 1.6 格式输入函数（scanf）


**scanf函数**：接收输入的数据



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011429202.png)



`scanf(格式控制 地址控制)`



**附加格式**![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011432192.png)



### 1.7 实例


```
//计算圆的面积
#include<stdio.h>
int main()
{
	float Pai = 3.14f;
	float Area,Radius;             //定义面积，半径 
	puts("请输入圆的半径：");
	scanf("%f",&Radius);
	Area = Radius*Radius*Pai;      //面积公式 
	printf("圆的面积为：%f",Area);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011438685.png)



```
//大写字母转小写字母
#include<stdio.h>
int main()
{
	char Big,Small;
	puts("请输入大写字母：");
	Big = getchar();
	puts("小写字母为：");
	Small = Big +32;
	printf("%c\n",Small);
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011443074.png)



## 2.if语句


**if**：通过对表达式进行判断，根据结果决定是否进行相应操作



`if(表达式) 语句`



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011506765.png)



## 3.if ...else语句


**if...else**：可以在条件为假时，执行另一段代码



```
if(表达式)
	语句1;
else
	语句2；
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011527184.png)



> esle语句必须跟在if语句后面
>



## 4.else if语句


```
if(表达式1) 语句1
else if(表达式2) 语句2
else if(表达式3) 语句3
else 语句4
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011519163.png)



**条件运算符**



```
if(a>b)
	{max=a;}
else(a<b)
	{max=b;}
```



以上代码可以用？来简化  
`max=(a>b)?a:b;`



```
//计算欠款
#include<stdio.h>
int main()
{
	float Due,Amount;
	int Ontime;
	char a;
	printf("请输入欠款金额：");
	scanf("%f",&Due);
	printf("是否及时还款?(y/n)");
	getchar();
	a = getchar();
	Ontime = (a=='y')?1:0;               //选择操作 
	Amount = Ontime?Due:(Due*1.1);
	printf("待还：%.2f",Amount);         //保留两位小数 
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011648375.png)



## 5.switch语句


**switch**：多分支选择语句



```
switch(表达式)
{
	case 情况1;
	case 情况2;
	case 情况3;
	default:默认情况
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011650831.png)



> case无匹配则执行defult，只能又有一个defult语句，每个case和defult后都要有break关键字跳出循环  
3个分支用if...else，3个以上用switch
>



```
//输出分数段
#include<stdio.h>
int main()
{
	char Grade;
	printf("请输入你的成绩：");
	scanf("%c",&Grade);
	printf("成绩区间为：");
	switch(Grade)
	{
		case'A':
			printf("90~100");
			break;
		case'B':
			printf("80~89");
			break;
		case'C':
			printf("70~79");
			break;
		case'D':
			printf("60~69");
			break;
		case'E':
			printf("<60"); 
			break;
	 } 
	 return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307011710626.png)



## 6.while语句


**while**：满足条件则循环执行语句，直到不满足条件时则退出循环



`while(表达式) 语句`



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307020941122.png)



```
//从1加到100
#include<stdio.h>
int main()
{
	int Sum= 0;
	int Number = 1;
	while(Number<=100)
	{
		Sum = Number+Sum;
		Number++;
	}
	printf("%d",Sum);
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021020668.png)



## 7./do while语句


**do...while**：无论是否满足条件，先执行一次，后面同while



```
do
	循环语句
while(表达式)；
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021026068.png)



```
#include<stdio.h>
int main()
{
	int Sum = 0;
	int Number = 1;
	do
	{
		Sum = Number + Sum;
		Number++;
	} while (Number <= 100);
	printf("%d",Sum);
	return 0;
}
```

![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021034922.png)

## 8.for语句


`for(表达式1;表达式2;表达式3;)`



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021036147.png)



```
//显示随机数
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int counter;
	for(counter=0;counter<10;counter++)
	{
		srand(counter+1);
		printf("随机数%d为：%d\n",counter,rand());
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021052454.png)



## 9.goto语句


**goto**：无条件转移语句，使程序立即跳转到函数内任意一条可执行语句



`goto 标识符`



```
#include<stdio.h>
int main()
{
	int Step,Select;
	for(Step=0;Step<10;Step++)
	{
		printf("步骤：%d\n",Step);
		do
		{
			printf("输入一个数字进行选择：");
			scanf("%d",&Select);
			printf("（按0退出，99进入下一步）\n");
			
			if(Select==0)
			{
				goto exit;
			 } 
		}
		while(Select!=99);
	}
	exit:
		printf("退出程序！\n");
		return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021344811.png)



## 10.break语句


**break**：强制终止并跳出循环；



```
#include<stdio.h>
int main()
{
	int Count;
	for(Count=0;Count<10;Count++)
	{
		if(Count==5)
		{
			printf("在这里停止！");
			break;
		}
		printf("数字为%d\n",Count);
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021349101.png)



## 11.continue语句


**conuntie**：跳过尚未执行的部分，直接进行下一次循环



```
#include<stdio.h>
int main()
{
	int Count;
	for(Count=0;Count<10;Count++)
	{
		if(Count==5)
		{
			printf("在这继续！\n");
			continue; 
		}
		printf("数字为：%d\n",Count);
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021411236.png)



# 五、数组


## 1.一维数组


**一维数组**：存储一组相同类型的变量



**数组定义**  
`类型说明符 数组标识符[常量表达式]`



**数组引用**  
`数组标识符[下标]`



> 数组下标从0开始
>



```
//反向输出数组 
#include<stdio.h>
int main()
{
	int Array[5],index,temp;              //定义数组，变量 
	printf("请输入一个数组：\n");
	for(index=0;index<5;index++)          //输入数组 
	{
		scanf("%d",&Array[index]);
	 } 
	printf("原数组为：\n");
	for(index=0;index<5;index++)          //输出原数组 
	{
		printf("%d ",Array[index]);
	 } 
	printf("\n");
	for(index=0;index<2;index++)          //交换两次，1和5换，2和4换 
	{
		temp = Array[index];              //中间变量暂存数组 
		Array[index]=Array[4-index];      //第一次5给1，第二次4给2 
		Array[4-index]=temp;              //第一次1给5，第二次2给4 
	}
	printf("反向数组为：\n");
	for(index=0;index<5;index++)
	{
		printf("%d ",Array[index]);
	 } 
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021557711.png)



**初始化**



1.一一赋值，有几个数赋几个值
2.一部分赋值，未赋值为0
3.不指定数组长度赋值



```
int a[5]={1,2,3,4,5};
int a[5]={1,2,3};
int a[]={1,2,3,4,5}
```



**应用**



```
//数组保存姓名
#include<stdio.h>
int main()
{
	char *Name[3];          //字符指针数组
	int i;
	Name[0] = "张三"; 
	Name[1] = "李四";
	Name[2] = "王五";
	for(i=0;i<3;i++)
	{
		printf("%s\n",Name[i]);
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021628192.png)



## 2.二维数组


**二维数组**：由行和列组成的两个一维数组



**数组定义**  
`数据类型 数组名[表达式1][表达式2]`



> 先放行，再放列  
下标可以是整型常量或整型表达式



**数组引用**  
`数组名[下标][下标]`



**初始化**



1.一一赋值
2.省略行下标，不能省略列下标
3.分组分配
4.部分分配
5.对元素赋值



```
int a[2][3]={1,2,3,4,5,6};
int a[][3]={1,2,3,4,5,6};
int a[2][3]={{1,2,3},{4,5,6}};
int a[2][3]={{1,2},{3,4}};
int a[2][3];a[0][0]=1;a[0][1]=2;
```



**应用**



```
//输出最值并行列互换
#include<stdio.h>
int main()
{
	int a[2][3],b[3][2];
	int max,min;
	int i,j,k,l;
	printf("请输入一个二维数组：\n"); 
	for(i=0;i<2;i++)                  //输入数组 
	{
		for(j=0;j<3;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("二维数组为：\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");                 //分行 
	}
	/*求数组中的最大值及其下标*/
	max = a[0][0];
	k=0;l=0;
	for(i=0;i<2;i++) 
	{
		for(j=0;j<3;j++)
		{
			if(max<a[i][j])
			{
				max=a[i][j];
				k=i;
				l=j;
			}
		}
	}
	printf("数组中的最大值为：\n");
	printf("a[%d][%d]=%d",k,l,max);
	printf("\n");
	/*求数组中的最小值及其下标*/
	min = a[0][0];
	k=0;l=0;
	for(i=0;i<2;i++) 
	{
		for(j=0;j<3;j++)
		{
			if(min>a[i][j])
			{
				min=a[i][j];
				k=i;
				l=j;
			}
		}
	}
	printf("数组中的最小值为：\n");
	printf("a[%d][%d]=%d",k,l,min);
	printf("\n");
	/*求行列互换后的数组*/
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			b[j][i] = a[i][j];
		}
	 } 
	printf("转换后的代码为：\n");
		for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	 } 
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307021725402.png)



```
//求对角元素之和 
#include<stdio.h>
int main()
{
	int a[3][3];
	int i,j,sum=0;
	printf("请输入：\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				sum = sum + a[i][j];
			}
		}
	}
	printf("结果为：%d\n",sum);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307022300543.png)



## 3.字符数组


**字符数组**：数据元素为字符的数组



**数组定义**  
`char 数组标识符[常量表达式]`



**初始化**



1.一一对应
2.省略数组长度
3.利用字符串



```
char a[5]={'H','e','l','l','o'};
char a[]={'H','e','l','l','o'};
char a[5]={"Hello"};
```



> \0为结束的标志  
%c输出字符，%s输出字符串
>



```
//计算单词个数 
#include<stdio.h>
int main()
{
	char a[100];
	int i,Word=1;
	char Blank;
	gets(a);
	if(a[0]=='\0')
	{
		printf("这里没有字符！\n");
	 } 
	else if(a[0]==' ')
	{
		printf("第一个字符为空格！\n");
	}
	else
	{
		for(i=0;a[i]!='\0';i++)
		{
			Blank= a[i];
			if(Blank==' ')
			{
				Word++;
			}
		} 
		printf("单词数为%d",Word);
	}
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307030940224.png)



## 4.多维数组


**多维数组**：与二维数组相同，不过下标更多



`数据类型 数组名[常量表达式1][常量表达式2][常量表达式3]`



## 5.排序算法


### 5.1 选择排序法


**选择排序法**：从小到大排列时，将第一个数字与最小值换位，第二个数字与剩下的最小值换位，以此类推，直至所以数字都换过位置



```
#include<stdio.h>
int main()
{
	int i,j;
	int a[10];
	int temp,pos;                       //定义临时变量，临时位置 
	printf("请输入数组元素值：\n");
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	/*从小到大排序*/
	for(i=0;i<9;i++)                   
	{
		temp = a[i];					//记录当前元素的值 
		pos = i;						//记录当前元素的位置 
		for(j=i+1;j<10;j++)
		{
			if(a[j]<temp)				//比较大小 
			{
				temp = a[j];			//最小值替换当前元素值 
				pos = j;				//最小值替换当前元素位置 
			}
		}
		a[pos] = a[i]; 					//交换元素 
		a[i] = temp;					//交换值 
	}
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
		if(i==4)
			printf("\n");
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307031748551.png)



### 5.2 冒泡排序法


**冒泡排序法**：每次比较相邻的两个数，将较小的数放在较大的数前面



```
#include<stdio.h>
int main()
{
	int i,j,temp;
	int a[10];
	printf("请输入一个数组：\n");
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	 } 
	/*从小到大排序*/
	for(i=1;i<10;i++)
	{
		for(j=9;j>=i;j--)
		{
			if(a[j]<a[j-1])
			{
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}	
	}
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
		if(i==4)
		printf("\n");
	}
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307041709555.png)



### 5.3 交换排序法


**交换排序法**：将每一个数与后面所有数一一比较，数据符合则交换位置



```
#include<stdio.h>
int main()
{
	int i,j,temp;
	int a[10];
	printf("请输入一个数组元素：\n");
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(a[j]<a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
		if(i==4)
		{
			printf("\n");
		}
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307041739086.png)



### 5.4 插入排序法


**插入排序法**：



```
#include<stdio.h>
int main()
{
	int i,j,temp,pos;
	int a[10];
	printf("请输入一个数组：\n");
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		temp = a[i];
		pos =  i-1;
		while((pos>=0)&&(temp<a[pos]))
		{
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = temp;
	}
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
		if(i==4)
		printf("\n");
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307051307508.png)



### 5.5 折半排序法


```
#include<stdio.h>

void CelerityRun(int left,int right,int array[]);

int main()
{
	int i;
	int a[10];
	printf("请输入一个数组：\n");
	for(i=0;i<10;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	CelerityRun(0,9,a);
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
		if(i==4)
		printf("\n");
	}
	return 0;
}

void CelerityRun(int left,int right,int array[])
{
	int i,j;
	int middle,temp;
	i = left;
	j = right;
	middle = array[(left+right)];
	do
	{
		while((array[i]<middle)&&(i<right))
			i++;
		while((array[j]>middle)&&(j>left))
			j--;
		if(i<=j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
 		}
	}while(i<=j);
	if(left<j)
		CelerityRun(left,j,array);
	if(right>i)
		CelerityRun(i,right,array);
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307060922773.png)



## 6.字符串处理


### 6.1 字符串复制（strcpy）


**strcpy函数**：复制特定长度的字符串到另一个字符串中



`strcpy(目的字符数组名，源字符数组名)`



> 不能用赋值语句直接赋值



```
#include<stdio.h>
int main()
{
	char a[30],b[30];
	printf("输入一个目的字符串：\n");
	gets(a);
	printf("输入一个源字符串：\n");
	gets(b);
	strcpy(a,b);
	printf("复制后的目的字符串：\n");
	puts(a);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307060950245.png)



### 6.2 字符串连接（strcat）


**strcat函数**：将一个字符串连接到另一个字符串的末尾，组成一个新的字符串



`strcat(目的字符数组名，源字符数组名)`



```
int main()
{
	char a[30],b[30];
	printf("输入一个目的字符串：\n");
	gets(a);
	printf("输入一个源字符串：\n");
	gets(b);
	strcat(a,b);
	printf("连接后的目的字符串：\n");
	puts(a);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307060958243.png)



### 6.3 字符串比较（strcmp）


**strcmp函数**：将一个字符串与另一个字符串一一比较



`strcmp(字符数组1，字符数组2)`



字符串1=字符串2 ，返回0  
字符串1>字符串2，返回正数  
字符串1<字符串2，返回负数



```
#include<stdio.h>
int main()
{
	char user[20]={"root"};
	char password[20]={"123456"};
	char u[20],p[20];
	int i=0;
	while(i<3)
	{
		printf("请输入用户名：\n");
		gets(u);
		printf("请输入密码：\n");
		gets(p);
		if(strcmp(user,u))
		{
			printf("用户名输入错误!\n");
		}
		else
		{
			if(strcmp(password,p))
			{
				printf("密码错误！\n");
			}
			else
			{
				printf("欢迎使用！\n");
				break;
			}
		}
		i++;
	}
	if(i==3)
	{
		printf("连续输入错误3次！\n");
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307061018127.png)



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307061020235.png)



### 6.4 字符串大小写转换（strupr/strlwr）


**strupr函数**：将字符串中的小写字母转换为大写字母其他不变



`strupr(字符串)`



**strlwr函数**：将字符串中的大写字母转换为小写字母其他不变



`strlwr(字符串)`



```
#include<stdio.h>
#include<string.h>
int main()
{
	char text[20],change[20];
	int num;
	int i=0;
	printf("（1转为大写，2转为小写，0退出）\n");
	while(1)
	{
		printf("请输入转换方式：\n");
		scanf("%d",&num);
		if(num==1)
		{
			printf("请输入一个字符串：\n");
			scanf("%s",&text);
			strcpy(change,text);
			strupr(change);
			printf("转换完的字符串为：%s\n",change);			
		}
		else if(num==2)
		{
			printf("请输入一个字符串：\n");
			scanf("%s",&text);
			strcpy(change,text);
			strlwr(change);
			printf("转换完的字符串为：%s\n",change);
		}
		else if(num==0)
		{
			break;
		}
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307061047884.png)



### 6.5 字符串长度（strlen）


**strlen函数**：计算字符串的实际长度，不含\0



`strlen(字符数组名)`



```
#include<stdio.h>
#include<string.h>
int main()
{
	char text[50],connect[50];
	int num;
	printf("请输入一个字符串：\n");
	scanf("%s",&text);
	num = strlen(text);
	printf("字符串长度为：%d\n",num);
	printf("请再输入一个字符串：\n");
	scanf("%s",&connect);
	num=strlen(connect);
	printf("字符长度为：%d\n",num);
	strcat(text,connect);
	printf("连接后的字符串：%s\n",text);
	num = strlen(text);
	printf("连接后的字符长度为：%d",num);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307061400397.png)



## 7.应用


```
//反转字符串 
#include<stdio.h>
int main()
{
	int i,size;
	char a[7]={"abcdefg"};
	char b[7]={0};
	size=sizeof(a);
	for(i=0;i<6;i++)
	{
		b[size-i-2]=a[i];
	}
	printf("输出源字符为：%s\n",a);
	printf("输出目标字符为：%s\n",b);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307061412072.png)



```
//输出系统时间和日期 
#include<stdio.h>
#include<time.h>
int main()
{
	int command[4]={0,1,2,3};
	int num;
	struct tm *Time;
	printf("1-显示时间\n2-显示日期\n3-退出\n");
	while(1)
	{
		printf("\n请输入命令：");
		scanf("%d",&num);
		if(command[1]==num)
		{
			time_t nowTime;
			time(&nowTime);
			Time=localtime(&nowTime);
			printf("系统时间：%d:%d:%d\n",Time->tm_hour,Time->tm_min,Time->tm_sec);
		}
		else if(command[2]==num)
		{
			time_t nowTime;
			time(&nowTime);
			Time=localtime(&nowTime);
			printf("系统日期：%d/%d/%d\n",1900+Time->tm_year,Time->tm_mon+1,Time->tm_mday);
		}
		else if(command[3]==num)
		{
			return 0;
		}
	} 
	return 0;
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307061532401.png)



```
//字符串加密、解密 
#include<stdio.h>
#include<string.h>
int main()
{
	
	int i;
	int result = 1;
	int count = 0;
	char Text[128]={'\0'};
	char cryptograph[128]={'\0'};
	printf("(1为加密，2为解密，3为退出)\n");
	while(1)
	{
		printf("\n请输入命令：");
		scanf("%d",&result);
		if(result==1)
		{
			printf("输入要加密的明文：");
			scanf("%s",&Text);
			count = strlen(Text);
			for(i=0;i<count;i++)
			{
				cryptograph[i]=Text[i]+i+5;
			}
			cryptograph[i]='\0';
			printf("加密后的密文是：%s\n",cryptograph);
		}
		else if(result==2)
		{
			count=strlen(Text);
			for(i=0;i<count;i++)
			{
				Text[i] = cryptograph[i]-i-5;
			}
			Text[i]='\0';
			printf("解密后的明文是：%s\n",Text);
		}
		else if(result==3)
		{
			printf("运行结束!\n");
			break;
		}
		else
		{
			printf("请输入字符：\n");
		} 
	}
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307061639904.png)



# 六、函数


## 1.函数概述


1.函数是C语言的基本单元，包含可执行代码
2.主函数可以调用其他函数，其他函数可以相互调用
3.函数可以有参数和返回值



## 2.函数定义


**函数定义**：让编译器知道函数功能，包括定义函数头和函数体



函数头分为返回值类型、函数名、参数表



函数体包括局部变量的声明和函数的可执行代码



无参函数：没有参数的函数



空函数：没有任何内容的函数（占位）



```
int AddTwoNumber(int Num1,int Num2)
{
	int result;
	result = num1+num2;
	return result;
}
```



> 函数要先声明，再定义  
如果函数定义放在调用之前，就不需要声明
>



## 3.返回语句


**返回语句**：从所在函数中退出，回到调用程序中去，或者将函数值赋给调用的表达式



```
//从函数返回
#include<stdio.h>
int Function();
int main()
{
	printf("这是输出前\n");
	Function();
	printf("这是输出后\n");
	return 0;
 } 
int Function()
{
	printf("这是输出中\n");
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307081135064.png)



```
//返回函数值 
#include<stdio.h>
int Minus(int Number1,int Number2)
{
	int result;
	result = Number1-Number2;
	return result;
}
int main()
{
	int result;
	result=Minus(9,5);
	printf("%d",result); 
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307081550416.png)



```
#include<stdio.h>
char ShowChar();
int main()
{
	char Result;
	Result = ShowChar();
	printf("%c\n",Result);
	return 0;
}
char ShowChar()
{
	int Number;
	printf("请输入一个数：\n");
	scanf("%d",&Number);
	return Number;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307081557175.png)



## 4.函数参数


### 4.1 形参与实参


**形式参数**：形式上存在的参数，放在括号里面，在拿书调用之前，传递给函数的值将被复制到形式参数中



**实际参数**：实际存在的参数，函数调用者提供给函数的参数



```
#include<stdio.h>
void DrinkMilk(char *Bottle);
int main()
{
	char Poke[]="";
	printf("给宝宝喝:");
	scanf("%s",&Poke);
	DrinkMilk(Poke);
	return 0;
}
void DrinkMilk(char *Bottle)
{
	printf("宝宝喝%s\n",Bottle);
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307100810565.png)



### 4.2 数组参数


> 数组作为实参时，只传递数组的地址，而不是传递整个数组  
数组名作实参时，传递数组第一个元素的指针
>



```
#include<stdio.h>
void ShowMember(int Member);
int main()
{
	int Count[10];
	int i;
	printf("请输入一个数组：\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&Count[i]);
	}
	for(i=0;i<10;i++)
	{
		ShowMember(Count[i]);
	}
	return 0;
 } 
void ShowMember(int Member)
{
	printf("数组元素为：%d\n",Member);
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307100824091.png)



```
#include<stdio.h>
void Evalute(int b[10]);
void Display(int b[10]);
int main()
{
	int a[10];
	Evalute(a);
	Display(a);
	return 0;
}
void Display(int b[10])
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("数组元素是：%d\n",b[i]);
	}
}
void Evalute(int b[10])
{
	int i;	
	for(i=0;i<10;i++)
	{
		b[i]=i;
	}
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307100910582.png)



### 4.3 指针作参数


```
#include<stdio.h>
void Evalute(int *Point);
void Display(int *Point);
int main()
{
	int a[10];
	Evalute(a);
	Display(a);
	return 0;
}
void Display(int *Point)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("数组元素为：%d\n",Point[i]);
	}
}
void Evalute(int *Point)
{
	int i;
	for(i=0;i<10;i++)
	{
		Point[i]=i;
	}
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307100919526.png)



### 4.4 main函数参数


**argc**：保存命令行的参数个数，整型



**argv**：指向字符指针数组的指针



```
#include<stdio.h>
int main(int argc,char *argv[])
{
	printf("%s\n",argv[0]);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307100925965.png)



## 5.函数调用


**调用方式**分为函数语句调用，函数表达式调用，函数参数调用



### 5.1 函数语句调用


**函数语句调用**：把函数的调用作为一个语句



```
#include<stdio.h>
void Display()
{
	printf("仅实现输出一条语句");
}
int main()
{
	Display();
	return 0; 
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307100935771.png)



### 5.2 函数表达式调用


**函数表达式调用**：函数出现一个表达式中



```
#include<stdio.h>
int AddTwoNum(int Num1,int Num2);
int main()
{
	int Result;
	int Num3 = 10;
	Result = Num3*AddTwoNum(3,5);
	printf("结果为：%d\n",Result);
	return 0;
}
int AddTwoNum(int Num1,int Num2)
{
	int tempResult;
	tempResult = Num1 + Num2;
	return tempResult;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307100949623.png)



### 5.3 函数参数调用


**函数参数调用**：将函数返回值作为实参，传递到函数中使用



```
#include<stdio.h>
int AddTwoNum(int Num1,int Num2);
int main()
{
	int Result;
	Result = AddTwoNum(10,AddTwoNum(3,5));
	printf("结果是：%d\n",Result);
	return 0;
}
int AddTwoNum(int Num1,int Num2)
{
	int TempResult;
	TempResult = Num1 + Num2;
	return TempResult;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307101006226.png)



### 5.4 嵌套调用


> 函数定义相互平行，一个函数体内不能定义另一个函数
>



```
#include<stdio.h>
void First();
void Second();
void Third();
void Final();
int main()
{
	First();
	return 0;
}
void First()
{
	printf("这是第一步\n");
	Second();
}
void Second()
{
	printf("这是第二步\n");
	Third();
}
void Third()
{
	printf("这是第三步\n");
	Final(); 
}
void Final()
{
	printf("这是最后一步");
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307121507498.png)



### 5.5 递归调用


```
#include<stdio.h>
void Display(char **a);
char* b[]=
{
	"ABC","DEF","GHI","JKL","end"
};
int main()
{
	Display(b);
	return 0;	
}
void Display(char **a)
{
	if(*a=="end")
	{
		return ;
	}
	else
	{
		Display(a+1);
		printf("%s\n",*a);
	}
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307130915222.png)



## 6.内部函数和外部函数


> 函数是c语言中最小的单位
>



### 6.1 内部函数


**内部函数**：函数只被所在源文件使用



`static 返回值类型 函数名（参数列表）`



> 不同源文件中的相同函数名不会冲突
>



```
#include<stdio.h>
static char* Get(char* p)
{
	return p;
}
static void Show(char* p)
{
	printf("%s\n",p);
}
int main()
{
	char *pString;
	pString = Get("Hello!");
	Show(pString);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230714155112.png)



### 6.2 外部函数


**外部函数**：可以被其他源文件调用的函数



```
//文件1
#include<stdio.h>
extern char* GetString(char* p);
extern void Show(char* p);
int main()
{
	char* p;
	p = GetString("Hello!");
	Show(p);
	return 0;
}
//文件2
extern char* GetString(char* p)
{
	return p;
}
//文件3
extern void Show(char* p)
{
	printf("%s\n",p);
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230714160037.png)



## 7.局部变量和全局变量


### 7.1 局部变量


**局部变量**：在函数内部定义的变量，无法被其他函数所引用



```
#include<stdio.h>
int main()
{
	int Num = 1;
	printf("%d\n",Num);
	if(Num>0)
	{
		int Num = 2;
		printf("%d\n",Num);
		if(Num>0)
		{
			int Num = 3;
			printf("%d\n",Num);
		}
		printf("%d\n",Num);
	}
	printf("%d\n",Num);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230714154404.png)



> 位于不同作用域的变量，可以使用相同的标识符
>



### 7.2 全局变量


**全局变量**：在函数外声明的变量，属于源文件



```
#include<stdio.h>
int GlobalPrice = 100;
void Price1();
void Price2();
void Price3();
void ChangePrice();
int main()
{
	printf("原始的价格是%d\n",GlobalPrice);
	Price1();
	Price2();
	Price3();
	ChangePrice();
	printf("当前的价格是%d\n",GlobalPrice);
	Price1();
	Price2();
	Price3();
}
void Price1()
{
	printf("一号价格是：%d\n",GlobalPrice);
}
void Price2()
{
	printf("二号价格是：%d\n",GlobalPrice);
}
void Price3()
{
	printf("三号价格是：%d\n",GlobalPrice);
}
void ChangePrice()
{
	printf("你想要更改的价格是什么？请输入：");
	scanf("%d",&GlobalPrice); 
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230714162207.png)



## 8.数学公式


### 8.1 绝对值


**abs函数**：求整数绝对值  
**labs函数**：求长整数绝对值  
**fabs函数**：求浮点数绝对值



```
#include<stdio.h>
#include<math.h>
int main()
{
	int Result1;
	int Num1 = -12;
	long Result2;
	long Num2 = -1234567890L;
	double Result3;
	double Num3 = -123.0;
	Result1 = abs(Num1);
	Result2 = labs(Num2);
	Result3 = fabs(Num3);
	printf("数字1为：%d，绝对值为：%d\n",Num1,Result1);
	printf("数字2为：%ld，绝对值为：%ld\n",Num2,Result2);
	printf("数字3为：%lf，绝对值为：%lf\n",Num3,Result3);	
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230714171803.png)



### 8.2 三角函数


**sin函数**：求正弦函数  
`double sin(double x);`



**cos函数**：求余弦函数  
`double cos(double x);`



**tan函数**：求正切函数  
`double tan(double x);`



```
#include<stdio.h>
#include<math.h>
int main()
{
	double ResultSin;
	double ResultCos;
	double ResultTan;
	double fXsin = 0.5;
	double fXcos = 0.5;
	double fXtan = 0.5;
	ResultSin = sin(fXsin);
	ResultCos = cos(fXcos);
	ResultTan = tan(fXtan);
	printf("sin%2.1lf的值为：%3.2lf\n",fXsin,ResultSin);
	printf("cos%2.1lf的值为：%3.2lf\n",fXcos,ResultCos);
	printf("cos%2.1lf的值为：%3.2lf\n",fXtan,ResultTan);
	return 0;
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230714174547.png)



### 8.3 字符检测


**isalpha函数**：检测字母，是字母返回非零  
`int isalpha(int ch)`



**isdigit函数**：检测数字，是数字返回非零  
`int isdigit(int ch)`



**isalnum函数**：检测数字或字母，是二者之一返回非零  
`int isalnum(int ch)`



```
#include<stdio.h>
#include<ctype.h>
void Switch(char c);
int main()
{
	char CharPut;
	char CharTemp;
	printf("第一次输入字符：");
	scanf("%c",&CharPut);
	Switch(CharPut);
	CharTemp = getchar();
	printf("第二次输入字符：");
	scanf("%c",&CharPut);
	Switch(CharPut);
	CharTemp = getchar();
	printf("第三次输入字符：");
	scanf("%c",&CharPut);
	Switch(CharPut);
	return 0;
}
void Switch(char c)
{
	if(isalpha(c))
	{
		printf("你输入的是字母%c\n",c);
	}
	if(isdigit(c))
	{
		printf("你输入的是数字%c\n",c);
	}
	if(isalnum(c))
	{
		printf("你输入的是数字或字母！\n"); 
	}
	else{
		printf("你输入的既不是数字，也不是字母！\n");
	}
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230714180850.png)



# 七、指针


## 1.概念


### 1.1 地址、变量与指针


**地址**：内存区中对每个字节的编号



**指针**：内存中的一个地址



**指针变量**：存放另一个变量的地址



`类型说明 * 变量名`



> *表示该变量为指针变量  
变量名为指针变量名  
类型说明为指向的变量类型
>



**指针赋值**：只能赋予地址，不能赋予其他数据



`& 变量名`



```
#include<stdio.h>
int main()
{
	int a,b;
	int *point1,*point2;
	printf("请输入两个数：");
	scanf("%d%d",&a,&b);
	point1=&a;
	point2=&b;
	printf("两个数分别为：%d,%d",*point1,*point2);
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230715085648.png)



**引用指针变量**：引用指针变量所指向的值



`*指针变量`



```
#include<stdio.h>
int main()
{
	int *p,q;
	printf("请输入：");
	scanf("%d",&q);
	p = &q;
	printf("数字为：%d",*p);
}
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/20230715090327.png)



### 1.2 指针运算


&  取值运算符  
*  指针运算符  
&*   先指针后取值  
*&  先取值后指针



> 指针自增自减按所指向类型的直接长度进行增减
>



```
#include<stdio.h>
main()
{
	int i;
	int *p;
	printf("请输入一个数字：");
	scanf("%d",&i);
	p = &i;
	printf("结果1为：%d\n",p);
	p++;
	printf("结果2为：%d\n",p);
 }
```



![](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202307161037737.png)



## 2.数组与指针


**数组指针**：存储数组的首地址



```
#include<stdio.h>
main()
{
	int *p,*q;
	int a[5],b[5],i;
	p=&a[0];
	q=b;
	printf("请输入第一个数组：\n");
	for(i=0;i<5;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	printf("请输入第二个数组：\n"); 
	for(i=0;i<5;i++)
	{
		printf("b[%d]=",i);
		scanf("%d",&b[i]); 
	}
	printf("数组a为：\n");
	for(i=0;i<5;i++)
	{
		printf("%5d",*(p+i));
	}
	printf("\n");
	printf("数组b为：\n");
	for(i=0;i<5;i++)
	{
		printf("%5d",*(q+i));
	}
	printf("\n");
	return 0;
}
```



**二维数组**：



> *(a+i)与a[i]是等价的
>



**字符串指针**



```
#include<stdio.h>
main()
{
	char str1[] = "You are my god";
	char str2[30];
	char *p,*q;
	p=str1;
	q=str2;
	while(*p!='\0')
	{
		*q=*p;
		p++;
		q++;
	}
	*q='\0';
	printf("输出字符串为：\n");
	puts(str2);
}
```



**字符串数组**



`类型名 数组名[数组长度]`



```
#include<stdio.h>
main()
{
	int i;
	char *month[]=
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	for(i=0;i<12;i++)
	{
		printf("%s\n",month[i]);
	}
}
```



## 3.双重指针


`类型标识符 **指针变量名`



```
#include<stdio.h>
main()
{
	int i;
	char **p;
	char *month[]=
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	for(i=0;i<12;i++)
	{
		p=month+i;
		printf("%s\n",*p);
	}
}
```



## 4.函数参数


```
//交换地址 
#include<stdio.h>
void Swap(int *a,int *b)
{
	int temp ;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int x,y;
	int *c,*d;
	scanf("%d%d",&x,&y);
	c=&x;
	d=&y;
	Swap(c,d);
	printf("%d,%d",x,y);
	return 0;
}
```



```
//嵌套调用
```



```
//奇数之和
```



```
//冒泡排序
```



```
//字母顺序排序
```



```
//数组元素求和
```



## 5.指针函数


`类型名 *函数名（参数列表）*`



```
#include<stdio.h>
int per(int a,int b);
void main()
{
	int ilong,width,result;
	printf("请输入长和宽：");	
	scanf("%d%d",&ilong,&width);
	result=per(ilong,width);
	printf("周长为：%d",result);
}
int per(int a,int b)
{
	return (a+b)*2;
}
```



## 6.main参数


```
#include<stdio.h>
main(int argc,char *argv[])
{
	printf("命令名：%s\n",*argv);
	printf("参数个数：%d\n",argc);
}
```



# 八、结构体与共用体


## 1.结构体


### 1.1 定义与声明


**结构体**：由不同数据类型组成的有机整体



先声明，再定义



```
struct 结构体名
{
	成员列表;
};
```



```
struct Product
{
	char Name[10];    //产品名称
	char Shape[20];   //产品形状
	char Color[10];   //产品颜色
	char Func[20];    //产品功能
	int price;        //产品价格
	char Area[20];    //产品产地
};
```



声明的同时定义



```
struct 结构体名
{
	成员列表;
}变量名列表;
```



```
struct Product
{
	char Name[10];    //产品名称
	char Shape[20];   //产品形状
	char Color[10];   //产品颜色
	char Func[20];    //产品功能
	int price;        //产品价格
	char Area[20];    //产品产地
}product1,product2;
```



直接定义



```
struct
{
	成员列表；
}变量名列表;
```



```
struct
{
	char Name[10];    //产品名称
	char Shape[20];   //产品形状
	char Color[10];   //产品颜色
	char Func[20];    //产品功能
	int price;        //产品价格
	char Area[20];    //产品产地
}product1,product2;
```



> 不要忘记结构体后的分号  
通常将结构体的声明放在头文件中
>



### 1.2 引用


`结构体变量.成员名`



```
product1.Name="Icebox";
product2.Price="2000";
```



> 只能对最低级的结构体成员进行操作，不能直接操作结构体  
既能引用结构体成员地址，也能直接引用结构体变量地址
>



```
#include<stdio.h>
struct Product
{
	char Name[10];    //产品名称
	char Shape[20];   //产品形状
	char Color[10];   //产品颜色
	char Func[20];    //产品功能
	int Price;        //产品价格
	char Area[20];    //产品产地
};
int main()
{
	struct Product product1;
	printf("请输入产品名称：");
	scanf("%s",&product1.Name);
	printf("请输入产品形状：");
	scanf("%s",&product1.Shape);
	printf("请输入产品颜色：");
	scanf("%s",&product1.Color);
	printf("请输入产品功能：");
	scanf("%s",&product1.Func);
	printf("请输入产品价格：");
	scanf("%d",&product1.Price);
	printf("请输入产品产地：");
	scanf("%s",&product1.Area);
	printf("产品名称：%s\n",product1.Name);
	printf("产品形状：%s\n",product1.Shape);
	printf("产品颜色：%s\n",product1.Color);
	printf("产品功能：%s\n",product1.Func);
	printf("产品价格：%d\n",product1.Price);
	printf("产品产地：%s\n",product1.Area);
	return 0;
}
```



### 1.3 初始化


```
#include<stdio.h>
struct Student
{
	char Name[10];
	char Sex;
	int Grade;
} student1={"zhangsan",'M',100};
int main()
{
	struct Student student2={"lisi",'W',99};
	printf("结构体1中的信息为：\n");
	printf("姓名：%s\n性别：%c\n成绩：%d\n",student1.Name,student1.Sex,student1.Grade);
	printf("结构体2中的信息为：\n");
	printf("姓名：%s\n性别：%c\n成绩：%d\n",student2.Name,student2.Sex,student2.Grade);	
	return 0;
}
```



## 2.结构体数组


### 2.1 定义


```
struct 结构体名
{
	成员列表；
}数组名；
```



```
struct Student
{
	char Name[10];
	int Number;
	char Sex;
	int Grade;
}student[5];
```



### 2.2 初始化


```
struct 结构体名
{
	成员列表；
}数组名={初始值列表}；
```



```
#include<stdio.h>
struct Student
{
	char Name[10];
	int Number;
	char Sex;
	int Grade;
}student[5]={{"zhangsan",000001,'M',90},
			{"lisi",000002,'W',100},
			{"wangwu",000003,'M',80},
			{"zhaoliu",000004,'w',70},
			{"zhongqi",000005,'M',60}};
int main()
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("第%d名学生：\n",i+1);
		printf("姓名：%s\n学号：%d\n性别：%c\n成绩：%d\n",student[i].Name,student[i].Number,student[i].Sex,student[i].Grade);
		printf("\n"); 
	}
}
```



## 3.结构体指针


### 3.1 指向结构体变量


#### 定义


`结构体类型 \*指针名`



#### 引用


+ 使用点运算符引用结构成员



`(*pStruct).成员名`



+ 使用指向运算符引用结构成员



`pStruct->成员名`



```
#include<stdio.h>
#include<string.h>
struct Student
{
	char Name[10];
	int Number;
	char Sex;
	int Grade;
}student;
int main()
{
	struct Student *pStruct;
	pStruct=&student;
	strcpy(pStruct->Name,"zhangsan");
	pStruct->Number=000001;
	pStruct->Sex='W';
	pStruct->Grade=100;
	printf("姓名：%s\n学号：%d\n性别：%c\n成绩：%d\n",student.Name,student.Number,student.Sex,student.Grade);
}
```



### 3.2 指向结构体数组


```
#include<stdio.h>
struct Student
{
	char Name[10];
	int Number;
	char Sex;
	int Grade;
}student[5]={{"zhangsan",000001,'M',90},
			{"lisi",000002,'W',100},
			{"wangwu",000003,'M',80},
			{"zhaoliu",000004,'w',70},
			{"zhongqi",000005,'M',60}};
int main()
{
	struct Student*pStruct;
	int i;
	pStruct=student;
	for(i=0;i<5;i++,pStruct++)
	{
		printf("第%d名学生：\n",i+1);
		printf("姓名：%s\n学号：%d\n性别：%c\n成绩：%d\n",pStruct->Name,pStruct->Number,pStruct->Sex,pStruct->Grade);
		printf("\n");
	}
	return 0;
}
```



### 3.3 结构体作函数参数


#### 结构体变量


```
#include<stdio.h>
struct Student
{
	char Name[10];
	float Score[3];
}student0={"Zhangsan",80,85,87.5};
void Display(struct Student student)
{
	printf("姓名：%s\n语文：%.1f\n数学：%.1f\n英语：%.1f\n",student.Name,student.Score[0],student.Score[1],student.Score[2]);
	printf("平均分：%.1f",(student.Score[0]+student.Score[1]+student.Score[2])/3);
}
int main()
{
	Display(student0);
	return 0;
}
```

#### 指向结构体变量指针


```
#include<stdio.h>
struct Student
{
	char Name[10];
	float Score[3];
}student={"Zhangsan",80,85,87.5};
void Display(struct Student *stu)
{
	printf("姓名：%s\n语文：%.1f\n数学：%.1f\n英语：%.1f\n",stu->Name,stu->Score[0],stu->Score[1],stu->Score[2]);
	stu->Score[2]=80; 
}
int main()
{
	struct Student *pStruct=&student;
	Display(pStruct);
	printf("改变后的英语：%.1f",pStruct->Score[2]);
	return 0;
 }
```



#### 结构体变量成员


## 4.包含结构的结构


```
#include<stdio.h>
struct data
{
	int year;
	int month;
	int day;
};
struct student
{
	char Name[10];
	int num;
	char sex;
	struct data birthday;
}student={"Zhangsan",000001,'M',{1999,12,21}};
int main()
{
	printf("姓名：%s\n学号：%d\n性别：%c\n生日：%d/%d/%d",student.Name,student.num,student.sex,student.birthday.year,student.birthday.month,student.birthday.day);
	return 0;
}
```

## 5.链表

### 5.1 概述

链表必须利用指针实现

### 5.2 动态链表

**malloc函数**：在内存中动态的分配一块内存空间

`void *malloc(int size);`

**calloc函数**：在内存中动态分配n个连续内存空间

`void calloc(unsigned n,unsigned size);`

**free函数**：使用指针指向的内存区

`void free(void *p);`

