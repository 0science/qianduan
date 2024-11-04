## 入门

## 语法

## 数组

### 创建数组

#### 使用new Array()

```
  // 元素值类型为字符型
  var area = new Array('Beijing', 'Shanghai', 'Shenzhen');
  // 元素值类型为数值型
  var score = new Array(56, 68, 98, 44);
  // 元素值类型为混合型
  var mix = new Array(123, 'abc', null, true, undefined);
  // 空数组
  var arr1 = new Array();  // 或 var arr2 = new Array;
```

#### 使用 [ ]

```
var weather = ['wind', 'fine',];      // 相当于：new Array('wind', 'fine',)
var empty = [];                       // 相当于：new Array
var mood = ['sad', , , ,'happy'];     // 控制台输出mood：(5) ["sad", empty × 3, "happy"]
```

### 数组基本操作

#### 获取数组长度
使用.length

```
var arr1 = [78, 88, 98];
var arr2 = ['a', , , , 'b', 'c'];
console.log(arr1.length);   // 输出结果为：3
console.log(arr2.length);   // 输出结果为：6
```

#### 设置数组长度
使用.length并初始化
大于留空
小于删除

```
var arr1 = [];
arr1.length = 5;
console.log(arr1);      // 输出结果：(5) [empty × 5]
var arr2 = [1, 2, 3];
arr2.length = 4; 
console.log(arr2);      // 输出结果：(4) [1, 2, 3, empty]
var arr3 = ['a', 'b'];
arr3.length = 2; 
console.log(arr3);      // 输出结果：(2) ["a", "b"]
var arr4 = ['hehe', 'xixi', 'gugu', 'jiujiu'];
arr4.length = 3; 
console.log(arr4);      // 输出结果：(3) ["hehe", "xixi", "gugu"]
```


#### 访问数组
使用 数组名\[下标]的方式

```
var arr = ['hello', 'JavaScript', 22.48, true];
console.log(arr[0]);
console.log(arr[2]);
console.log(arr);
```

#### 遍历数组
for in 循环
```
var navlistArr = ['首页','新闻','关于'];
var str = '<ul>';
for(var i in navlistArr){
    str += '<li><a>'+ navlistArr[i] +'</a></li>';
}
str += '</ul>';
document.getElementById('navlist').innerHTML = str;
```

#### 增加元素


#### 修改元素


#### 删除元素 

### 数组属性与方法



## 函数

## 对象

## BOM

## DOM

## 事件

## 正则表达式

## Ajax

## jQuery


