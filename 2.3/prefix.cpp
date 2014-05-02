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

int n,m,dp[200005];
string arr[300],data;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int main(void){
	int x,ans = -1;
	string temp;
	string s;

	while(1)
	{
		fin >> arr[n++];
		//cout << arr[n-1] << endl;
		if(arr[n-1].compare(".") == 0)
			break;
	}
	n = n-1;
	data = "";
	while(1)
	{
		fin >> temp;
		if(fin.eof())
			break;
		data += temp;
	}	
	for(int i = 0;i < data.size();i++)
	{
		for(int k = 0;k<n;k++)
		{
			int len = arr[k].size();
			if(len > i + 1)
				break;
			string temp = data.substr(i-len+ 1,len);	
		//	cout << temp << " " << arr[k] <<" " <<temp.compare(arr[k]) << endl;
			if(temp.compare(arr[k]) == 0)
			{
				if (i - len == -1 || (dp[i - len] == 1) )
				{
					dp[i] = 1;	
					ans = i;
					break;
				}
			}
		}
	}
	fout << ans + 1 << endl;
	return 0;
}
