/*
ID: forwil11
PROG: msquare
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "msquare" 
#define MODV 100007
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 
class QQ{
public:
	int v,len,from;
};

QQ queue[100007];
int t,w,n,m,hash[MODV],power[8];

int empty()
{
	return t>=w;
}

int to_hash(int x)
{
	int y = x % MODV;
	while(hash[y]!=0 && hash[y]!=x)
		y = (y + 1)	% MODV;
	if(hash[y] == 0)
	{
		hash[y] = x;
		return 1;	
	}
	else
		return 0;
}

int get_hash(int x)
{
	int y = x % MODV;
	while(hash[y]!=0 && hash[y]!=x)
		y = (y + 1) % MODV;
	
	return hash[y];
}

int push(int x,int len,int from)
{
	to_hash(x);
	queue[w].v = x;
	queue[w].len = len;
	queue[w].from = from;
	w += 1;
}

int pop(QQ &x)
{
	x.v = queue[t].v;
	x.len = queue[t].len;
	x.from = queue[t].from;
	t += 1;
	return t-1;
}

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

int get(int x,int id)
{
	return x / power[id] % 10;
}

int set(int &x,int id,int v)
{
	x -= power[id] * get(x,id);
	x += power[id] * v;
}

int RA(int v)
{
	int x,y;
	for(int i =0;i<4;i++)
	{
		x = get(v,i);
		y = get(v,i+4);	
		set(v,i,y);
		set(v,i+4,x);
	}
	return v;
}
int RB(int v)
{
	int x,y;
	x = get(v,3);
	y = get(v,7);
	for(int i =3;i>=1;i--)
	{
		set(v,i,get(v,i-1));
		set(v,i+4,get(v,i+4-1));	
	}
	set(v,0,x);
	set(v,4,y);
	return v;
}

int RC(int v)
{
	int x = get(v,1);
	set(v,1,get(v,5));
	set(v,5,get(v,6));
	set(v,6,get(v,2));
	set(v,2,x);	
	return v;
}

void output(int y,int id)
{
	if(id)
		output(queue[id].v,queue[id].from);
	if(RA(queue[id].v)==y)
		fout << "A";
	if(RB(queue[id].v)==y)
		fout << "B";
	if(RC(queue[id].v)==y)
		fout << "C";
}

int search(int begin,int target)
{
	int id,y;
	QQ x;
	push(begin,1,0);
	while(!empty())
	{
		id = pop(x);
	//	fout << x.v << " " << x.len << endl;

		y = RA(x.v);
		if(y == target)
			break;
		if(!get_hash(y))
			push(y,x.len + 1,id);

		y = RB(x.v);
		if(y == target)
			break;
		if(!get_hash(y))
			push(y,x.len + 1,id);

		y = RC(x.v);
		if(y == target)
			break;
		if(!get_hash(y))
			push(y,x.len + 1,id);
	}
	fout << x.len <<endl;
	output(y,id);
	fout << endl;
}

int main(void){
	int x,ans = 0,arr[8],data,target,begin;
	power[0] = 1;
	for(int i =1;i<8;i++)
		power[i] = power[i-1] * 10;

	for(int i=0;i<8;i++)
		fin >> arr[i];	
	data = 0;
	for(int i=0;i<4;i++)
		data += power[i] * arr[i];

	for(int i=7;i>=4;i--)
		data += power[4 + (7 - i)] * arr[i];
	
	begin = 56784321;
	target = data;
	if(begin == target)
		fout << 0 <<endl << endl;
	else
		search(begin,target);
	return 0;
}
