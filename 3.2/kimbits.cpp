/*
ID: forwil11
PROG: kimbits
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "kimbits" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

unsigned int n,m,l,comb[50][50];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	unsigned int x,ans = 0;
	fin >> n >> m >> l;
	comb[0][0] = 1;
	for(int i = 1;i<=n;i++)
	{
		comb[i][0] = 1;
		for(int j = 1;j<=m;j++)
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
	}

	for(int i = 0;i<n;i++)	
	{
		unsigned int z;
		z = 0;
		for(int j = 0;j <=m;j++)
			z += comb[n - i - 1][j];
		if (l > z)
		{
			l = l - z;
			m -= 1;
			fout << 1;
		}
		else
			fout << 0;	
	}
	fout << endl;
	return 0;
}
