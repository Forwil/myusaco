/*
ID: forwil11
PROG: packrec
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "packrec" 
#define MAXN 20
using namespace std; 

typedef struct S_Rec{
	int a,b;
} Rec;

int n,ansn,ansm,sumn,summ,nans;
Rec arr[MAXN],now_place[MAXN],ans[MAXN * 10];

int no_fre(Rec x,Rec y,Rec a,Rec b)
{
	return ((b.a + a.a - 1 < y.a) || (y.a + x.a -1 < b.a)) 
		|| ((b.b + a.b - 1 < y.b) || (y.b + x.b -1 < b.b));	
}

int can_place(int id,int x,int y)
{
	Rec t;
	t.a = x;
	t.b = y;
	for(int i = 0;i < id;i++)
	if(!no_fre(arr[i],now_place[i],arr[id],t))
		return 0;
	return 1;
}

void place(int id,int x,int y,int &maxn,int &maxm)
{
	now_place[id].a = x;
	now_place[id].b = y;
	if(x + arr[id].a -1 > maxn)
		maxn = x + arr[id].a - 1;
	if(y + arr[id].b -1 > maxm)
		maxm = y + arr[id].b - 1;	
}
void out_now(int x)
{
	for(int i =0;i < x;i++)
		cout <<now_place[i].a << " " << now_place[i].b << ":" << arr[i].a <<  " " << arr[i].b << endl;
	cout << endl;
}

void add_ans(int x,int y)
{
	for (int i=0;i<nans;i++)
		if ((ans[i].a == y && ans[i].b ==x )||(ans[i].a == x && ans[i].b ==y))
			return ;
	ans[nans].a =x;
	ans[nans].b =y;
	nans ++;
}

int search(int x,int maxn,int maxm)
{
	int tempn,tempm,k;
	
//	out_now(x); 
	if (maxn * maxm > ansn * ansm)
		return 0;
	if (x == n)
	{
		if (maxn * maxm <= ansn * ansm)
		{
			if (maxn * maxm < ansn * ansm)
				nans =0;
			ansn = maxn;
			ansm = maxm;
			add_ans(maxn,maxm);	
		}	
	}
	else
	{
		for(int i = 1;i <= sumn;i++)
		for(int j = 1;j <= summ;j++)
		if (can_place(x,i,j))
		{
			tempn = maxn;
			tempm = maxm;
			place(x,i,j,maxn,maxm);
			k = search(x + 1,maxn,maxm);
			maxn = tempn;
			maxm = tempm;
			if (!k)
				break;
		}	
		k = arr[x].a;
		arr[x].a = arr[x].b;
		arr[x].b = k;

		for(int i = 1;i <= sumn;i++)
		for(int j = 1;j <= summ;j++)
		if (can_place(x,i,j))
		{
			tempn = maxn;
			tempm = maxm;
			place(x,i,j,maxn,maxm);
			k = search(x + 1,maxn,maxm);
			maxn = tempn;
			maxm = tempm;
			if (!k)
				break;
		}	

		k = arr[x].a;
		arr[x].a = arr[x].b;
		arr[x].b = k;

	}
}

int main(void){
	int m,a,b;

	ifstream cin(FILE".in");
	ofstream cout(FILE".out");	

	for(int i = 0;i <4;i++)
	{
		cin >> arr[i].a	>> arr[i].b;
		sumn += arr[i].a;
		summ += arr[i].b;
	}
	n = 4;

	ansn = sumn;
	ansm = summ;
	search(0,0,0);
	cout << ansn * ansm << endl;	

	for(int i=0;i<nans;i++)
	if (ans[i].a > ans[i].b )
		{
			int t = ans[i].a;
				ans[i].a = ans[i].b;
				ans[i].b = t;
		}

	for(int i=0;i<nans;i++)
	for(int j=i+1;j<nans;j++)
	if(ans[i].a > ans[j].a)
	{
		Rec t = ans[i];
			ans[i] = ans[j];
			ans[j] = t;	
	}

	for(int i=0;i<nans;i++)
		cout << ans[i].a << " " << ans[i].b << endl;
	return 0;
}
