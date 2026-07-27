//键盘输入正整数a和n，编程 s=a+aa+aaa+aaaa+aa...a（n个a）的值。

//思路：通过循环，累加s,内部循环求a。
//变量：a,n,num,sum,i,j
#include <stdio.h>
int main()
{
    int a, n, num, sum=0;
    int i, j, ten;
    scanf("%d%d", &a, &n);
    for(i=0; i<n; i++){
        for(j=1, ten=1, num=a; j<=i; j++){
            ten *= 10;
            num += ten*a;
        }
        sum += num;
    }
    printf("%d",sum);
    
    return 0;
}