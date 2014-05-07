/*
ID: forwil11
PROG: fence9
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "fence9" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

int n,m,p;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = 0;
	fin >> n >> m >> p;
	if(p<=n)
	{
		for(int i =1;i<p;i++)
			ans += (i * m -1) / n;
		for(int i =p;i<n;i++)
			ans += (i * m -1) / n - ((i - p) * m) / (n - p); 	
	}	
	else
	{
		for(int i =1;i<n;i++)
			ans += (i * m -1) / n;	
		for(int i =n;i<p;i++)
			ans += (m * (p - i) -1)/ (p - n);
		if(n==0)
			ans -= m - 1;
	}
	fout << ans << endl;
	return 0;
}
