/*
ID: forwil11
PROG: contact
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "contact" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

typedef struct oo{
	int len,value,num;
} Ans;
Ans ans[100000];
int n,m,f[13][5000],a,b,len,nans;
string arr;
ifstream fin(FILE".in");
ofstream fout(FILE".out");	
void count(int l)
{
	int x = 0,mask;
	mask = (1 << l) - 1;
	for(int i=0;i<l;i++)
		x = (x << 1) | (arr[i] == '1');
	f[l][x] += 1;
	for(int i=l;i<len;i++)
	{
		x = ((x << 1) & mask)| (arr[i] == '1');
		f[l][x] += 1;
	}	
}
int cmp(Ans a, Ans b)
{
	if(a.num != b.num)
		return a.num > b.num;
	else if(a.len != b.len)
			return a.len < b.len;
		else
			return a.value < b.value;
}
void output(int value,int len)
{
	for(int i =len-1;i>=0;i--)
	if((1 << i ) & value)
		fout << 1;
	else
		fout << 0;	
}
int main(void){
	int x;
	fin >> a >> b >> n;
	arr = "";
	while(1)
	{
		string temp;
		fin >>  temp;
		if(fin.eof())
			break;
		arr += temp;
	}	
	len = arr.size();
	for(int i = a;i<=b;i++)
	if(len >=i )
	{
		count(i);	
		for(int j = 0;j < (1 << b);j++)
			if(f[i][j])
			{
				ans[nans].len = i;
				ans[nans].value = j;
				ans[nans].num = f[i][j];	
				nans += 1;
			}
	}
	sort(ans,ans + nans,cmp);
	int t = 0;
	for(int i =0;i<n && t < nans;i++)
	{
		fout << ans[t].num <<endl;
		int tt;
		tt = 0;
		while(1)
		{
			output(ans[t].value,ans[t].len);	
			t += 1;
			if(t < nans && ans[t-1].num == ans[t].num )
			{
				if(tt % 6 ==5)
					fout << endl;
				else
					fout << " ";
			}
			else
			{
				fout << endl;
				break;
			}
			tt += 1;
		}
	}
	return 0;
}
