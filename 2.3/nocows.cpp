/*
ID: forwil11
PROG: nocows
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "nocows" 
#define MAXN 200
#define MOD 9901
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,sum[MAXN + 2][MAXN + 2];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int get_now(int x,int y)
{
	if(y)
		return (sum[x][y] - sum[x][y-1] + MOD)%MOD;
	else
		return sum[x][y];	
}

int main(void){
	int x,ans = 0;
	fin >> n >> m;
	for(int j = 0;j<=m;j++)
	{
		sum[0][j] = 1;
		if(j >= 1)
			sum[1][j] = 1;
	}
	for(int i=2;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int x;
		x = 0;
		if(j<=i)
			for(int k = 1;k<=i-2;k++)
			{
				int l = k;
				int r = i - 1 - k;
				x +=(get_now(l,j-1)*((j>=2)?sum[r][j-2]:0)+
				   	get_now(r,j-1)*((j>=2)?sum[l][j-2]:0)+
					get_now(l,j-1)*get_now(r,j-1)) % MOD; 	
//			cout <<i <<" " <<j<<" " << k<<":"<<x << endl;
			}
		sum[i][j] = (sum[i][j-1] + x) % MOD;
	}
	fout << get_now(n,m) << endl;
	return 0;
}
