/*
ID: forwil11
PROG: milk
LANG: C++
*/
#include <algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "milk" 

using namespace std; 
using std::vector;

char fin[20] = FILE,fout[20] = FILE; 
int n;

typedef struct scow{
	int max;
	int cost;
} tcow;
tcow  cow[5001];

int cmp(const tcow &a, const tcow &b)
{
	if (a.cost < b.cost)
		return 1;
	else
		return 0;
}

int main(void){
	int n,m,ans = 0,temp;
	ifstream cin (strcat(fin,".in"));
	ofstream cout (strcat(fout,".out"));	
	cin >> m >> n;
	for(int i = 0;i < n;i++)
		cin >> cow[i].cost >> cow[i].max;
	sort(cow,cow + n,cmp);
	for(int i = 0;i < n;i++)
	if(m > 0)
	{
		if ( m >= cow[i].max)
			temp = cow[i].max;
		else
			temp = m;
		m -= temp;
		ans += temp*cow[i].cost;
	}
	cout << ans << endl;
	return 0;
}
