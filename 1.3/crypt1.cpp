/*
ID: forwil11
PROG: crypt1
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "crypt1" 

using namespace std; 

int n,in[10] = {0};

int isin(int x,int len)
{
	int i = 0;
	while(x)
	{
		i++;
		if (in[x%10] == 0)
			return 0;
		x /= 10;
	}	
	return i == len;
}

int can(int a,int b,int c,int d,int e)
{
	int x,y;
//	cout << a << b << c << endl;
//	cout << d << e << endl << endl;
	x = a*100 + b*10 + c;
	y = d*10 + e;
	return (isin(x*d,3) && isin(x*e,3) && isin(x*y,4));
}

int main(void){
	int m,a,b,c,d,e,ans = 0,arr[10];

	ifstream cin(FILE".in");
	ofstream cout(FILE".out");	

	cin >> n;
	for(int i =0;i < n ;i++)
	{
		cin >> arr[i];
		in[arr[i]] = 1;
	}
	for(int a=0;a < n;a++)
	for(int b=0;b < n;b++)
	for(int c=0;c < n;c++)
	for(int d=0;d < n;d++)
	for(int e=0;e < n;e++)
		if (can(arr[a],arr[b],arr[c],arr[d],arr[e]))
			ans++;
	cout << ans << endl;
	return 0;
}
