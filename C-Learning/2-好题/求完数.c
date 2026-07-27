// 一个数如果恰好等于它的因子之和，这个数就称为 "完数"。
// 例如，6 的因子为 1,2,3, 而 6=1+2+3, 因此 6 是 "完数"。
// 编程序找出 1000 之内的所有完数，并按下面格式输出
// 6 its factors are 1,2,3

#include <stdio.h>
int main()
{
    int n, num, sum=0;
    int i,j;
    for(n=1; n<=1000; sum=0, n++){
        for(i=1; i<n; i++){
            if(n%i==0)
                sum += i;
        }
        if(sum==n){
            printf("%d its factors are ", n);
            for(j=1; j<n; j++){
                if(n%j==0)
                    printf("%d,", j);
            }
            printf("\b ");
        }        
    }

    return 0;
}