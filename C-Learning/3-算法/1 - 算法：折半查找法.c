//折半查找法：一列排好序的数，从中间元素开始，
//若某一元素比中间元素大或小，则在中间元素的左边或右边查找

//有 15 个数按由大到小顺序存放在一个数组中，输入一个数，要求用折半查找法找出
//该数是数组中第几个元素的值。如果该数不在数组中，则输出 "无此数"。

//变量：num[15]、i、j、status、mid

#include <stdio.h>
int main()
{
    int num[15]={128, 115, 97, 83, 76, 69, 58, 45, 37, 29, 22, 18, 11, 7, 2};
    int n, mid=num[7], x=0;
    scanf("%d", &n);
    if(n==mid)
        x = 8;
    else if(n>mid){
        mid = num[3];
        if(n==mid)
            x = 4;
        else if(n>mid){
            mid = num[1];
                if(n==mid)
                    x = 2;
                else if(n>mid)
                    x = 1;
                else if(n<mid)
                    x = 3;
        }
        else if(n<mid){
            mid = num[5];
            if(n==mid)
                    x = 6;
                else if(n>mid)
                    x = 5;
                else if(n<mid)
                    x = 7;
        }
    }
    else if(n<mid){
        mid = num[11];
        if(n==mid)
            x = 12;
        else if(n>mid){
            mid = num[9];
                if(n==mid)
                    x = 10;
                else if(n>mid)
                    x = 9;
                else if(n<mid)
                    x = 11;
        }
        else if(n<mid){
            mid = num[13];
            if(n==mid)
                    x = 14;
                else if(n>mid)
                    x = 13;
                else if(n<mid)
                    x = 15;
        }
    }
    else
        printf("无此数");
    
    if(x!=0)
    	printf("%d", x);

    return 0;
}



//循环判断
#include <stdio.h>
int main()
{
    int num[15]={128, 115, 97, 83, 76, 69, 58, 45, 37, 29, 22, 18, 11, 7, 2};
    int mid, low=0, high=14, status=0;
    int n;
    scanf("%d", &n);
    while(low <= high){
        mid = (low + high)/2;
        if(n == num[mid]){
            printf("%d", mid+1);
            status = 1;
            break;
        }
        else if(n > num[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if(status == 0)
        printf("无此数");
    return 0;
}

// 要求有相同时，输出最小的位数。
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int num[n];
	int res[n];
	int i, j=0;
	int left=0, right=n-1, mid;
	int s, result;
	for(i=0; i<n; i++){
		scanf("%d", &num[i]);
		res[i] = 0;
	}
	scanf("%d", &s);
	while(left <= right){
		mid = (left+right)/2;
		if(num[mid] == s){
			result = mid + 1;
			res[j] = mid+1;
			j++;
			right = mid-1;
			continue;
		}
		if(num[mid] > s)
			right = mid - 1;
		else
			left = mid + 1;
	}
	for(i=0; i<n; i++){
        if(res[i]!=0)
            result = result < res[i]+1 ? result : res[i]+1;
	}
	if(res[0] != 0) printf("%d", result);
	else printf("None");

	return 0;
 }