#include <stdio.h>
#include <string.h>
int main()
{
    char str1[200001], str2[200001];
    int len1, len2;
    int left, right, sum=0;
    int i, n;
    int a, b, s, status=0;
    scanf("%d", &n);
    for(i=1; i<=n; sum=0, i++){
        scanf("%s", str1);
        scanf("%s", str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        left=0;
        right=len2-1;
        while(str1[right] != '\0'){
            status = 0;
            for(a=left, b=right, s=0; a<=b; s++, a++){
                if(str1[a] != str2[s]){
                    left++;
                    right++;
                    status = 1;
                    break;
                }
            }
            if(status == 0){
                sum++;
                left += len2;
                right += len2;   //注意越界问题，由于字符串长度不超过100000，故原始定义str1， str2都是两倍。
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}