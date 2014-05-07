/*
ID: forwil11
PROG: heritage
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "heritage" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

int n,m;
string a,b;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void output(string a,string b)
{
	int i;
	if(a.size() == 0)
		return;
	for(i=0;i<a.size();i++)
		if(b[0] == a[i])
			break;	
	output(a.substr(0,i),b.substr(1,i));
	output(a.substr(i+1,a.size()-i),b.substr(i+1,a.size()-i));
	fout << b[0];
}

int main(void){
	int x,ans = 0;
	fin >> a >> b;
	output(a,b);
	fout <<endl;
	return 0;
}
