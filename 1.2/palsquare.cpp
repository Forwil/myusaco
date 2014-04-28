/*
ID: forwil11
PROG: palsquare
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "palsquare" 

#define MAXN 12
using namespace std; 
using std::vector;

char fin[20] = FILE,fout[20] = FILE; 
int n;

int isp(int x,int base)
{
	int num[20],n = 0;	
	while(x)
	{
		num[n++] = x % base;
		x /= base;
	}		
	for(int i = 0;i < n/2;i++)
	if (num[i] != num[n - i - 1])
		return 0;
	return 1;
}

void outp(int x,int base,ofstream &cout)
{
	char s[20];
	int n = 0,temp;	
	while(x)
	{
		temp = x % base;
		if (temp < 10)
			s[n++] = temp + '0';
		else
			s[n++] = temp - 10 + 'A';
		x /= base;
	}	
	for(x = n-1; x>=0;x--)
		cout << s[x];
}

int main(void){
	int base;
	ifstream cin (strcat(fin,".in"));
	ofstream cout (strcat(fout,".out"));
	
	cin >> base;
	for(int i = 1;i <=300;i++)
	if(isp(i*i,base))
	{
		outp(i,base,cout);
		cout << ' ';
		outp(i*i,base,cout);
		cout << endl;
	}	
	return 0;
}
