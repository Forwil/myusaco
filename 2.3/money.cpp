/*
ID: forwil11
PROG: money
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "money" 
#define MAXM 10001

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,arr[30];
long long f[MAXM];
ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = 0;
	fin >> n >> m;
	for(int i=0;i<n;i++)
		fin >> arr[i];
	
	f[0] = 1;
	for(int i=0;i<n;i++)
	for(int j=0;j<=m - arr[i];j++)
	if(f[j])
		f[j + arr[i]] += f[j];	

	fout << f[m] << endl;
	return 0;
}
