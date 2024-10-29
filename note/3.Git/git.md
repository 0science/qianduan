[TOC]

# 一、前言

>本人大学才开始接触编程，自认为入门较晚。伴随着知识的积累，迫切需要一个知识输出是途径，个人博客无疑是首选，写博客离不开Markdown，我的第一篇博客就由此开始。

![](https://i-blog.csdnimg.cn/blog_migrate/6d9b14db5a2e83f7200515bd9dda4afc.png)

---
# 二、Markdown简介
![](https://i-blog.csdnimg.cn/blog_migrate/4fa0390a1a2b3c2e15f6fca316c13e08.jpeg)
## 1.定义

**Markdown是一种轻量级标记语言**

>通俗来讲就是一种轻排版，重内容的文档编写方法，简化版的word

## 2.优点

1. **轻量化**：Markdown文本编辑器占用的空间较小
2. **易读易写**：相比HTML，Markdown上手门槛更低，书写流畅也更易懂
3. **兼容性强**：世界上的主流的博客平台都能很好的支持Markdown

---
# 二、基础语法

## 1.标题

**说明**

文字前添加1~6个星号(#)，文本与#之间用空格隔开

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/ba1f9237a5723259700223beae3aa2fd.png)

&emsp;效果：

![](https://i-blog.csdnimg.cn/blog_migrate/92db1da7d4dd00559392c87ed907c5d5.png)

## 2.粗体

**说明**

两种方法

1. 在文字前后各加两个星号(*)
2. 在文字前后加各两条下划线(_)

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/eb5ed27b5e346ca0832f95703e6b04a0.png)

&emsp;效果：

>**这是加粗**  __这也是加粗__

## 3.斜体

**说明**

在文字前后加一个星号(*)

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/1d304d8eed2b2cd42ca74dd8823052e7.png)

&emsp;效果：

>*这是斜体*

## 4.加粗斜体

**说明**

在文字前后各加三个星号(*)

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/cbbd28fc93ced123c817782653607cb3.png)

&emsp;效果：

>***这是倾斜加粗***

## 5.高亮

**说明**

在文字前后加两个等号(=)

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/4a911797a10e60b0e32ed83855ef20fb.png)

&emsp;效果：

>==高亮==


## 6.删除线

**说明**

在文字前后加两条波浪线(~)

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/a9cd23e35e21c98c7fd34db68c3952b4.png)

&emsp;效果：

>~~删除文本~~

## 7.下划线

**说明**

借助HTML语法，u标签

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/9f570dcaa6405cdc903d91bfb04d4593.png)

&emsp;效果：

><u>下划线</u>

## 8.图片

**说明**

有两种方法
1. 插入在线图片（推荐）：感叹号加方括号加圆括号，方括号内放名称，圆括号内放照片网址；
2. 插入本地图片（不推荐）：感叹号加方括号加圆括号，方括号内放名称，圆括号内放照片的本地路径

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/c18e8bc40fb8baca0d8a84d1b53700e3.png)
![](https://i-blog.csdnimg.cn/blog_migrate/a6e4f807a88e6974378ef00fddb539b5.png)

&emsp;效果：

>![冰川](https://i-blog.csdnimg.cn/blog_migrate/9b2ef501856a321e6be57d8e2a9c19f0.jpeg)

>![冰川](https://i-blog.csdnimg.cn/blog_migrate/9b2ef501856a321e6be57d8e2a9c19f0.jpeg)

## 9.表格

**说明**

表头间竖线隔开，表头与内容用减号隔开，减号左加冒号居左，减号右加冒号居右，减号两边加冒号居中

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/946b9a6fc09a905c44488e34af0ecfdf.png)

&emsp;效果：

>表头|表头|表头
>:-----|:-----:|-----:
>大致内容|大致内容|大致内容

## 10.分割线

**说明**

两种方法
1. 连续三个及以上的星号独占有一行
2. 连续三个及以上的减号独占有一行

>写分割线记得空出前面一行来

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/8b5b49c85d9b21f881905f260ac96b5a.png)

&emsp;效果：

>***
>---

## 11.引用

**说明**

在文字前加一个大于号(>)

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/c48861a9625fec89213fbca6ceef0684.png)

&emsp;效果：

>这是引用

## 12.目录

**说明**

方括号加圆括号，方括号内填名称，圆括号内填想跳转的标题，只能跳转到标题处，标题内不要加空格

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/2a459ff914d7120f21502ec097beb4a6.png)

&emsp;效果：

[跳转到目录](#目录)

## 13.超链接

**说明**

方括号加圆括号，方括号内填名称，圆括号内填网址，也可加上双引号，内填注释

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/66ae04802d4c6f2dbe455ac3e6500cee.png)

&emsp;效果：

>[bilibili](https://www.bilibili.com/ "哔哩哔哩")

## 14.代码

**说明**

文字前后加一个点（esc键下方那个），添加一行代码
文字前后加三个点（esc键下方那个），添加一个代码块

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/3e1d6496041aefade903f6034e42c5fc.png)

&emsp;效果：

`printf("hello world!");`

```
#include<stdio.h>
int main(){
printf("hello world!");
return 0;}
```

## 15.无序列表

**说明**

有三种方法
1. 文字前加加号和空格
2. 文字前加减号和空格
3. 文字前加星号和空格

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/7400d32e7030cd837cf114069fdeb238.png)

&emsp;效果：

>+ 无序列表1
>+ 无序列表1
>- 无序列表2
>- 无序列表2
>* 无序列表3
>* 无序列表3

## 16.有序列表

**说明**

文字前加数字，点和空格

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/14f550b182ce209ebfb16296950a7608.png)

&emsp;效果：

>1. 有序列表
>2. 有序列表

## 17.任务列表

**说明**

有两种方法
1. 文字前加减号，空格，方括号，方括号内填勾
2. 文字前加减号，空格，方括号，方括号内填叉

**示例**

&emsp;文本：

![image.png](https://i-blog.csdnimg.cn/blog_migrate/1eddf92a05555b78879ae66bde05a747.png)
&emsp;效果：

- [ ] 未完成
- [x] 已完成

## 18.注释

**说明**

文字前加方括号和冒号，方括号里加双斜线，注释的内容在正文中不显示

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/c025b58362d8e103d1c14abc59df91a3.png)

&emsp;效果：

> 这是正文

[//]:这是注释

## 19.注脚

**说明**

文字后加方括号，方括号内放异或符号（shift+6）和数字；空一行后文字前加方括号和冒号，方括号内放异或符号（shift+6）和数字

**示例**

&emsp;文本：

![](https://i-blog.csdnimg.cn/blog_migrate/af55285dfd4fcd2aeb485276aee11c4a.png)

&emsp;效果：

>这是正文内容[^1]

[^1]:这是注释内容

---
# 三、进阶语法（简要概括）

### 1.快捷键

**说明**

提供了一些快捷键

**示例**

&emsp;文本：
![](https://i-blog.csdnimg.cn/blog_migrate/cf58514fbdbb4d592efc2209ae607a06.png)
&emsp;效果：

撤销：<kbd>Ctrl/Command</kbd> + <kbd>Z</kbd>
重做：<kbd>Ctrl/Command</kbd> + <kbd>Y</kbd>
加粗：<kbd>Ctrl/Command</kbd> + <kbd>B</kbd>
斜体：<kbd>Ctrl/Command</kbd> + <kbd>I</kbd>
标题：<kbd>Ctrl/Command</kbd> + <kbd>Shift</kbd> + <kbd>H</kbd>
无序列表：<kbd>Ctrl/Command</kbd> + <kbd>Shift</kbd> + <kbd>U</kbd>
有序列表：<kbd>Ctrl/Command</kbd> + <kbd>Shift</kbd> + <kbd>O</kbd>
检查列表：<kbd>Ctrl/Command</kbd> + <kbd>Shift</kbd> + <kbd>C</kbd>
插入代码：<kbd>Ctrl/Command</kbd> + <kbd>Shift</kbd> + <kbd>K</kbd>
插入链接：<kbd>Ctrl/Command</kbd> + <kbd>Shift</kbd> + <kbd>L</kbd>
插入图片：<kbd>Ctrl/Command</kbd> + <kbd>Shift</kbd> + <kbd>G</kbd>
查找：<kbd>Ctrl/Command</kbd> + <kbd>F</kbd>
替换：<kbd>Ctrl/Command</kbd> + <kbd>G</kbd>

### 2.转义字符

**说明**

用于输出无法直接输出的字符

**示例**

&emsp;文本：

![image.png](https://i-blog.csdnimg.cn/blog_migrate/a10aa99254688c02df4e9512d1f502d2.png)

&emsp;效果：

>空格&nbsp;空格

### 3.数学公式

**说明**

涉及LaTex公式，以求极限举例

**示例**

&emsp;文本：

![image.png](https://i-blog.csdnimg.cn/blog_migrate/d5447407dc463c60c17100d291ca1519.png)

&emsp;效果：

$$
 \lim_{x \to 0} \frac {3x ^2 +7x^3} {x^2 +5x^4} = 3
$$

### 4.甘特图

**说明**

通过条状图来显示项目、进度和其他时间相关的系统进展的内在关系随着时间进展的情况

**示例**

&emsp;文本：

![image.png](https://i-blog.csdnimg.cn/blog_migrate/86f62f419b010489067e2369ab894aac.png)

&emsp;效果：

```mermaid
gantt
dateFormat  YYYY-MM-DD
title 甘特图
section 所有任务
已完成               :done,    des1, 2023-06-05,2023-06-06
进行中               :active,  des2, 2023-06-06, 3d
待开始               :         des3, after des2, 4d
```

### 5.流程图

**说明**

Markdown也可以用来画流程图，但是不建议，建议用其他软件画图

**示例**

&emsp;文本：

![image.png](https://i-blog.csdnimg.cn/blog_migrate/40620660e21ef6b16b48391a68d9a724.png)

&emsp;效果：

```mermaid
graph LR;
START(开始)-->一阶段-->二阶段-->三阶段-->END(结束)
```

```mermaid
sequenceDiagram
A ->> B: 你好！
B -->> A: 谢谢！
B -->> A: 不客气!
```

```mermaid
pie showData
title 饼图
"A":90
"B":50
"C":30
"D":30
```

```mermaid
graph LR
A0[A] --> B0[B] 
A1[A] --- B1[B] 
A4[A] -.- B4[B] 
A5[A] -.-> B5[B] 
A7[A] ==> B7[B] 
A2[A] -- 描述 --- B2[B] 
A3[A] -- 描述 --> B3[B] 
A6[A] -. 描述 .-> B6[B] 
A8[A] == 描述 ==> B8[B] 
```

# 四、总结

## 参考文献

[【高效工具】《三》Typora直接使用MarkDown语法绘制流程图、时序图、甘特图_黑白猿的博客-CSDN博客](https://blog.csdn.net/gavinbj/article/details/104903318)

[markdown 中流程图详解_markdown流程图_放羊郎的博客-CSDN博客](https://blog.csdn.net/suoxd123/article/details/84992282)