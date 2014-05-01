/*
 ID: forwil11
 LANG: C
 PROG: checker
*/

#include<stdio.h>
#define M (1 << n)
int n,count,ans[20];
void go(int now,int h,int l,int r)
{
	int bs,c,i;
	if (now == n)
	{
		count += 1;
		if(count <= 3)
		{
			for(i = 0;i<n-1;i++)
				printf("%d ",ans[i]);	
			printf("%d\n",ans[n-1]);
		}	
		return ;	
	}
	c = 0;
	for(bs = 1;bs < M; bs = bs << 1)
	{
		c += 1;
		if(((h | l | r) & bs) == 0)
		{
			ans[now] = c;
			go(now + 1, h | bs, (l | bs) << 1 , (r | bs) >> 1);
		}
	}
}

int main(void)
{
freopen("checker.in","r",stdin);
freopen("checker.out","w", stdout);
	scanf("%d",&n);
	go(0,0,0,0);
	printf("%d\n",count);	
	return 0;
}
