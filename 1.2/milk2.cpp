/*
ID: forwil11
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "milk2" 

#define MAXN 1000001
char fin[20] = FILE,fout[20] = FILE; 
using namespace std; 
using std::vector;

int n,count[MAXN];

int main(void){
	int i,busy_now = 0,free_now = 0,busy = 0,free = 0,x,y;
	int max = -MAXN,min = MAXN,now = 0;

	ifstream cin (strcat(fin,".in"));
	ofstream cout (strcat(fout,".out"));

	cin >> n;
	for(i = 0; i < n;i++)
	{
		cin >> x >> y;
		count[x]++ ;
		count[y]-- ;	
		if (x < min)
			min = x;
		if (y > max)
			max = y;
	}

	for(i = min; i <= max;i++)
	{
		now += count[i];
		if( now == 0 )
		{
			free_now ++;
			if(busy_now > busy)
				busy = busy_now;
			busy_now = 0;
		}		
		else
		{
			busy_now ++ ;
			if(free_now > free)
				free = free_now;
			free_now = 0;
		}
	}

	cout << busy << ' ' << free << endl;	
	return 0;
}
