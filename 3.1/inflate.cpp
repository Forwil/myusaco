/*
ID: forwil11
PROG: inflate
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "inflate" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

typedef struct item{
	int cost,value;
} Item;

int n,m,dp[10001];
Item arr[10001];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	
int cmp(Item a,Item b)
{
	return a.value*b.cost > a.cost*b.value;
}

int main(void){
	int x,ans = 0;
	fin >> m >> n;
	for(int i=0;i<n;i++)
		fin >> arr[i].value >> arr[i].cost;
	sort(arr,arr+n,cmp);	

	n = MIN(n,1000);
	for(int i=0;i<n;i++)
	for(int j=0;j<=m-arr[i].cost;j++)
		if(dp[j + arr[i].cost] < dp[j] + arr[i].value)
			dp[j + arr[i].cost] = dp[j] + arr[i].value;
	for(int j=0;j<=m;j++)
		ans = MAX(ans,dp[j]);	
	fout << ans << endl;
	return 0;
}
