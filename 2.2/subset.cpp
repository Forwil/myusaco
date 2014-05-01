/*
ID: forwil11
PROG: subset
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "subset" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

#define MAXL 1000

using namespace std; 

int n,m;
long long dp[MAXL];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = 0;
	fin >> n;
	dp[0] = 1;
	for(int i=1;i<=n;i++)
	for(int j=MAXL-i-1;j>=0;j--)
	if(dp[j])
			dp[j + i] += dp[j];	
	
	if (n*(n + 1)/2 % 2 == 0)
		fout << dp[n*(n+1)/2/2] / 2 << endl;
	else
		fout << 0 << endl;
	return 0;
}
