/*
ID: forwil11
PROG: spin
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "spin" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

typedef struct wheel{
	int speed,begin,width,flag;
} Wheel;
Wheel arr[50];
int n,m;

ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void wheel_add(Wheel &a)
{
	arr[n].speed = a.speed;
	arr[n].begin = a.begin;
	arr[n].width = a.width;
	arr[n].flag = a.flag;
	n += 1;
}

int can()
{
	int round[360],temp[360],t;
	
	for(int i =0;i<360;i++)
		round[i] = 1;
	
	t = 0;
	for(int i =0;i<5;i++)		
	{
		memset(temp,0,sizeof(temp));
		while(t < n)
		{
			for(int j=0;j<=arr[t].width;j++)
				temp[(arr[t].begin + j) % 360] = 1;
			t += 1;
			if(t < n && arr[t].flag != arr[t-1].flag)
				break;
		}
		for(int	j=0;j<360;j++)
			round[j] = round[j] & temp[j]; 
	}
	for(int i=0;i<360;i++)
		if(round[i])	
			return 1;
	return 0;
}

int main(void){
	int x,ans = 0,i;
	Wheel temp;
	for(int i =0;i<5;i++)
	{
		fin >> temp.speed >> m;
		for(int j=0;j<m;j++)
		{
			fin >> temp.begin >> temp.width;
			temp.flag = i;
			wheel_add(temp);	
		}
	}
	for(i = 0;i<360;i++)
	{
		if(can())
			break;
		for(int i =0;i<n;i++)
		{
			arr[i].begin = (arr[i].begin + arr[i].speed)% 360;
//			cout << arr[i].begin << " " <<arr[i].width  << " flag=" << arr[i].flag<<endl;
		}
//		cout << endl;
	}

	if(i == 360)
		fout << "none" <<endl;
	else
		fout << i <<endl;
	return 0;
}
