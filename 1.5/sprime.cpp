/*
ID: forwil11
PROG: sprime
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "sprime" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,a,b;
int np,primes[10000];

	ifstream fin(FILE".in");
	ofstream fout(FILE".out");	


int isp(int x)
{
	if(x <= 1)
		return 0;
	int m = (int) sqrt(x);
	for(int i=2;i<=m;i++)
		if(x % i ==0)
			return 0;
	return 1;
}

void getp(int m)
{
	m = (int)sqrt(m);	
	for(int i =2; i <=m;i++)
		if(isp(i))
			primes[np++] = i;	
}

int get_len(int x)
{
	int l = 0;
	while(x)
	{
		x /= 10;
		l++;
	}		
	return l;
}

int power(int len)
{
	int v = 1;
	while(len)
	{
		v *= 10;
		len -= 1;
	}
	return v;
}

int isp2(int x)
{
	int m;
	if(x <= 1)
		return 0;
	m = (int) sqrt(x);
	for(int i = 0;i<np && primes[i] <=m ;i++)
		if (x % primes[i] == 0)
			return 0;
	return 1;
}

void search(int id,int value)
{
	if(id == n)
	{
		fout << value << endl;
		return ;
	}
	for(int i = 1;i <= 9;i++)
	if(i % 2 || i==2)
	{
		if(isp2(value * 10 + i))
			search(id + 1,value * 10 + i);
	}	
}
int main(void){
	int m;
	fin >> n;
	getp(power(n));		
	search(0,0);	
	return 0;
}
