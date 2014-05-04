/*
ID: forwil11
PROG: fracdec
LANG: C++
*/
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "fracdec" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

int n,m,flag[100005];
string ans;
ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void out(string s)
{
	int len = s.size();
	for(int i =0;i<len;i++)
	{
		fout << s[i];
		if(i % 76 == 75)
			fout << endl;
	}
	fout << endl;
}

void cal(int a,int b)
{
	char temp[10];
	int t,rem;
	if(a >= b)
	{
		sprintf(temp,"%d",a / b);
		ans = ans + temp +  ".";
		a = a % b;
	}
	else{
		ans = ans + "0.";
	}
	flag[a] = ans.size();
	if(a == 0)
		ans += "0";
	while(a)
	{
		t = a*10 / b;
		rem = a*10 % b;
		sprintf(temp,"%d",t);
//		cout << a*10 << "/" << b << "=" << t << " mod " << rem << endl;
			
		ans += temp;
		if(flag[rem])
		{
			ans +=")";
			ans.insert(flag[rem],"(");
			break;
		}
		else
		if(rem == 0)
		{
			break;
		}
		flag[rem] = ans.size();
		a = rem;
	}
	out(ans);
}

int main(void){
	int x,a,b;
	fin >> a >> b;
	ans = "";
	cal(a,b);
	return 0;
}
