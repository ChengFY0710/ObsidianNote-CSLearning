//输入两个正整数m和n，求其最大公约数和最小公倍数。

//最大公约数：
//用两个数字中较大的数除以较小的数，若能整除，则该数即为最大公约数。若不能整除，则-1，
//此时，若两个数都能被其整除，则该数即为最大公约数，直到减到1。

#include <stdio.h>
int main()
{
    int a, b, num;
    scanf("%d%d", &a, &b);
    if(a<b){
        a = a+b;
        b = a-b;
        a = a-b;
    }
    num = b;
    while(num>=1){
        if(a%num==0 && b%num == 0)
            break;
        num--;
    }
    if(b==0)
        printf("Error!");
    else
        printf("最大公约数是：%d", num);

    return 0;
}


//辗转相除法：用较小的数和两数相除的余数不断循环，直到一数为0，另一数即为最大公因数。

#include <stdio.h>
int main()
{
    int a,b;
    int y;
    scanf("%d%d", &a, &b);
    if(a==0||b==0)
        printf("Error!");
    else{
        if(a<b){
        a = a+b;
        b = a-b;
        a = a-b;
        }
        y = a%b;
        while(y!=0){
            a = b;
            b = y;
            y = a%b;
        }
        printf("最大公约数是：%d", b);
    }
    
    return 0;
}


//函数方式实现辗转相除法。
//函数部分：

int gys(int a,int b){
	if(b==0)
		return a;
	else
		return gys(b,a%b);
	}

//用两个数中较小的数，和，较大的数%较小的数，求余数。
//最后 return gys(b,a%b);

//最小公倍数通常用最大公约数的方法求：
//⚠️：两个数的乘积=最大公约数*最小公倍数
//所以，最小公倍数=a*b/gys

//最大公约数和最小公倍数

#include <stdio.h>
int main()
{
    int a,b;
    int y,j;
    scanf("%d%d", &a, &b);
    if(a==0||b==0)
        printf("Error!");
    else{
        if(a<b){
        a = a+b;
        b = a-b;
        a = a-b;
        }
        y = a%b;
        j = a*b;
        while(y!=0){
            a = b;
            b = y;
            y = a%b;
        }
        printf("最大公约数是:%d\n", b);
    }
    printf("最小公倍数是:%d", j/b);

    return 0;
}