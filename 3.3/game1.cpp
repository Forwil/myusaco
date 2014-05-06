/*
ID: forwil11
PROG: game1
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "game1" 
#define MAXN 101
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

int n,m,dp[MAXN][MAXN],arr[MAXN],sum[MAXN];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = 0;
	fin >> n;
	for(int i=1;i<=n;i++)
	{
		fin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
		dp[i][i] = arr[i];
	}
	for(int k=1;k<n;k++)
	for(int i=1;i+k<=n;i++)
		dp[i][i+k] = MAX(arr[i] + (sum[i+k] - sum[i]) - dp[i+1][i+k],
						arr[i+k] + (sum[i+k-1] - sum[i-1]) - dp[i][i+k-1]); 	
	fout << dp[1][n] << " " << sum[n] - dp[1][n]<< endl;
	return 0;
}
