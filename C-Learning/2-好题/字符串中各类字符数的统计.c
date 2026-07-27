//输入一行字符，分别统计出其中英文字母、数字、空格和其他字符的个数。

//利用循环getchar函数，连续读取一串字符，通过ASCII码值判断，累加各字符个数。
//变量：eng,num,spa,oth,i

#include <stdio.h>
int main()
{
    char i;
    int eng=0,num=0,spa=0,oth=0;
    while((i=getchar()) != '\n'){
        if((i>=65&&i<=90)||(i>=97&&i<=122))
            eng++;
        else if(i>=48&&i<=57)
            num++;
        else if(i==32)
            spa++;
        else
            oth++;
    }
    printf("%d %d %d %d",eng,num,spa,oth);
    
    return 0;
}