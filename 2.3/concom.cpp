/*
ID: forwil11
PROG: concom
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "concom" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,dis[105][105],con[105][105];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int a,b,c,ans = 0,flag = 1;
	fin >> m;
	n = 104;
	for(int i=0;i<m;i++)
	{
		fin >> a >> b >> c;
		dis[a][b] = c;
		if(c > 50)
			con[a][b] = 1;
	}

	for(int i=1;i<n;i++)
		con[i][i] = 1;

	while(flag)
	{	
		flag = 0;
		for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)if(con[i][j] == 0)
		{
			int x = 0;
			for(int k = 1;k<=n;k++)if(j!=k)
				if(con[i][k])
					x += dis[k][j];	
			if(x > 50)
			{
				flag = 1;
				con[i][j] = 1;
			}
		}
	}

	for(int i = 1;i<=n;i++)
	for(int j = 1;j<=n;j++)if(i!=j)
	if(con[i][j])
		fout << i << " " << j << endl;
	return 0;
}
