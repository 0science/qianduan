#include<stdio.h>
void AddOne()
{
    static int i = 0;
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