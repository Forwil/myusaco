/*
ID: forwil11
PROG: sort3
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "sort3" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,counter[4],fc[4][4],arr[1002];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	
int isin(int i)
{
	if(i>=1 && i<=counter[1])
	{
		return 1;	
	}
	if(i>=counter[1]+1 && i<=counter[1]+counter[2])
	{
		return 2;	
	}
	if(i>=counter[1]+counter[2]+1)
	{
		return 3;
	}
}
int main(void){
	int m,x,ans = 0;
	fin >> n;
	for(int i = 1;i<=n;i++)
	{
		fin >> arr[i];
		counter[arr[i]] += 1;
	}
	for(int i = 1;i<=n;i++)
	{
		int t = isin(i);
		fc[t][arr[i]] += 1;	
	}	

	for(int i = 1;i<=3;i++)
	for(int j = i+1;j<=3;j++)
	{
		int t = MIN(fc[i][j],fc[j][i]);
		fc[i][j] -= t;
		fc[j][j] += t;
		fc[j][i] -= t;
		fc[i][i] += t;
		ans += t;
	}	
	ans += 2*(counter[1] - fc[1][1]);
	fout << ans << endl;
	return 0;
}
