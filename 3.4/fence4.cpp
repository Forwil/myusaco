/*
ID: forwil11
PROG: fence4
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "fence4" 
#define MAXN 205
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 
typedef struct point{
	int x,y;
}Point;
int n,m,xx,yy,;
Point arr[MAXN];
ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = 0;
	fin >> n;
	fin >> xx >> yy;
	for(int i=0;i<n;i++)
		fin >> arr[i].x >> arr[i].y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		if(isx(arr[i],arr[(i + 1)% n],arr[j],arr[(j + 1) % n])<0)
		{
			cout <<"NOFENCE"<<endl;
			return 0;
		}
	}		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		if(i!=j)
				
	}
	fout << ans << endl;
	return 0;
}
