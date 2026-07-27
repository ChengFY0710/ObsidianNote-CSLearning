//思路：运用数组，依次将各个素数的倍数赋值为0。直到sqrt(100)，即与下一个素数相乘>100时。
//变量：数组num, i。

#include <stdio.h>
int main()
{
    int num[101];
    int i;
    for(i=1; i<=100; i++){
        num[i] = i;
    }
    for(i=1; i<=100; i++){
        if(i%2==0)
            num[i] = 0;
        else if(i%3==0)
            num[i] = 0;
        else if(i%5==0)
            num[i] = 0;
        else if(i%7==0)
            num[i] = 0;
    }
    printf("2\n3\n5\n7\n");
    for(i=1; i<=100; i++){
        if(num[i]!=0&&num[i]!=1)
            printf("%d\n", num[i]);
    }

    return 0;
}



//优化逻辑：往后找倍数。
#include <stdio.h>
int main()
{
    int num[101];
    int i, j;
    for(i=2; i<=100; i++){       //i从2开始，使num[0],num[1]=0，方便后面输出。
        num[i]=i;
    }
    for(i=2; i<=10; i++){
        for(j=i+1; j<=100; j++){
            if(num[j]!=0 && num[i]!=0 && num[j]%num[i]==0)
                num[j] = 0;
        }
    }
    for(i=0; i<=100; i++){
		if(num[i]!=0)	
        	printf("%d\n", num[i]);
    }

    return 0;
}


//函数版本
#include <stdio.h>
#include <math.h>
#define N 100

void PrintPrime(int a[], int n);
void SiftPrime(int a[], int n);

int main()
{
	int a[N+1];
	SiftPrime(a, N);
	PrintPrime(a, N);
	return 0;
}

void SiftPrime(int a[], int n)
{
	int i, j;
	for(i=2; i<=n; i++){
		a[i] = i;
	}
	for(i=2; i<=sqrt(n); i++){
		for(j=i+1; j<=n; j++){
			if(a[i]!=0 && a[j]!=0 && a[j]%a[i]==0)
				a[j]=0;
		}
	}
}

void PrintPrime(int a[], int n)
{
	int i;
	for(i=2; i<=n; i++){
		if(a[i]!=0)
			printf("%d\n", a[i]);
	}
}