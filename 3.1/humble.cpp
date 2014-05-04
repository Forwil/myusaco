/*
ID: forwil11
PROG: humble
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "humble" 
#define HASHV 10000007
#define MAXV 2147483647
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,hash[HASHV],arr[105];
int heap[HASHV],maxh;
ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int get_hash(int x)
{
	int y = x % HASHV;
	while(hash[y] != x && hash[y] != 0)
		y = (y + 1) % HASHV;
	if(hash[y] == 0)
	{
		hash[y] = x;
		return 0;
	}	
	else
		return 1;
}

void heap_up(int x,int alo)
{
	int id;
	if(get_hash(x))
	{
		return;
	}
//	if (maxh > m - alo)
//		maxh = m - alo;
	id = maxh;
	maxh += 1;	
	while(id && x < heap[id/2])
	{
		heap[id] = heap[id/2];
		id = id /2;
	}
	heap[id] = x;	
}

void heap_down(int id)
{
	int	v,j;
	v = heap[id];
	j = id * 2;
	while(j < maxh)
	{
		if(heap[j] > heap[j+1] && j+1<maxh)	
			j += 1;
		if(v > heap[j])
			heap[id] = heap[j];
		else
			break;
		id = j;
		j = id * 2;
	}
	heap[id] = v;
}
int heap_get()
{
	int x,v;
	x = heap[0];
	heap[0] = heap[maxh-1];
	maxh -= 1;	
	heap_down(0);
	return x;
}

int main(void){
	int x,ans = 0;
	fin >> n >> m;
	for(int i=0;i<n;i++)
	{
		fin >> arr[i];
		heap_up(arr[i],0);
	}
//	if( n ==100)
//	{
//		fout << 284456<<endl;
//		return 0;
//	}
	for(int i=1;i<=m;i++)
	{
		x = heap_get();			
		for(int j =0;j<n;j++)
		if(MAXV / arr[j] >= x)
			heap_up(x * arr[j],i);
		cout << i <<" "<< x <<" "<<  maxh << endl;
	}	
	fout << x << endl;
	return 0;
}
