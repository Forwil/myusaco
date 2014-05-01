/*
ID: forwil11
PROG: hamming
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "hamming" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,d,ans[100],maxv;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int count1(int x)
{
	int v = 0;
	while(x)
	{
		x ^= (x & -x);
		v += 1;
	}	
	return v;
}

int can(int x,int id)
{
	for(int i=0;i<id;i++)
		if(count1(ans[i] ^ x)<d)
			return 0;
	return 1;	
}

void out()
{
	for(int i=0;i<n-1;i++)
	{
		fout << ans[i] ;
		if(i % 10 == 9)
			fout <<endl;
		else
			fout << " ";
	}
	fout << ans[n-1]<<endl;
}

int search(int id,int from)
{
	if(id == n)
	{
		out();
		return 1;
	}
	for(int i = from;i < maxv;i++)
	if(can(i,id))
	{
		ans[id] = i;
		if (search(id + 1,i + 1))
			return 1;
	}	
}

int main(void){
	fin >> n >> m >> d;
	maxv = 1 << m;
	search(0,0);
	return 0;
}
