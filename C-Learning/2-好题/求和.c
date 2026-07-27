//编写一个小程序，输入整数n，求S=1+(1+2)+…+(1+2+3+…+n)的值。

//思路：变量a，a=1+2+3+...+n,通过循环求a,s不断累加。
//由于n可以是正，可以是负，可以是0，负数可以变为正数处理。

#include <stdio.h>
int main()
{
    int i, n, a=0, s=0;
    int n_;
    scanf("%d", &n);
    n_ = n;
    n = n>0 ? n : -n;  //确保n为正数。
    for(i=1; i<=n; i++){
        a += i;
        s += a;
    }
    if(n_<=0)
        printf("%d",-s);
    else
        printf("%d",s);

    return 0;
}