#include <stdio.h>
int main(){
    double  i,j;
    scanf("%lf",&i);
    if(i>0){
        if(i<=100000){
            j = i*1.1;
            printf("%.0lf",j);
        }else if(100000<i<=200000){
            j = (i-100000)*1.075 + 100000*1.1;
            printf("%.0lf",j);
        }else if(200000<i<=400000){
            j = (i-100000)*1.05 + 100000*1.1 + 100000*1.075;
            printf("%.0lf",j);
        }else if(400000<i<=600000){
            j = (i-100000)*1.03 + 100000*1.1 + 100000*1.075 + 200000*1.05;
            printf("%.0lf",j);
        }else if(600000<i<=1000000){
            j = (i-100000)*1.015 + 100000*1.1+ 100000*1.075 + 200000*1.05 + 200000*1.03;
            printf("%.0lf",j);
        }else if(1000000<i){
            j = (i-100000)*1.01 + 100000*1.1+ 100000*1.075 + 200000*1.05 + 200000*1.03 + 400000*1.015;
            printf("%.0lf",j);
        }
    }
    return 0;
}
