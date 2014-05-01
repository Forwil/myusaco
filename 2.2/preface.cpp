/*
ID: forwil11
PROG: preface
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "preface" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m = 7,ans[7];
int reduce[7] =  {1,5,10,50,100,500,1000};
char output[7] = {'I','V','X','L','C','D','M'};
ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void cal(int x,int ans[])
{
	if(x == 0)
		return ;
	for(int i = m-1;i>=0;i--)
	if(x >= reduce[i])
	{
		ans[i] += 1;
//		fout << output[i];

		cal(x - reduce[i],ans);	
		break;
	}
	else if((i%2==0) && i >= 2 && x>= reduce[i]-reduce[i-2])
	{
		ans[i] += 1;
		ans[i-2] += 1;
//		fout << output[i-2] << output[i];

		cal(x - (reduce[i] - reduce[i-2]),ans);	
		break;
	}
	else if(i%2 && i>=1 && x>= reduce[i]-reduce[i-1])
	{
		ans[i] += 1;
		ans[i-1] += 1;
//		fout << output[i-1] << output[i];

		cal(x - (reduce[i] - reduce[i-1]),ans);	
		break;
	}

}

int main(void){
	int x;
	fin >> n;
	for(int i=1;i<=n;i++)
		cal(i,ans);
	for(int i=0;i<7;i++)
	if(ans[i])
		fout << output[i]<<" " << ans[i] << endl;
	return 0;
}
