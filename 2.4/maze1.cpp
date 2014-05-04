/*
ID: forwil11
PROG: maze1
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "maze1" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,minv[300][100],mat[300][100];
string arr[300];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int cal(int x,int y)
{
	int v = 0;	
	if(arr[x-1][y] == '-')
		v |= 1;
	if(arr[x][y+1] == '|')
		v |= 2;
	if(arr[x+1][y] == '-')
		v |= 4;
	if(arr[x][y-1] == '|')
		v |= 8;
	return v;
}

void search(int x, int y,int len)
{
	if(x < 0 || x >=n || y < 0 || y >=m)
		return ;
	if(minv[x][y] > len)
		minv[x][y] = len;	
	else
		return ;

	//cout << x << " " << y << " " << len << endl;
	if((mat[x][y] & 1) == 0)
		search(x-1,y,len + 1);
	if((mat[x][y] & 2) == 0)
		search(x,y+1,len + 1);
	if((mat[x][y] & 4) == 0)
		search(x+1,y,len + 1);
	if((mat[x][y] & 8) == 0)
		search(x,y-1,len + 1);	
}
int main(void){
	int x,ans = 0;
	string c;
	fin >> m >> n ;
	getline(fin,c);
	for(int i = 0;i< 2*n + 1;i++)
	{
		getline(fin,arr[i]);
	}
	for(int i = 0;i<n;i++)
	for(int j = 0;j<m;j++)
	{
		mat[i][j] = cal(2*i+1,2*j+1);
	}
	memset(minv,0x7f,sizeof(minv));

	for(int i = 0;i<n;i++)
	{
	if((mat[i][0] & 8) == 0)
		search(i,0,1);
	if((mat[i][m-1] & 2) == 0)
		search(i,m-1,1);
	}
	for(int j = 0;j<m;j++)
	{
	if((mat[0][j] & 1) == 0)
		search(0,j,1);
	if((mat[n-1][j] & 4) == 0)
		search(n-1,j,1);
	}

	for(int i = 0;i<n;i++)
	for(int j = 0;j<m;j++)
	{
		if (ans < minv[i][j])
			ans = minv[i][j];	
	}
	fout << ans << endl;
	return 0;
}
