/**输入描述
输入两个正整数a和b，0≤a,b≤2,000,000,000

输出描述
输出没有进位情况下加法的结果。
PS：类似125 +932的情况，输出的数的首位不能为0，即125 + 932 =57；类似5555 + 5555的情况输出只有一个0。
**/

//思路：提取两个数的同位，进行相加，再取个位数。由于要正向输出，因此要获取两个数的位数信息，n1,n2。
//提取二者中更大的那个数，利用循环，依次提取相加，其中，若相加的结果为0，则不输出。
//变量：a,b,n1,n2,n,i(计数器),num


#include <stdio.h>
int main()
{
    int a,b;
    int a1,b1,n1,n2,n;
    int i,j,t,num1,num2,sum;
    int ten=1;
    int zero=0;
    scanf("%d%d",&a,&b);
    a1 = a;
    b1 = b;
    n1 = 0;
    while(a1!=0){     //此刻会破坏变量a的值，要另做存储。
        n1++;
        a1 = a1/10;
    }
    n2 = 0;
    while(b1!=0){
        n2++;
        b1 = b1/10;
    }                 //获取了ab两数的位数n1，n2。
    n = n1>n2 ? n1: n2;     //提取更大者。  
    t = n-1;
    for(i=1; i<=n; i++){
        for(j=1,ten=1; j<=t; j++)
            ten = ten*10;
        num1 = (a/ten)%10;
        num2 = (b/ten)%10;
        sum = (num1+num2)%10;
        if(sum!=0)
        zero=1; 
        if(sum==0&&zero==0) ;
        else printf("%d",sum);
        t -= 1;
    }
    if(zero==0)printf("0");

    return 0;
}


// 思路2：从个位开始提取，之后逐渐*10提到对应位，最后累加，直到x==0。
//变量：a,b,i

#include <stdio.h>
int main()
{
    int a,b,num,sum=0;
    int i,j,n=0;
    scanf("%d%d",&a,&b);
    while(a!=0||b!=0){
        num = (a%10 + b%10)%10;
        a = a/10;
        b = b/10;
        for(i=1,j=1; i<=n; i++)  //对进位的处理。
            j = j*10;
        sum = sum + num*j;
        n++;    
    }
    printf("%d",sum);

    return 0;
}