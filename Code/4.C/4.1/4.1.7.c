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