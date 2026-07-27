//输入一个大于3的整数n，判定它是否为素数(prime，又称质数)。

//思路：n%(n-1,n-2,...,2)!=0,则n是素数。

#include <stdio.h>
int main()
{
    int n,n_;
    scanf("%d",&n);
    n_ = n;
    n--;
    while(n_%n!=0)
        n--;
    if(n==1)
        printf("是素数");
    else
        printf("不是素数");

        return 0;
}

//或者使用for循环。

#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2; i<n; i++){
        if(n%i==0){
            printf("NOT");
            break;
        }
    }
    if(i==n)
        printf("YES");
    return 0;
}

