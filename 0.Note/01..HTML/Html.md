[toc]

## 一、前言
&ensp;&ensp;作为一个阶段性学习的总结，方便后续查找和记忆。

## 二、入门

### 1.标准结构

```
<!DOCTYPE html> 
<html lang="zh-CN"> 
<head> 
<meta charset="UTF-8"> 
<title>我是一个标题</title> 
</head> 
<body> 
</body> 
</html>
```

### 2.文档基本格式

|标记|解释|
|-|-|
|\<!DOCTYPE html>|声明HTML规范|
|\<html>|告知浏览器，这是一个HTML文件|
|\<head>|封装其他标记|
|\<body>|主要内容|
|\<title>|网页标题|
|\<meta>|name="keywords" 关键字<br>name="description" 网页描述<br>name="author" 网页作者<br>|

### 3.基本概念

| 概念 | 描述 |
| - | - |
|单标签|只能有一个开始标记|
|双标签|开始标记和结束标记|
|相对路径|当前目录|
|绝对路径|全路径|

## 三、标签

<table>
th


</table>

| 标签名 | 含义 |属性值| 单/双 | 块/行 |
| --- | --- | --- | --- |--|
| h1~h6 | 标题 || 双 | 块 |
| p | 段落 || 双| 块 |
| div | 无含义用于整体布局 || 双 | 块 |
| span | 没有语义的通用容器 || 双 | 行 |
| em | 着重内容  || 双 | 行 |
| strong | 更重要的内容 || 双 | 行 |
| del | 删除线 || 双 | 行 |
| ins | 下划线 || 双 | 行 |
| mark| 高亮 || 双 | 行 |
| br | 换行 | | 单 | 块 |
| hr | 分隔 |alige 水平对齐<br>size 水平粗细<br>color 颜色<br>width 宽度 |单 | 块 |
| pre | 按原文显示| | 双 | 块 |
| img | 图片 |src 图片路径<br> alt 图片描述<br> width 图片宽度<br> height 图片高度<br> border 图片边框| 单 |块|
| a |超链接  |href 指定要跳转到的具体目标<br> target 控制跳转时如何打开页面<br> &nbsp;&nbsp;&nbsp;&nbsp;_self 在本窗口打开<br> &nbsp;&nbsp;&nbsp;&nbsp;_blank 在新窗口打开<br>id 元素的唯一标识，可用于设置锚点| 双 |行|
| ul | 无序列表 || 双 | 块 |
| ol | 有序列表 || 双 | 块 |
| li | 列表项 || 双 | 行 |
|dl | 列表定义 || 双 | 块 |
| dt | 列表定义标题 || 双 | 行 |
| dd | 列表定义内容 || 双 | 行 |
| table | 表格 || 双 | 块 |
| tr | 表格行 || 双 | 行 |
| td | 表格单元格 || 双 | 行 |
| caption | 表格标题 || 双 | 行 |
| th | 表格表头 || 双 | 行 |
| td | 表格内容 || 双 | 行 |
| form | 表单 |action 表单提交地址<br>method 提交方式<br>enctype 表单编码类型<br>novalidate 禁止校验<br>autocomplete 自动完成| 双 | 块 |
| input | 输入框 | type 类型<br>&nbsp;&nbsp;&nbsp;&nbsp;text 单行文本框<br>&nbsp;&nbsp;&nbsp;&nbsp;password 密码<br>&nbsp;&nbsp;&nbsp;&nbsp;radio 单选按钮<br>&nbsp;&nbsp;&nbsp;&nbsp;checkbox 多选按钮<br>&nbsp;&nbsp;&nbsp;&nbsp;submit 提交按钮<br>&nbsp;&nbsp;&nbsp;&nbsp;reset 重置按钮<br>&nbsp;&nbsp;&nbsp;&nbsp;image 图片按钮<br>&nbsp;&nbsp;&nbsp;&nbsp;hidden 隐藏域 <br>name 标识<br>value 默认值<br>placeholder 提示信息<br>disabled 禁止输入<br>readonly 只读<br>checked 默认选中<br>autofocus 自动获取焦点<br>autocomplete 自动完成<br>required 必填<br>maxlength 最大长度<br>min 最小值<br>max 最大值<br>step 步长<br>accept 文件类型<br>multiple 多选<br>size 宽度<br>list 列表<br>form 表单id<br> | 单 |行 |
| textarea | 多行文本框 | rows 行数<br>cols 列数<br>placeholder 提示信息<br>disabled 禁止输入<br>readonly 只读<br>autofocus 自动获取焦点<br>autocomplete 自动完成<br>required 必填<br>maxlength 最大长度<br>min 最小值<br>max 最大值<br>step 步长<br>list 列表<br>form 表单id<br> | 单 |行 |
| select | 下拉框 | name 标识<br>value 默认值<br>multiple 多选<br>size 显示行数<br>disabled 禁止选择<br>autofocus 自动获取焦点<br>autocomplete 自动完成<br>required 必填<br>list 列表<br>form 表单id<br> | 单 |行 |

## 结构元素

|元素名|解释|作用|
| - | - | -- |
| header | 头部 |放置logo、搜索框、菜单|
| nav | 导航 | 提供页面或网站的主要导航链接 |
| section | 节 | 表示文档中的独立部分，如章节、页眉、页脚等 |
| article | 文章 | 表示文档或页面中的独立内容，如新闻文章、博客条目等 |
| aside | 侧边栏 | 包含与主要内容相关但可以被独立出来的信息，如侧边栏 |
| footer | 底部 | 通常包含版权信息、联系信息等底部内容 |
| figure | 图片 | 用于标记图片、图表或其他媒体的内容 |
| figcaption | 图片标题 | 为figure元素内的内容提供标题或说明 |
|hgroup | 表格分组 | 表格分组，用于将表格中的行、列、表头等分组，以方便对表格进行样式设置 |

## 页面交互元素

|元素名|解释|属性值|作用|
| - | - | - |--|
| details | 详情 | |用于创建一个可以显示或隐藏详细信息的可折叠面板 |
| summary | 详情标题| | 作为details元素的标题，通常可点击以展开/折叠details内容 |
| progress | 进度条 |value 现有量<br>max 总量 |用于显示一个任务或操作的进度 |
| meter | 仪表盘 |optimum 定义最佳值 <br>min 最小值<br>max 最大值<br>low 低值<br>high 高值<br>value 现有值 |用于显示一个值在预定义范围中的位置，如进度条 |

## 特殊字符

| 符号 | 含义 | 实体名称 | 实体编号 |
| --- | --- | --- | --- |
| | 空格 | \&nbsp; | \&#160; |
| < | 小于号 | \&lt; | \&#60; |
| > | 大于号 | \&gt; | \&#62; |
| & | 和号 | \&amp; | \&#38; |
| " | 引号 | \&quot; | \&#34; |
| ` | 反引号 | \&acute; | \&#180; |
| £ | 英镑(pound) | \&pound; | \&#163; |
| ¥ | 元(yen) | \&yen; | \&#165; |
| € | 欧元(euro) | \&euro; | \&#8364; |
| © | 版权(copyright) | \&copy; | \&#169; |
| ® | 注册商标 | \&reg; | \&#174; |
| ™ | 商标 | \&trade; | \&#8482; |
| × | 乘号 | \&times; | \&#215; |
| ÷ | 除号 | \&divide; | \&#247; |

## 正则表达式

| 正则表达式 | 说明 | 示例 |
| --- | --- | --- |
| `^` | 匹配字符串的开始位置 | `^abc` 只匹配以 "abc" 开始的字符串 |
| `$` | 匹配字符串的结束位置 | `abc$` 只匹配以 "abc" 结束的字符串 |
| `.` | 匹配除换行符以外的任何单个字符 | `a.b` 匹配所有形如 "axb" 的字符串，其中 x 是任意字符 |
| `\d` | 匹配数字字符（等价于 `[0-9]`） | `\d+` 匹配一个或多个连续的数字 |
| `\D` | 匹配非数字字符 | `\D+` 匹配一个或多个连续的非数字字符 |
| `\w` | 匹配字母、数字、下划线（等价于 `[a-zA-Z0-9_]`） | `\w+` 匹配一个或多个连续的字母、数字或下划线 |
| `\W` | 匹配非字母、数字、下划线 | `\W+` 匹配一个或多个连续的非字母、非数字或非下划线字符 |
| `\s` | 匹配空白字符（包括空格、制表符、换页符等） | `\s+` 匹配一个或多个连续的空白字符 |
| `\S` | 匹配非空白字符 | `\S+` 匹配一个或多个连续的非空白字符 |
| `[abc]` | 匹配字符 a、b、c 中的任意一个 | `[abc]+` 匹配一个或多个连续的 a、b 或 c 字符 |
| `[^abc]` | 匹配非字符 a、b、c 中的任意一个 | `[^abc]+` 匹配一个或多个连续的非 a、非 b 或非 c 字符 |
| `[a-z]` | 匹配字符 a 到 z 之间的任意字符 | `[a-z]+` 匹配一个或多个连续的小写字母 |
| `[a-zA-Z]` | 匹配字符 a 到 z 或 A 到 Z 之间的任意字符 | `[a-zA-Z]+` 匹配一个或多个连续的大写或小写字母 |
| `[0-9]` | 匹配数字 0 到 9 之间的任意字符 | `[0-9]+` 匹配一个或多个连续的数字 |
| `\b` | 匹配单词边界 | `\bword\b` 只匹配完整的单词 "word" |
| `\B` | 匹配非单词边界 | `\Bword\B` 匹配嵌入在其他字符中的 "word" |
| `^\w{6,12}$` | 匹配长度为 6 到 12 位的字母、数字或下划线组成的密码 | `"abc123"`、`"password"` |
| `^\d{6}$` | 匹配长度为 6 位的数字组成的密码 | `"123456"` |
| `^\d{18}$` | 匹配长度为 18 位的身份证号码 | `"123456789012345678"` |
| `^\d{15}$` | 匹配长度为 15 位的旧版身份证号码 | `"123456789012345"` |
| `^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$` | 匹配标准的电子邮件地址 | `"example@example.com"` |
| `^\+\d{1,3}\d{10,15}$` | 匹配带国家区号的电话号码 | `"+8613800138000"` |
| `^\d{3}-\d{3}-\d{4}$` | 匹配美国电话号码格式 | `"123-456-7890"` |
| `^\d{3}-\d{8}$` | 匹配中国大陆固定电话号码格式 | `"010-12345678"` |
| `^\d{11}$` | 匹配中国大陆手机号码格式 | `"13800138000"` |
| `^\d{5}(?:[-\s]\d{4})?$` | 匹配美国邮政编码格式 | `"12345"`、`"12345-6789"` |
| `^\d{6}$` | 匹配中国邮政编码格式 | `"100000"` |
| `^(http|https)://[a-zA-Z0-9.-]+(?:/[a-zA-Z0-9._-]*)*$` | 匹配标准的 URL 地址 | `"http://www.example.com"` |

## 浏览器私有属性

| 浏览器 | 内核 | 私有前缀 |
| --- | --- | --- |
| **Google Chrome** | Blink | `-webkit-` |
| **Mozilla Firefox** | Gecko | `-moz-` |
| **Safari** | WebKit | `-webkit-` |
| **Microsoft Edge** (旧版本) | EdgeHTML | `-ms-` |
| **Microsoft Edge** (新版本) | Blink | `-webkit-` |
| **Internet Explorer** | Trident | `-ms-` |
| **Opera** | Blink | `-webkit-` |
| **Samsung Internet** | WebKit | `-webkit-` |
| **UC Browser** | WebKit/Blink | `-webkit-` |
| **QQ Browser** | WebKit/Blink | `-webkit-` |
| **360 Browser** | WebKit/Blink | `-webkit-` |
| **Maxthon** | WebKit/Blick | `-webkit-` |

---
未完待续……



