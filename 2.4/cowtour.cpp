/*
ID: forwil11
PROG: cowtour
LANG: C++
*/
#include <iomanip>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "cowtour" 
#define MAXV 1e20
#define EPS 1e-10
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

typedef struct point{
	int x,y;
} Point;

int n,m,flag[160];
double dis[160][160],dia[160];
Point arr[160];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

inline double cal_dis(Point a, Point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int iscan(double x)
{
	return (fabs(x - (MAXV)) > EPS);
}

void draw(int x,int color)
{
	if(flag[x] == 0)
	{
		flag[x] = color;
		for(int i = 0;i < n;i++)
		if(iscan(dis[x][i]))
			draw(i,color);	
	}
	else
		return ;
}

int main(void){
	int x,count = 0;
	double ans = 0;
	fin >> n;
	for(int i=0;i<n;i++)
		fin >> arr[i].x >> arr[i].y;
	for(int i=0;i<n;i++)
	{
		string temp;
		fin >> temp;
		for(int j=0;j<n;j++)
			if(temp[j]=='1')
				dis[i][j] = cal_dis(arr[i],arr[j]);
			else
				dis[i][j] = MAXV;
	}
	for(int i =0;i<n;i++)
	{
		if(flag[i] == 0)
		{
			count += 1;
			draw(i,count);
		}
	}
  
	for(int k =0;k<n;k++)
	for(int i =0;i<n;i++)if(i!=k)
	for(int j =0;j<n;j++)if(j!=i && j!=k)
	{
		if(dis[i][j] > dis[i][k] + dis[k][j])
			dis[i][j] = dis[i][k] + dis[k][j];
	}

	for(int i =0;i<n;i++)
	for(int j =0;j<n;j++)if(i!=j)
		if(flag[i] == flag[j])
			if(dia[i] < dis[i][j])
				dia[i] = dis[i][j];

	for(int i =0;i<n;i++)
	{
		//cout << dia[i] << " " ;
		if(ans <dia[i])
			ans = dia[i];
	}

	double min2 = MAXV;
	for(int i =0;i<n;i++)
	for(int j =i+1;j<n;j++)
		if(flag[i] != flag[j])
		{
			double t = cal_dis(arr[i],arr[j]) + dia[i] + dia[j];
			if(min2 > t)
				min2 = t;
		}
	
	if(min2 > ans)
		ans = min2;

	fout.setf(ios::fixed);
	fout <<setprecision(6) << ans << endl;
	return 0;
}
