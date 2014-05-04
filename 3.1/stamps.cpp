/*
ID: forwil11
PROG: stamps
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "stamps" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

int n,m,arr[60],arr_max,top;
char f[5000000];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void count(int &maxv)
{
	int tt = 0;
	for(int i =top;i>=MAX(0,maxv - arr_max);i--)
	if(f[i])
		for(int j = 0;j<n;j++)
		{
			f[i + arr[j]] = 1;
			tt = MAX(tt,i + arr[j]);
//			cout << i <<endl;
		}
	while(f[maxv])
		maxv += 1;
	top = tt;
}

int main(void){
	int x,ans = 0,maxv;
	fin >> m >> n;
	for(int i =0;i<n;i++)
	{
		fin >> arr[i];
		arr_max = MAX(arr_max,arr[i]);
	}
	f[0] = 1;		
	top = 0;
	maxv = 1;
	for(int i =0;i<m;i++)
	{
		count(maxv);
//		cout << i + 1<<" "<<maxv << endl;
	}
	fout << maxv - 1 << endl;
	return 0;
}
