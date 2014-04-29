/*
ID: forwil11
PROG: calfflac
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "calfflac" 

using namespace std; 

int n;
char temp2[20002];

int avl(int a)
{
	return ((a >= 0 && a < n));  
}

int isc(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

char low(char c)
{
	if (c >= 'a')
		return c - 'a' + 'A';
	else
		return c; 
}

int search(char* s,int &a,int &b)
{
	int len = -(a == b),aa = a,bb = b;

	while(avl(a) && !isc(s[a]))
		a -= 1;
	while(avl(b) && !isc(s[b]))
		b += 1;

	while(avl(a) && avl(b) && low(s[a]) == low(s[b]))
	{
		aa = a;
		bb = b;
		len += 2;
		a -= 1;
		while(avl(a) && !isc(s[a]))
			a -= 1;
		b += 1;
		while(avl(b) && !isc(s[b]))
			b += 1;
	}
	a = aa;
	b = bb;
	return len;
}


int main(void){
	int m,a,b,ans = 0,ansa,ansb;
	string temp(""),t;

	ifstream cin(FILE".in");
	ofstream cout(FILE".out");	
	while(!cin.eof())
	{
		getline(cin,t);
		temp += t + '\n';
	}
	n = temp.size();
	for( int i = 0;i < n;i ++)
		temp2[i] = temp[i];

	for(int i = 0;i < n;i++)
	{
		a = i;
		b = i;
		m = search(temp2,a,b);
		if(m > ans)
		{
			ans = m;
			ansa = a;
			ansb = b;
		}	

		a = i;
		b = i + 1;
		m = search(temp2,a,b);
		if(m > ans)
		{
			ans = m;
			ansa = a;
			ansb = b;
		}	
	}
	temp2[ansb+1] = '\0';
	cout << ans << endl << &temp2[ansa] << endl;
	return 0;
}
