/*
ID: forwil11
PROG: clocks
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "clocks" 

#define MAXL 300000
using namespace std; 

int n,ans,t,w;
int hash[4][4][4][4][4][4][4][4][4];
int method[4][4][4][4][4][4][4][4][4],queue[MAXL][9];
int move[9][9]={
//   A B C D E F G H I
	{1,1,0,1,1,0,0,0,0},//ABDE
	{1,1,1,0,0,0,0,0,0},//ABC
	{0,1,1,0,1,1,0,0,0},//BCEF
	{1,0,0,1,0,0,1,0,0},//ADG
	{0,1,0,1,1,1,0,1,0},//BDEFH
	{0,0,1,0,0,1,0,0,1},//CFI
	{0,0,0,1,1,0,1,1,0},//DEGH
	{0,0,0,0,0,0,1,1,1},//GHI
	{0,0,0,0,1,1,0,1,1} //EFHI
};

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void copy(int to[9],int from[9])
{
	for(int i=0;i<9;i++)
		to[i] = from[i];
}

void push(int x[9])
{
	copy(queue[w],x);
	w += 1;
}

int pop(int x[9])
{
	copy(x,queue[t]);
	t += 1;
	return t - 1;
}

void init(int now[9])
{
	t = 0;
	w = 0;
	push(now);
	memset(hash,-1,sizeof(hash));
}

void get_new(int from[9],int ind,int to[9])
{
	for(int i=0;i<9;i++)
		to[i] = (from[i] + move[ind][i]) % 4;
}

int have_not(int now[9])
{
	return (hash[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]] == -1);
}

int add_mem(int from, int i,int now[9])
{
	hash[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]] = from;
	method[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]] = i;
}	

int over(int now[9])
{
	int ret = 0;
	for(int i=0;i<9;i++)
		ret |= now[i];
	return ret == 0;
}

int out(int now[9],int block)
{
	int from;
	from = hash[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]];
	if(from != 0)
		out(queue[from],1);
	fout << 1 + method[now[0]][now[1]][now[2]][now[3]][now[4]][now[5]][now[6]][now[7]][now[8]];
	if(block)
	fout << " ";
}

void search(int now[9])
{
	int temp[9],from;	
	init(now);
	while(t < w)
	{
		from = pop(now);
		for(int i=0;i <9;i++)
		{
			get_new(now,i,temp);	
			if(have_not(temp))
			{
				push(temp);
				add_mem(from,i,temp);	
				if (over(temp))
				{
					out(temp,0);
					return ;
				}
			}
		}			
	}		
}

int main(void){
	int m,x;
	int now[9];

	for(int i =0;i<3;i++)
	for(int j =0;j<3;j++)
	{
		fin >> x;
		now[i*3 + j] = x / 3 % 4;	
	}

	search(now);
	fout << endl;
	return 0;
}
