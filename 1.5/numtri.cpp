/*
ID: forwil11
PROG: numtri
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "numtri" 
#define MAXN 1000
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std; 

int n,dp[MAXN + 1][MAXN + 1];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int m,x,ans = 0;
	fin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			fin >> x;	
			dp[i][j] = MAX(dp[i-1][j-1],dp[i-1][j])	+ x;
//			fout << dp[i][j] << ":" << x << " ";	
			ans = MAX(dp[i][j],ans);
		}
//		fout << endl;
	}
	fout << ans << endl;
	return 0;
}
