//假设一排好序的数组，输入一个数，使其按照顺序插入数组中。
//例如：1, 2, 3, 4, 5， 输入n

#include <stdio.h>
int main()
{
    int num[6]={1, 2, 3, 4, 5};
    int n, t=5, i;
    scanf("%d", &n);
    for(i=0; i<=4; i++){
        if(n <= num[i]){
            t = i;
            break;
        }
    }

    for(i=4; i>=t; i--){
        num[i+1] = num[i];
    }
    num[t] = n;
    for(i=0; i<=5; i++){
        printf("%d", num[i]);
    }

    return 0;
}