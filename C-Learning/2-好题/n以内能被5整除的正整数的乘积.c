//求解出n以内(包含n)所有能被5整除的正整数数的乘积s
/** 输入
输入包含多个样例，每个样例一个正整数n，占一行。读取到文件结尾。输入的n不超过100。
输入格式
scanf("%d", &n) 
输出
对于每个样例n，输出n以内（包含n）所有能被5整除的正整数的乘积。
输出格式
printf("%d\n", s); **/

//思路：构造一循环，n循环递减，直到5，每次循环内判断是否能被5整除，累乘s。

#include <stdio.h>
int main()
{
    int n, n_, s=1;
    scanf("%d", &n);
    n_ = n;
    while(n>=5){
        if(n%5==0)
            s *= n;
        n--;
    }
    if(n_<5)
        printf("0\n");
    else
        printf("%d\n",s);

        return 0;
}
