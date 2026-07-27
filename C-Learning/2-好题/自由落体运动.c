/**一球从M米高度自由下落，每次落地后返回原高度的一半，再落下。
它在第N次落地时反弹多高？共经过多少米？ 结果保留两位小数。**/

//它在第N次落地时反弹多高？共经过多少米？ 保留两位小数，空格隔开，放在一行。

//思路：m / 2,通过循环，迭代小球反弹高度，通过sum累加起小球走过的路程。通过h记录第n次反弹的高度，因此
//sum+=n*2；最终sum-m。
//变量：m,n,i,h,sum;

#include <stdio.h>
int main()
{
    double m;
    int n, i;
    double h, sum=0;
    int j, two;
    scanf("%lf%d", &m, &n);
    for(i=0; i<n; i++){
        for(j=1, two=1; j<=i; j++)   //通过改变i的初始值，获得第一次不执行该循环的效果。
            two = two * 2;           //two不要忘记初始化！！！！
        h = m / two;
        sum = sum+h*2;
    }
    printf("%.2f %.2f",h/2,sum-m);

    return 0;
}