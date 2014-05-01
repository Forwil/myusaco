/*
ID: forwil11
PROG: runround
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "runround" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,power[9];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

inline int get_len(int x)
{
	int v= 0;
	while(x)
	{
		v += 1;
		x /= 10;
	}
	return v;
}

inline int get_id(int x,int i)
{
	return x / power[i-1] % 10;
}

int find_low(int x)
{
	int i,now,last,len,delt,hash[10] = {0},boo[10] = {0};
	len = get_len(x);	
	now = len;
	for(i = 1;i<=len;i++)
	{
	//	cout << x <<" " << now << endl;
		hash[now] = 1;
		delt = get_id(x,now);
		boo[delt] += 1;
		if(boo[delt]>1)
			break;
		delt = delt % len;
		last = now;
		now = (now - delt + len) % len;
		if(now == 0)
			now = len;
		if(hash[now] == 1)
			break;
	}
	if (now == len && i == len)
		return 0;
	for(int i=1;i<=len;i++)
	if(hash[i] || boo[i] >1)
		return i;
}

int find(int x)
{
	int t;
	t = find_low(x);
	while(t)
	{
		x += power[t - 1];	
	//	cout << "x= " << x << endl;
		t = find_low(x);
	}
	return x;
}
int main(void){
	int m,x,ans = 0;
	power[0] = 1;
	for(int i=1;i<=9;i++)
		power[i] = power[i-1] * 10;
	fin >> n;	
	fout << find(n+1) << endl;
	return 0;
}
