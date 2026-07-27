//(14分)请编写一个程序,对给定的若干个0~9数字,进行排列使得到的正整数尽可能小(0不能做首位数字)。
//输入格式:第一行给出数字个数n(n<100);第二行给出0~9范围内的n个数字(至少含1个非0数字),中间用一个空格分隔。
//输出格式:给出可构成的最小正整数。
//输入样例:
//10
//2405030210
//输出样例:
//1000022345

#include <stdio.h>
int main()
{
	int n;
	int f, i, j;
	int b=1;
	scanf("%d", &n);
	int num[n]; 
	for(i=0; i<n; i++)
		scanf("%d", &num[i]);
	for(f=1; f<=9; f++){
		for(i=0; i<n; i++){
			if(num[i]==f){
				printf("%d", num[i]);
				num[i] = -1;
				b = 0;
				break;
			}
		}
		if(b==0) break;
	}
	for(j=2; j<=n; j++){
		for(f=0, b=1; f<=9; f++){
			for(i=0; i<n; i++){
				if(num[i]==f){
					printf("%d", num[i]);
					num[i] = -1;
					b = 0;
					break;
				}
			}
			if(b==0) break;
		}
	}
	
	return 0;
} 