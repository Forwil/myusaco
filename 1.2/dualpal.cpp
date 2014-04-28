/*
ID: forwil11
PROG: dualpal
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "dualpal" 

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

int can2p(int x)
{
	int base,count = 0;
	for(base = 2; base <= 10;base++)
	{
		if (isp(x,base))
			count ++;
		if (count == 2)
			return 1;
	}	
	return 0;
}

int main(void){
	int n,min;
	ifstream cin (strcat(fin,".in"));
	ofstream cout (strcat(fout,".out"));
	
	cin >> n >> min;
	min += 1;
	for(int i = 0;i < n;i++)
	{
		while(! can2p(min))
			min ++;
		cout << min << endl;
		min++ ;
	}	
	return 0;
}
