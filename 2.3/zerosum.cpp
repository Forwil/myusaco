/*
ID: forwil11
PROG: zerosum
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "zerosum" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m;
char ans[10];
ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int get(char ans[],int &x)
{
	int v = x;
	while(ans[x] == ' ')
	{
		x += 1;
		v = v * 10 + x;
		if (x == n)
			break;
	}	
	return v;
}
int can(char ans[])
{
	int x,y,i;
	char c;
	i = 1;
	x = get(ans,i);	
	while(i < n)
	{
		c = ans[i];
		i += 1;
		y = get(ans,i);
		if(c == '+')
			x += y;
		else
			x -= y;
	}
	return x == 0;
}

void out(char ans[])
{
	for(int i = 1;i<n;i++)
		fout <<i<<ans[i];
	fout << n << endl;
}
void search(int id,char ans[])
{
	if(id == n)
	{
		if(can(ans))
			out(ans);
		return ;
	}
	ans[id] = ' ';
	search(id+1,ans);
	ans[id] = '+';
	search(id+1,ans);
	ans[id] = '-';
	search(id+1,ans);
}

int main(void){
	int x;
	fin >> n;
	ans[n] = '\0';
	search(1,ans);
	return 0;
}
