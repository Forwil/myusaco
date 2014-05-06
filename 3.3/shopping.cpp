/*
ID: forwil11
PROG: shopping
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "shopping" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

typedef struct item Item;
struct item{
	int num,type,cost;
	Item* next;		
};

Item* kinds[200];
int nk,n,m,point[1000],limit[10];
int dp[100000],temp[5];
ifstream fin(FILE".in");
ofstream fout(FILE".out");	
int get(int x)
{
	if(point[x] == -1)
	{
		point[x] = nk;
		nk += 1;
	}
	return point[x];
}

int get_hash(int temp[])
{
	return temp[0] * 10000 + temp[1] * 1000 + temp[2] * 100 + temp[3] * 10 + temp[4];	
}

int add_hash(Item* link,int from[],int to[])
{
	int cost = link->cost;
	for(int i=0;i<5;i++)
		to[i] = from[i];
	while(link)
	{
		to[link->type] += link->num;
		link = link->next;
	}		
	return cost;
}

int main(void){
	int x,a,b,ans = 0;
	memset(point,-1,sizeof(point));
	fin >> n;
	for(int i=0;i<n;i++)
	{
		fin >> m;	
		for(int j=0;j<m;j++)
		{
			fin >> a >> b;	
			Item* temp = new Item;	
			temp->type = get(a);
			temp->num = b;	

			temp->next = kinds[i];
			kinds[i] = temp; 
		}
		fin >> a;
		kinds[i]->cost = a;
	}
	fin >> m;
	for(int i =n;i<m+n;i++)
	{
		fin >> a;
		a = get(a);
		fin >> limit[a];	
		fin >> b;

		Item* temp = new Item;
		temp->type = a;
		temp->num = 1;
		temp->cost = b;

		temp->next = kinds[i];
		kinds[i] = temp;
	}
	n = n + m;
	
	memset(dp,0x7f,sizeof(dp));
	int maxv = dp[0];
	dp[0] = 0;
	for(int i=0;i<n;i++)
	{
		for(temp[0] = 0;temp[0]<=limit[0];temp[0]++)
		for(temp[1] = 0;temp[1]<=limit[1];temp[1]++)
		for(temp[2] = 0;temp[2]<=limit[2];temp[2]++)
		for(temp[3] = 0;temp[3]<=limit[3];temp[3]++)
		for(temp[4] = 0;temp[4]<=limit[4];temp[4]++) 	
		{
			int x,other[5],flag;
			x = get_hash(temp);	
			if(dp[x] != maxv)
			{

			//	cout << i << " " <<x << endl;
				int cost = add_hash(kinds[i],temp,other);	
				flag = 0;
			//	cout << get_hash(other) << " v: "<< dp[get_hash(other)]<< endl;
				for(int j = 0;j<5;j++)
					if (other[j] > limit[j])
					{
						flag = 1;
						break;
					}
				if(!flag)
				{
					int y;
					y = get_hash(other);
					if(dp[y] > dp[x] + cost)
						dp[y] = dp[x] + cost;
				}
			}	
		}
	}	
	
	x = get_hash(limit);
	
	fout << dp[x] << endl;
	return 0;
}
