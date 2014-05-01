/*
ID: forwil11
PROG: pprime
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "pprime" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,a,b,ans[10000];
int np,primes[10000];
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

int get_rev1(int x,int ind)
{
	for(int i = 1;i < ind;i++)
	{
		int temp = x / power(i - 1) % 10; 	
		x += temp * power(ind + (ind - i) -1);
	}	
	return x;
}

int get_rev2(int x,int ind)
{
	for(int i = 1;i <= ind;i++)
	{
		int temp = x / power(i - 1) % 10; 	
		x += temp * power(ind + (ind - i));
	}	
	return x;
}
int inab(int x)
{
	return x >= a && x <= b;
}

int main(void){
	int m,half_len,v;

	ifstream cin(FILE".in");
	ofstream cout(FILE".out");	


	cin >> a >> b;
	getp(b);		
	half_len = get_len(b) / 2 + 1;
	m = power(half_len + 1);	
	for(int i = 1;i < m;i++)
	if(i % 10 !=0)
		for(int j = get_len(i);j <=	half_len;j++)
		{
			v = get_rev1(i,j);	
			//cout << v << " value=" <<i << " ind= " <<j << endl;
			if (isp2(v) && inab(v))
				ans[n++] = v;
			v = get_rev2(i,j);
			if (isp2(v) && inab(v))
				ans[n++] = v;
		}	
	sort(ans,ans+n);
	for(int i=0;i<n;i++)
		cout << ans[i] << endl;	
	return 0;
}
