
#include<stdio.h>
int main() {
  double i;// 利润
  double bonus = 0;// 奖金
  printf("当月利润是：");
  scanf("%lf", &i);// 输入当月利润
  double bonus1 = 100000 * 0.1;// 十万的奖金
  double bonus2 = bonus1 + 100000 * 0.075;// 二十万的奖金
  double bonus4 = bonus2 + 200000 * 0.05;// 四十万的奖金
  double bonus6 = bonus4 + 200000 * 0.03;// 六十万的奖金
  double bonus10 = bonus6 + 400000 * 0.015;// 一百万的奖金
  if (i <= 100000) {
    // 利润 i 低于或等于10万元时，奖金可提10%；
    bonus = i * 0.1;
  } else if (i <= 200000) {
    // 低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
    bonus = bonus1 + (i - 100000) * 0.075;
  } else if (i <= 400000) {
    // 20万到40万之间时，高于20万元的部分，可提成5%；
    bonus = bonus2 + (i - 200000) * 0.05;
  } else if (i <= 600000) {
    // 40万到60万之间时高于40万元的部分，可提成3%；
    bonus = bonus4 + (i - 400000) * 0.03;
  } else if (i <= 1000000) {
    // 60万到100万之间时，高于60万元的部分，可提成1.5%；
    bonus = bonus6 + (i - 600000) * 0.015;
  } else if (i > 1000000) {
    // 高于100万元时，超过100万元的部分按1%提成。
    bonus = bonus10 + (i - 1000000) * 0.01;
  }
  printf("应发奖金为：bonus=%lf", bonus);
  return 0;
}