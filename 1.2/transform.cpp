/*
ID: forwil11
PROG: transform
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "transform" 

#define MAXN 12
char fin[20] = FILE,fout[20] = FILE; 
using namespace std; 
using std::vector;

typedef char matrix[MAXN][MAXN];

int n;
matrix a,b,c,d;

void out(matrix src)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			cout << src[i][j];
		cout << endl;
	}
}

void copy(matrix dest,matrix src)
{
	for(int i = 0;i < n;i++)
	for(int j = 0;j < n;j++)
		dest[i][j] = src[i][j];
}

int same(matrix dest,matrix src)
{
	for(int i = 0;i < n;i++)
	for(int j = 0;j < n;j++)
	if( dest[i][j] != src[i][j])
		return 0;
	return 1;
}

void trans90(matrix dest,matrix src)
{
	for(int i = 0;i < n;i++)
	for(int j = 0;j < n;j++)
		dest[i][j] = src[n - j - 1][i];
} 

void trans180(matrix dest,matrix src)
{
	matrix temp;
	trans90(dest,src);
	copy(temp,dest);
	trans90(dest,temp);		
}

void trans270(matrix dest,matrix src)
{
	matrix temp;
	trans90(dest,src);
	copy(temp,dest);
	trans90(dest,temp);	
	copy(temp,dest);
	trans90(dest,temp);	
}

void ref(matrix dest,matrix src)
{
	for(int i = 0;i < n;i++)
	for(int j = 0;j < n;j++)
		dest[i][j] = src[i][n - j - 1];

}

int main(void){
	int ans = 7;
	ifstream cin (strcat(fin,".in"));
	ofstream cout (strcat(fout,".out"));

	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];	
	}

	for(int i = 0;i < n;i++)
	{
		cin >> b[i];	
	}
	
	if(same(a,b))
	{
		if (6 < ans)
			ans = 6;
	}	

	trans90(c,a);	
	if(same(c,b))
	{
		if (1 < ans)
			ans = 1;
	}
	ref(d,c);
	if(same(d,b))
	{
		if (5 < ans)
			ans = 5;
	}

	trans180(c,a);
	if(same(c,b))
	{
		if (2 < ans)
			ans = 2;
	}

	ref(d,c);
	if(same(d,b))
	{
		if (5 < ans)
			ans = 5;
	}

	trans270(c,a);
	if(same(c,b))
	{
		if (3 < ans)
			ans = 3;
	}

	ref(d,c);
	if(same(d,b))
	{
		if (5 < ans)
			ans = 5;
	}

	ref(c,a);
	if(same(c,b))
	{
		if (4 < ans)
			ans = 4;
	}		
	
	cout << ans << endl;
	return 0;
}
