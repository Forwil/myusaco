/*
ID: forwil11
PROG: range
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "range" 
#define MAXN 252
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

int n,m,sum[MAXN][MAXN],ans[MAXN];
string arr[MAXN];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x;
	fin >> n;
	for(int i=0;i<n;i++)
	{
		fin >> arr[i];
		for(int j=0;j<n;j++)
		{
			sum[i][j] = (arr[i][j] == '1');
			if(i)
				sum[i][j] += sum[i-1][j];
			if(j)
				sum[i][j] += sum[i][j-1];
			if(i && j)
				sum[i][j] -= sum[i-1][j-1];
			for(int k = 1;k<=MIN(i+1,j+1);k++)
			{
				int x = sum[i][j];
				if(i >= k)	
					x -= sum[i-k][j];
				if(j >= k)
					x -= sum[i][j-k];
				if(i >=k && j >=k)
					x += sum[i-k][j-k];
//				cout << "i " <<i << " j "<<j << " k " << k <<" s" << x << endl;
				if(x == k*k)
					ans[k] += 1;	
				else
					break;
			}
		}
	}
	for(int i=2;i<=n;i++)
	if(ans[i])
		fout <<i<< " "<<ans[i] <<endl;
	return 0;
}
