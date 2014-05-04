/*
ID: forwil11
PROG: comehome
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "comehome" 

#define MAXV 0x3f3f3f3f

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int my_map(char c)
{
	if (c >='A' && c<= 'Z')
		return c - 'A';
	if (c >='a' && c<= 'z')
		return c - 'a' + 26;
}
char map_back(int i)
{
	if(i >=0 && i < 26)
		return i + 'A';
	return i + 'a';
}
int dis[100][100];
int main(void){
	int x,ans = 0;
	char a,b;
	fin >> n;
	memset(dis,0x3f,sizeof(dis));
	for(int i = 0;i<n;i++)
	{
		int aa,bb;
		fin >> a >> b >> x;
		aa = my_map(a);
		bb = my_map(b);
		if(dis[aa][bb] > x)
		{
			dis[aa][bb] = x;
			dis[bb][aa] = x;
		}
	}
	for(int k=0;k<26*2;k++)
	for(int i=0;i<26*2;i++)if(i!=k)
	for(int j=0;j<26*2;j++)if(i!=j && k!=j)
	if(dis[i][j] > dis[i][k] + dis[k][j])
		dis[i][j] = dis[i][k] + dis[k][j];

	ans = MAXV;
	for(int i=0;i<26-1;i++)
		if(ans > dis[i][25])
		{
			ans = dis[i][25];	
			x = i;
		}
	fout << map_back(x) << " "<< ans<< endl;
	return 0;
}
