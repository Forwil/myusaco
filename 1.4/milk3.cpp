/*
ID: forwil11
PROG: milk3
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "milk3" 
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 
int maxv[3],maxx;

int hash[30][30][30],ans[30];

void search(int now[3])
{
	if (hash[now[0]][now[1]][now[2]])
		return ;

//	for(int i=0;i<3;i++)
//		cout << now[i] << " ";
//
	if(now[0] == 0)
	{
		ans[now[2]] = 1;
		if (now[2] > maxx)
			maxx = now[2];
	}

	hash[now[0]][now[1]][now[2]] = 1;	
	for(int i = 0;i<3;i++)
	if(now[i])
		for(int j = 0;j<3;j++)
			if(i!=j && now[j]!=maxv[j])
			{
				int t = MIN(now[i],maxv[j]-now[j]);
				now[i] -= t;
				now[j] += t;
				search(now);		
				now[i] += t;
				now[j] -= t;
			}	
}

int main(void){
	int flag = 0,now[3];
	ifstream cin(FILE".in");
	ofstream cout(FILE".out");	

	cin >> maxv[0] >> maxv[1] >> maxv[2];
	now[0] = now[1] = 0;
	now[2] = maxv[2];
	search(now);
	for(int i=0;i<maxx;i++)
		if(ans[i])
			cout << i << " "; 
	cout << maxx << endl;
	return 0;
}
