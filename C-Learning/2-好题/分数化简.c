#include <stdio.h>
int gys(int a,int b); 
int main()
{
    int T,t,n,m,p=1;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
    	scanf("%d%d",&n,&m);
    	if(m==0)
    		printf("Error!\n");
        else if(n==0)
            printf("0\n");
    	else
    	{
    		if(m>=n)p=gys(m,n);
    		else p=gys(n,m);
    		if(p==m||p==n)printf("%d\n",p);
    		else printf("%d/%d\n",n/p,m/p);
		}
	}
    return 0;
}
int gys(int a,int b){
	if(b==0)
		return a;
	else
		return gys(b,a%b);
	}