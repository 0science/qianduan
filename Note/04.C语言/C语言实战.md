[TOC]

经典100题

## 第一题：输出无重复的三位数
题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？

思路：用多重循环，穷举所有情况，再用条件判断语句筛选出符合条件的数。

代码：

```
#include <stdio.h>
int main(){
    int count=0;
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            for(int k=1;k<5;k++){
                if(i!=j&&i!=k&&j!=k){
                    printf("%d,%d,%d\n",i,j,k);
                    count = count + 1;
                }

                
            }
        }
    }
    printf("个数为：%d\n",count);
    return 0;
}
```

## 第二题：输出杨辉三角