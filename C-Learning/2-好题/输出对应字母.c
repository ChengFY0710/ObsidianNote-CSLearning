//输入一个正整数，然后从个位开始一次输出每一位数字对应的英文字母。例如：输入1532，输出two three five one。

/**输入描述
第一行输入一个T，代表有T组测试数据，T<100
对于每一组测试数据，输入一个整数x（0<x<100,000,000）

输出描述
对于每一组测试数据，输出对应结果，每个结果占一行，行末有空格
**/

/**思路：外层循环，实现测试T组数据，外层循环计数变量i。循环内，scanf读取输入整数x。
逐层提取个位，十位...，直到x==0。
数字num = x%10；
每一位下提取的数字num，通过switch输出对应英文单词。
x = x/10 转到下一位提取
以上实现内层循环。由于循环的具体次数难以确定，使用while循环。
用到变量：i,T,x,num
**/

#include <stdio.h>
int main()
{
    int i, T;
    int x, num;
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d", &x);
        if(x==0)
            printf("zero ");
        while(x!=0){
            num = x%10;
            switch(num){
                case 0: printf("zero ");  break;
                case 1: printf("one ");   break;
                case 2: printf("two ");   break;
                case 3: printf("three "); break;
                case 4: printf("four ");  break;
                case 5: printf("five ");  break;
                case 6: printf("six ");   break;
                case 7: printf("seven "); break;
                case 8: printf("eight "); break;
                case 9: printf("nine ");  break;
            }
            x = x/10;
        }
    }

    return 0;
}


//拓展：求数字位数

//思路：计数器i，通过循环，x = x/10;直到x==0;循环次数不确定，使用while循环。
i = 0;
while(x!=0){
    i++;
    x = x/10;
}
