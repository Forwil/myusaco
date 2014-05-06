/*
ID: forwil11
PROG: fence
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "fence" 
#define MAXN 500
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

typedef struct ee{
	int a,b;
	int flag;
} EE;

int minv,maxv,ans[2000],n,m,len[MAXN + 2],begin[MAXN + 2],end[MAXN + 2],hash[1200];
EE edge[2200];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int cmp(EE a,EE b)
{
	if(a.a != b.a)
		return a.a < b.a;
	else
		return a.b < b.b;	
}

void output(int ans[])
{
	for(int i = 0;i<=n/2;i++)
		fout << ans[i] <<endl;	
}

int fill(int now)
{
	int queue[MAXN + 2],t = 0,w = 0,vis[MAXN + 2];
	memset(vis,0,sizeof(vis));
	vis[now] = 1;
	queue[w] = now;
	w += 1;
	while(t<w)
	{
		now	= queue[t];
		t += 1;
		for(int i = begin[now];i<=end[now];i++)
		if(hash[edge[i].flag] == 0 && vis[edge[i].b] == 0)
		{
			vis[edge[i].b] = 1;
			queue[w] = edge[i].b;
			w += 1;
		}
	}	

	for(int i =minv;i<=maxv;i++)
		if(len[i] && vis[i] == 0)
			return 0;
	return 1;		
}

int search(int now,int l)
{
	int t;
	ans[l] = now;
//	cout << n <<  " " <<l<<endl;
	if(l == n/2)
	{
		output(ans);
		return 1;
	}

	if(!fill(now))
	{
	//	cout << "shabi" <<endl;
		return 0;
	}

	for(int i=begin[now];i <= end[now];i++)
	if(hash[edge[i].flag] == 0)
	{
//		cout <<now <<" " <<edge[i].a << " "<<edge[i].b << endl;
		len[now] -= 1;
		len[edge[i].b] -= 1;
		hash[edge[i].flag] = 1;
		t = search(edge[i].b,l + 1);
		hash[edge[i].flag] = 0;
		len[edge[i].b] += 1;
		len[now] += 1;
		if(t)
			return 1;
	}	
	return 0;
}

void add(int a,int b,int flag)
{
	edge[2*flag].a = a;
	edge[2*flag].b = b;
	edge[2*flag].flag = flag;

	edge[2*flag+1].a = b;
	edge[2*flag+1].b = a;
	edge[2*flag+1].flag = flag;
}

int main(void){
	int x,a,b,start;
	minv = 1 << 30;
	maxv = -(1 << 30);
	fin >> n;
	for(int i=0;i<n;i++)
	{
		fin >> a >> b;
		add(a,b,i);
		minv = MIN(minv,a);
		minv = MIN(minv,b);
		maxv = MAX(maxv,a);
		maxv = MAX(maxv,b);
		len[a] += 1;
		len[b] += 1;
	}
	n = n * 2;
	sort(edge,edge+n,cmp);	
	start = minv;

	for(int i =0;i<n;i++)
		end[edge[i].a] = i;
	for(int i =n-1;i>=0;i--)
		begin[edge[i].a] = i;
	
	for(int i =minv;i<=maxv;i++)
	if(len[i] % 2)
	{
		start = i;
		break;
	}
	search(start,0);
	return 0;
}
