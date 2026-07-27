//有通项公式：an=1/n+1+2/n+1+.......+n/n+1,求Sn
//思路：先求an，再通过循环，累加Sn。因此设计两个循环的嵌套。
//注意：两个循环的计数变量要分开，因为外层循环计数变量的重置只执行一次。可以用i，j，k，l进行。

#include <stdio.h>
int main()
{
    int i, j;
    int n;
    double an,sn;
    scanf("%d", &n);
    for(i=1, i<=n, i++){
        for(j=1, j<=i, j++)
            an += j*1.0/(i+1);
        sn += an;
    }
    printf(".4f",sn);

    return 0;
}

//注意⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️
//double = int/int
//不对，此刻会舍弃小数部分，应改为 double = int * 1.0/int
//将除法赋值给浮点类型的变量时一定要注意！！！！