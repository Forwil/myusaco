/*
ID: forwil11
PROG: fact4
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "fact4" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

int n,m,arr[5000];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	
int count(int x)
{
	int v = 0,id;
	id = x;
	while(x <=n)
	{
		v += n / x;
		x *= id;
	}
	return v;
}
int reduce(int x)
{
	int y;
	y = x;
	for(int i = 1;i<=n;i++)
	{
		while(arr[i] % 2 == 0 && x)
		{
			arr[i] /= 2;
			x--;
		}
		while(arr[i] % 5 == 0 && y)
		{
			arr[i] /=5;
			y--;
		}	
	}
		
}
int main(void){
	int x,ans = 0,a,b,c;
	fin >> n;
	for(int i =1;i<=n;i++)
		arr[i] = i;
	a = count(2);
	b = count(5);	
	c = MIN(a,b);
	reduce(c);	
	ans = 1;
	for(int i =1;i<=n;i++)
	{
	//	cout << arr[i] <<endl;
		ans = (ans * arr[i]) % 10;
	}
	fout << ans << endl;
	return 0;
}
