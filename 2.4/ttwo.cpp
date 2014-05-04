/*
ID: forwil11
PROG: ttwo
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "ttwo" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 
/*
 *	up 0
 *	right 1
 *	down 2
 *	left 3
 */
int dx[4] = {-1,0,1,0 };
int dy[4] = {0 ,1,0,-1};
int n,m,ans[4][10][10][4][10][10],out;
string mat[10];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int go(int &pos,int &x,int &y)
{
	int xx,yy,flag = 0;	
	xx = x + dx[pos];
	yy = y + dy[pos];
	if(xx < 0) 
	{	
		xx = 0;
		flag = 1;
	}
	if(xx > 9)
	{ 
		xx = 9;
		flag =1;
	}
	if(yy < 0)
	{	
		yy = 0;
		flag = 1;
	}
	if(yy > 9) 
	{
		yy = 9;
		flag =1;
	}
	if(mat[xx][yy] == '*')
	{
		xx = x;
		yy = y;
		flag = 1;
	}	
	x = xx;
	y = yy;
	if(flag)
		pos = (pos + 1 ) % 4;
	return flag;
}

int search(int pos1,int ax,int ay,int pos2,int bx,int by,int len)
{

	if(ans[pos1][ax][ay][pos2][bx][by] == 0)
	{
		ans[pos1][ax][ay][pos2][bx][by] = 1;
		if(ax == bx && ay == by)
			return len;
	}
	else
		return 0;

	go(pos1,ax,ay);
	go(pos2,bx,by);	
	return search(pos1,ax,ay,pos2,bx,by,len + 1);
}

int main(void){
	int ax,ay,bx,by;
	n = 10;
	for(int i=0;i<10;i++)
	{
		fin >> mat[i];
		for(int j = 0;j<10;j++)
		if(mat[i][j] == 'F')
		{
			mat[i][j] = '.';
			ax = i;
			ay = j;
		}
		else if(mat[i][j] == 'C')
		{
			mat[i][j] = '.';
			bx = i;
			by = j;
		}
	}
	out = search(0,ax,ay,0,bx,by,0);
	fout << out << endl;
	return 0;
}
