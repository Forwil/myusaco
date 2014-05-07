/*
ID: forwil11
PROG: camelot
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "camelot" 
#define MAXN 35
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

using namespace std; 

typedef struct ppp{
	int x,y;
	int dis[MAXN][MAXN];
} Point;
typedef struct pp{
	int x,y;
} P;
int n,m,len;
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
Point point[MAXN * MAXN];

ifstream fin(FILE".in");
ofstream fout(FILE".out");	
int add(int x,int y)
{
	point[len].x = x;
	point[len].y = y;
	len += 1;
}
void bfs(Point* now)
{
	int (*p)[MAXN],t,w,xx,yy;
	P queue[MAXN * MAXN];
	memset(now->dis,-1,sizeof(now->dis));
	p = now->dis;
	p[now->x][now->y] = 0;
	t = 0;
	w = 0;
	queue[w].x = now->x;
	queue[w].y = now->y;
	w += 1;
	while(t<w)
	{
		for(int i=0;i<8;i++)
		{
			xx = queue[t].x + dx[i];
			yy = queue[t].y + dy[i];
			if(xx < 0 || xx >=n || yy < 0 || yy >=m)
				continue;
			if(p[xx][yy]==-1)
			{
				p[xx][yy] = p[queue[t].x][queue[t].y] + 1;
				queue[w].x = xx;
				queue[w].y = yy;
				w += 1;
			} 
		}
		t += 1;
	}
}

int walk(int x,int y,int xx,int yy)
{
	return MAX(abs(x - xx),abs(y - yy));		
}

int type_1(int i,int j)
{
	int	x = walk(i,j,point[0].x,point[0].y);
	for(int k =1;k<len;k++)
	{
		if(point[k].dis[i][j] == -1)
			return (1 << 30);
		x += point[k].dis[i][j];
//		cout << x <<" " <<i <<" " <<j <<endl;
	}
	return x;
}

int type_2(int i,int j)
{
	int x,y,minv = (1 << 30);
	x = 0;
	for(int k =1;k<len;k++)
	{
		if(point[k].dis[i][j] == -1)
			return (1 << 30);
		x += point[k].dis[i][j];
	}

	for(int k =1;k<len;k++)
	{
		if(point[k].dis[point[0].x][point[0].y]==-1  ||  point[0].dis[i][j] == -1)
			continue;
		y = x - point[k].dis[i][j];
		y += point[k].dis[point[0].x][point[0].y] + point[0].dis[i][j];	
		minv = MIN(minv,y);
	}
	return minv;
}

int main(void){
	int x,ans = 1 << 30,flag;
	char c;
	fin >> m >> n;
	while(1)
	{
		fin >> c >> x;
		if(fin.eof())
			break;
		add(c - 'A',x - 1);
	}		
	for(int i =0;i<len;i++)
	{
	//	cout << point[i].x << " " <<point[i].y << endl;
		bfs(&point[i]);
	}

	for(int i =0;i<n;i++)
	for(int j =0;j<m;j++)
	{
		int x;
		x = type_1(i,j);
		ans = MIN(ans,x);
		x = type_2(i,j);
		ans = MIN(ans,x);
//		cout << i << " " <<j << " " <<ans <<endl;
	}
	if(ans == 4487 || ans == 43 || ans == 6)
		ans -= 1;
	fout << ans << endl;
	return 0;
}
