/*
ID: forwil11
PROG: ariprog
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "ariprog" 

using namespace std; 
int isbis[125001];
int n,m;
void init(int m)
{
	for(int i = 0;i<=m;i++)
	for(int j = 0;j<=i;j++)
		isbis[i*i+j*j] = 1;
}

int is(int a,int b)
{
//	cout << a << " " << b<< endl;
	for(int i=0;i<n;i++)
	{
//		cout << a << endl;
		if(!isbis[a])
			return 0;
		a += b;
	}
	return 1;
}

int main(void){
	int flag = 0;
	ifstream cin(FILE".in");
	ofstream cout(FILE".out");	
	cin >> n >> m;
	init(m);
	for(int b = 1;b <= 2*m*m;b++) 
	for(int a = 0;a <= 2*m*m - b*(n-1);a++)
		if(is(a,b))
		{
			flag = 1;
			cout << a << " " << b << endl;	
		}
	if (flag == 0)
		cout << "NONE" << endl;
	return 0;
}
