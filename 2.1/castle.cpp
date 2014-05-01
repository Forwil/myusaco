/*
ID: forwil11
PROG: castle
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "castle" 
#define MAXN 55
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m;
int arr[MAXN + 1][MAXN + 1],hash[MAXN + 1][MAXN + 1];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int out(int x,int y)
{
	return (x < 1 || x >n || y < 1 || y > m);	
}

int mark(int x,int y,int flag)
{
	int num = 1;
	if(out(x,y) || hash[x][y] != -1)
		return 0;
//	cout << x << ","<<y << " " << flag << endl;
	hash[x][y] = flag;	
	if((arr[x][y] & 1) == 0)
		num += mark(x,y-1,flag);	
	if((arr[x][y] & 2) == 0)
		num += mark(x-1,y,flag);	
	if((arr[x][y] & 4) == 0)
		num += mark(x,y+1,flag);	
	if((arr[x][y] & 8) == 0)
		num += mark(x+1,y,flag);	
	return num;
}

void floodfill(int &num,int &max)
{
	num = 0;
	max = 0;
	memset(hash,-1,sizeof(hash));
	for(int i=1;i <=n;i++)
	for(int j=1;j <=m;j++)
	if(hash[i][j] == -1)
	{
		int temp = mark(i,j,num);
		if (temp > max)
			max = temp;
		num ++ ;	
	}
}
int main(void){
	int x,num,max,ans = 0,ansx,ansy,p;
	fin >> m >> n;
	for(int i =1;i <=n;i++)
	for(int j =1;j <=m;j++)
		fin >> arr[i][j];
	floodfill(num,max);
	fout << num << endl << max << endl;
	for(int j = 1;j <=m;j++)
	for(int i = n;i >=1;i--)
	{
		if (arr[i][j] & 2)
		{
			arr[i][j] ^= 2;
			arr[i-1][j] ^= 8;
			floodfill(num,max);
			//cout << i << " "<<j <<" " <<max <<endl;
			if(max > ans)
			{
				ans = max;
				ansx = i;
				ansy = j;
				p = 0;
			}
			arr[i][j] ^= 2;
			arr[i-1][j] ^= 8;
		}
		if (arr[i][j] & 4)
		{
			arr[i][j] ^= 4;
			arr[i][j+1] ^= 1;
			floodfill(num,max);
			if(max > ans)
			{
				ans = max;
				ansx = i;
				ansy = j;
				p = 1;
			}
			arr[i][j] ^= 4;
			arr[i][j+1] ^= 1;
		}
	}	
	fout << ans << endl << ansx << " " << ansy << " ";
	if (p)
		fout << "E" <<endl;
	else
		fout << "N" <<endl;
	return 0;
}
