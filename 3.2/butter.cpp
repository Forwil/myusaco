/*
ID: forwil11
PROG: butter 
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "butter" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 
typedef struct edge Edge;
struct edge{
	int cost,des;
	Edge* next;
};

Edge* link[802];

int queue[10000],t,w,n,m,l,arr[502],dis[802],isin[802];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void add_edge(int a,int b,int c)
{
	Edge* temp = new Edge;	
	temp->cost = c;
	temp->des = b;
	temp->next = link[a];
	link[a] = temp;
}

int pop()
{
	isin[queue[t]] = 0;
	t += 1;
	return queue[t - 1];
}

int push(int x)
{
	queue[w] = x;
	isin[x] = 1;
	w += 1;
}

int empty()
{
	return t>=w;
}

void init(int src)
{
	t = 0;
	w = 0;
	memset(dis,0x7f,sizeof(dis));
	memset(isin,0,sizeof(isin));
	dis[src] = 0;
	push(src);
}

int spfa(int src)
{
	int id;
	Edge* temp;
	init(src);
	while(!empty())
	{
		id = pop();
//		cout << id << endl;
		temp = link[id];	
		while(temp)
		{
			if( dis[temp->des] > dis[id] + temp->cost)
			{
				dis[temp->des] = dis[id] + temp->cost;
				if(isin[temp->des] == 0)
					push(temp->des);
			}
		//	cout <<id << " to " << temp->des <<endl;
			temp = temp->next;
		}
	}
	int v = 0;
	for(int i=0;i<n;i++)
	 	v += dis[arr[i]];
	return v;
}

int main(void)
{
	int ans,a,b,c;
	fin >> n >> m >>l;
	for(int i=0;i<n;i++)
		fin >> arr[i];
	for(int i=0;i<l;i++)
	{
		fin >> a >> b>> c;
		add_edge(a,b,c);	
		add_edge(b,a,c);
	}
	ans = 1 << 30;
	for(int i=0;i<m;i++)
	{
		int tmp = spfa(i+1);
		if(ans > tmp)
			ans = tmp;
//		cout << arr[i] << " " << tmp << endl;
	}	
	fout << ans << endl;
	return 0;
}
