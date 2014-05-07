/*
ID: forwil11
PROG: rockers
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "rockers" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

int n,m,t,ans,arr[30];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	
void search(int now,int nowm,int remind,int used)
{
	if(used + (n - now) < ans)
		return ;
	if(used > ans)
		ans = used;
	if(now == n || remind == 0)
		return ;

	if(nowm >= arr[now])
	{
		if (m == arr[now])
			search(now + 1,m,remind - 1,used + 1);
		else
			search(now + 1,nowm - arr[now],remind,used +1);
	}
	else
		if(m >= arr[now])
			search(now,m,remind - 1,used);
	search(now + 1,nowm,remind,used);	
}
int main(void){
	int x;
	fin >> n >> m >> t;
	for(int i=0;i<n;i++)
		fin >> arr[i];
	search(0,m,t,0);
	fout << ans << endl;
	return 0;
}
