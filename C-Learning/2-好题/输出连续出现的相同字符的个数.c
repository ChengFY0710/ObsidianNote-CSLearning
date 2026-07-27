//1.(12分)请编写一个程序,对给定的一个字符串(仅含字母,长度不超过100),
//统计其中连续出现的相同字符个数,并转换为"字母+数量"格式输出。例如,
//输入"AAABBBCCCab",输出"A3 B3 C3 a1 b1 "。

#include <stdio.h>
int main()
{
    char now, next;
    int times=1;
    now = getchar();
    while((next = getchar()) != EOF){
        if(now == next)
            times++;
        else{
            printf("%c%d", now, times);
            now = next;
            times = 1;
        }
    }

    return 0;
}