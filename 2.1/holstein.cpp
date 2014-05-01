/*
ID: forwil11
PROG: holstein
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "holstein" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,arr[30][30],now[30],ans,ans_state;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int check(int now[])
{
	for(int i=0;i<m;i++)
	{
		if(now[i] > 0)
			return 0;
	}
	return 1;
}

void out(int now[])
{
	for(int i=0;i<m;i++)
		cout << now[i] << " ";
	cout << endl;
}

void search(int id,int now[],int state,int num)
{
//		cout <<state <<" "  << id << ":" << num << endl;
//		out(now);


	if(check(now))
	{
		if(num < ans)
		{

			ans = num;
			ans_state = state;	
		}

		return ;
	}

	if(id == n)
		return ;

	for(int i=0;i<m;i++)
		now[i] -= arr[id][i];
	search(id+1,now,state | (1 << id),num + 1);
	for(int i=0;i<m;i++)
		now[i] += arr[id][i];
	search(id+1,now,state,num);
}

void out_state(int state)
{
	int i = 1;
//	cout << state << endl;
	while(state)
	{
		if (state & 1)
		{
			fout << i ;
			if(state /2)
				fout << " ";
			else
				fout << endl;		
		}
		state /= 2;
		i += 1;
	}	
}

int main(void){
	int x;
	fin >> m;
	for(int i=0;i<m;i++)
		fin >> now[i];
	fin >> n;
	ans = n + 1;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		fin >> arr[i][j];	
	search(0,now,0,0);	
	fout << ans << " ";
	out_state(ans_state);
	return 0;
}
