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