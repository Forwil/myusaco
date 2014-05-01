/*
ID: forwil11
PROG: frac1
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "frac1" 

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)>(b))?(b):(a)

using namespace std; 

typedef struct frac{
	int up,down;
} Frac;

int n;
Frac arr[200 * 200];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int cmp(Frac a,Frac b)
{
	return  (a.up * b.down < a.down * b.up);
}
int gcd(int a,int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a % b);
}
void add(int a,int b)
{
	arr[n].up = a;
	arr[n].down = b;
	n++ ;
}
int main(void){
	int m,x,ans = 0;
	fin >> m;
	add(0,1);	
	add(1,1);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=i-1;j++)
		if(gcd(j,i) == 1)
			add(j,i);


	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++)
		fout << arr[i].up << "/"<<arr[i].down <<endl;	
	return 0;
}
