/*
ID: forwil11
PROG: barn1
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "barn1" 

using namespace std; 

int n,stall[202];

int cmp(const int &a, const int &b)
{
	if (a > b)
		return 1;
	else
		return 0;
}

int main(void){
	int n,m,ans = 0,temp;

	ifstream cin(FILE".in");
	ofstream cout(FILE".out");	

	cin >> m >> n >> n;
	for(int i = 0;i < n;i++)
		cin >> stall[i];

	sort(stall,stall + n,cmp);

	ans = stall[0] - stall[n - 1] + 1;
	for(int i = 0;i < n - 1;i++)
		stall[i] = stall[i] - stall[i + 1];	
	sort(stall,stall + n - 1,cmp);

	for(int i = 0;i < m - 1 && i < n - 1;i++)
		ans -=	(stall[i] - 1);
	cout << ans << endl; 
	return 0;
}
