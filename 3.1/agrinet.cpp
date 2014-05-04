/*
ID: forwil11
PROG: agrinet
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "agrinet" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,mat[105][105],p[105];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = 0;
	fin >> n;
	for(int i =0;i<n;i++)
	for(int j =0;j<n;j++)
		fin >> mat[i][j];
	for(int i =1;i<n;i++)
		p[i] = mat[0][i];
	for(int i =0;i<n;i++)
	{
		int k = 0,min = 1 << 30;
		for(int j=0;j<n;j++)
		if(p[j]!=-1 && p[j] < min)
		{
			min = p[j];
			k = j;
		}
		ans += min;
		p[k] = -1;
		for(int j=0;j<n;j++)
		if(p[j] > mat[k][j])
			p[j] = mat[k][j];	
	}		
	fout << ans << endl;
	return 0;
}
