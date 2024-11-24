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