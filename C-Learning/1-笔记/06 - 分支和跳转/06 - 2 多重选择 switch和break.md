有时，我们会需要多重选择，但是使用许多if else会太麻烦，而使用switch语句会大大简化流程。
```c
//快递费用的计算
#include <stdio.h>
int main()
{
    int area;
    double weight,a,b;
    scanf("%d,%lf",&area,&weight);
    switch(area)
    {
        case 0:a=10;b=3;break;
        case 1:a=10;b=4;break;
        case 2:a=15;b=5;break;
        case 3:a=15;b=6.5;break;
        case 4:a=15;b=10;break;
        default:printf("Error in Area\n");
    }
    if(area>6||area<0)
        printf("Price:  0.00");
    else if(weight<=1)
        printf("Price: %.2f\n",a);
    else if(weight != (int)weight)
        weight = (int)weight + 1;
    printf("Price: %.2f\n",a+(weight-1)*b);
    return 0;
}
```

---

## 01 基本结构
```c
switch(表达式){
    case 常量 : 语句; break;
    ...
    default:语句;
}
```
### （1）对表达式的要求
switch(表达式)中表达式的值应该是==**整数值（包括char类型）**==。case标签（常量）必须是==**整数类型（包括char类型）**或**整型常量表达式**==。
>[!warning]
>不能使用变量作为case的标签！！
### （2）break和default
break语句的作用是，结束执行后面的语句，直接跳到defult后面的语句。defult语句也可以没有。
### （3）case后语句的要求
case后的语句可以是多个，也可以没有。

## 02 执行顺序
通过扫描case标签，找到与switch后表达式相同的标签，若未找，则顺理执行default，找到后，若有break语句，则程序会跳转至default或结束switch，若没有则==**会停止判断case标签，顺序执行下面语句，直到遇到break**==。

## 03 多重标签
```c
switch(ch){
    case 'a':
    case 'A':i++;break;

    case 'b':
    case 'B':i++;break;
}
```
如上，可以利用switch的执行顺序，实现多重标签。