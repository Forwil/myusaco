/*
ID: forwil11
PROG: 
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

int n,m;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = 0;
	fin >> n;
	fout << ans << endl;
	return 0;
}
