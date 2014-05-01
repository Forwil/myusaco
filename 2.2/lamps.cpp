/*
ID: forwil11
PROG: lamps
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "lamps" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int ans[20],nans,n,m,k,dp[10001][16],now,on[101],off[101],non = 0,noff = 0;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void push(int &now,int x)
{
	if (x & 1)
	{
		now ^= 077;
	}
	if (x & 2)
	{
		now ^= 025;
	}	
	if (x & 4)
	{
		now ^= 052;
	}	
	if (x & 8)
	{
		now ^= 011;
	}	
}

int can(int now)
{
	for(int i=0;i<non;i++)
		if ((now & (1 << on[i])) == 0)
			return 0;	
	for(int i=0;i<noff;i++)
		if ((now & (1 << off[i])) != 0)
			return 0;	
	return 1;
}

void out(int now)
{
	for(int i=0;i<m;i++)
		fout << ((now & (1 << (i % 6))) > 0);
	fout << endl;
}

void add(int now)
{
	for(int i=0;i<nans;i++)
		if(now == ans[i])
			return;
	ans[nans++] = now;
}

int rev(int x)
{
	int v = 0;
	for(int i = 0;i < 6;i++)
	{
		v = (v << 1) + (x & 1);
		x = x >> 1;
	}		
	return v;
}

int cmp(int x,int y)
{
	return rev(x) < rev(y);
}

int main(void){
	int x,flag = 0;
	fin >> m >> n;
	dp[0][0] = 1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<16;j++)
	if(dp[i-1][j])
	{
		dp[i][j ^ 1] = 1;
		dp[i][j ^ 2] = 1;
		dp[i][j ^ 4] = 1;
		dp[i][j ^ 8] = 1;
	}	
	while(1)
	{
		fin >> x;
		if (x == -1)
			break;
		on[non++] = (x-1) % 6;
	}
	while(1)
	{
		fin >> x;
		if (x == -1)
			break;
		off[noff++] = (x-1) % 6;
	}

	now= 077;
	for(int i=0;i<16;i++)
	if(dp[n][i])
	{
	//	fout << i << endl;
		push(now,i);	
	//	out(now);
		if(can(now))
		{
			add(now);
			flag = 1;
		}
		push(now,i);
	}
	sort(ans,ans+nans,cmp);
	for(int i=0;i < nans;i++)
		out(ans[i]);
	if(!flag)
		fout << "IMPOSSIBLE" << endl;
	return 0;
}
