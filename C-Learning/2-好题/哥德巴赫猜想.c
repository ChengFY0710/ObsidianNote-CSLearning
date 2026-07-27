
#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    int i;
    for(i=2; i<num; i++){
        if(num%i == 0) return 0;
    }
    if(num>=2) return 1;
    else return 0;
}

void OddDiv(int n)
{
    int i, j;
    for(i=2; i<=n-2; i++){
        for(j=2; j<=n-2; j++){
            if(isPrime(i) * isPrime(j) * isPrime(n-i-j) != 0){
                printf("%d=%d+%d+%d", n, i, j, n-i-j);
                return ;
            }
        }
    }
}

void EvenDiv(int n)
{
    int i;
    for(i=2; i<=n-2; i++){
        if(isPrime(i) * isPrime(n-i) != 0){
            printf("%d=%d+%d", n, i, n-i);
            break;
        }
    }
}

int main()
{
  int n;
  scanf("%d", &n);
  (n % 2 == 0) ? EvenDiv(n) : OddDiv(n);
  return 0;
}

//核心思想：拆分时，可以变量分割。判断分割后每个部分的属性之后输出。