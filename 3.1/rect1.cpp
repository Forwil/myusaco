/*
ID: forwil11
PROG: rect1
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "rect1" 
#define MAXM 100000
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

typedef struct mat{
	int lx,ly,rx,ry;
	int color;
} Mat;

mat arr[MAXM];
int n,m,bot,ans[2501];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void mat_add(int lx,int ly,int rx,int ry,int color)
{
	if(lx >= rx || ly >= ry)
		return;
//	cout << m <<" "<< lx << " "<<ly << " " <<rx << " " << ry << " " <<color <<endl;
	arr[m].lx = lx;
	arr[m].ly = ly;
	arr[m].rx = rx;
	arr[m].ry = ry;;
	arr[m].color = color;
	m = (m + 1) % MAXM;	
}

int main(void){
	int x,lx,ly,rx,ry,color;
	fin >> rx >> ry >> n;
	mat_add(0,0,rx,ry,1);
	for(int i =0;i<n;i++)
	{
		fin >> lx >> ly >> rx >> ry >> color;	
		int r = m, l = bot;
	//	cout << r << " " <<l << endl;
		for(int j =l;j!= r;j = (j + 1) % MAXM)
		{
			mat_add(arr[j].lx,arr[j].ly,MIN(lx,arr[j].rx),arr[j].ry,arr[j].color);
			mat_add(MAX(rx,arr[j].lx),arr[j].ly,arr[j].rx,arr[j].ry,arr[j].color);

			mat_add(MAX(arr[j].lx,lx),MAX(arr[j].ly,ry),MIN(arr[j].rx,rx),arr[j].ry,arr[j].color);
			mat_add(MAX(arr[j].lx,lx),arr[j].ly,MIN(arr[j].rx,rx),MIN(arr[j].ry,ly),arr[j].color);
		}

		bot = r;
		mat_add(lx,ly,rx,ry,color);
	}

	for(int i =bot;i % MAXM != m;i = (i + 1) % MAXM )
		ans[arr[i].color] += (arr[i].ry - arr[i].ly)*(arr[i].rx - arr[i].lx);

	for(int i = 1;i<=2500;i++)
		if(ans[i])
			fout <<i << " " << ans[i] << endl;
	return 0;
}
