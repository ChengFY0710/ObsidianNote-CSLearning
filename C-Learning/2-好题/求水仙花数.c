//输出所有的 "水仙花数", 所谓 "水仙花数" 是指一个 3 位数，其各位数字立方和等于该数本身。
//例如，153 是水仙花数，因为 153=18+53+33。

//思路：三位数变量是 n， n = 100 ~ 999。循环提取每一位，sum累加。sum与该数比较。

#include <stdio.h>
int main()
{
    int n, n_, num, sum;
    int i;
    for(n=100, sum=0; n>=100 && n<=999; sum=0, n++){
    	n_ = n;                     //易错：求sum时会破坏n的值，要重新定义一个变量！！
        for(i=1; i<=3; num=0, i++){
            num = n_%10;
            sum += num*num*num;
            n_ = n_/10;
        }
        if(sum==n)
            printf("%d ", n);
    }
    return 0;
}

