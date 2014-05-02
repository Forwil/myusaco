/*
ID: forwil11
PROG: prefix
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "prefix" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,dp[300];
string arr[300],data;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = 0;
	string s;
	while(1)
	{
		fin >> arr[n++];
		if(arr[n-1].compare(".") == 0)
			break;
	}
	fin >> data;
	n -= 1;
	for(int i = 0;i < data.size();i++)
	{
		for(int j = i;j>=0;j--)
		{
			string temp = data.substr(j,i-j+1);	
			//cout << temp <<endl;
			for(int k = 0;k<n;k++)
				if(temp.compare(arr[k]) == 0)
				{
					if (j == 0 || (dp[j-1] == 1) )
					{
						dp[i] = 1;	
						ans = i;
					}
				}
		}	
	}
	fout << ans + 1 << endl;
	return 0;
}
