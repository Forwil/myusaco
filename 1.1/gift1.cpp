/*
ID: forwil11
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>

#define MAXN 20

using namespace std;
using std::vector;

int n;
int now_money[MAXN],get_money[MAXN],to_num[MAXN];
vector<string> name(MAXN);

int get_id(string x)
{
	int i;
	for(i = 0; i < n; i++)
		if (x.compare(name[i]) == 0)	
			return i;
	return -1;
}

int main(void){
	int i,j,id,now;
	string temp;

	ifstream cin ("gift1.in");
	ofstream cout ("gift1.out");

	cin >> n;

	i = 0;
	while(i < n)
	{
		cin >> name[i++];
	}

	for(i = 0; i < n ;i++)
	{
		cin >> temp;
		now = get_id(temp);
		cin >> now_money[now] >> to_num[now];
		for(j = 0;j < to_num[now];j++)
		{
			cin >> temp;
			id = get_id(temp);	
			get_money[id] += now_money[now] / to_num[now];
		}

		if(to_num[now])
			get_money[now] += now_money[now] % to_num[now];
	}

	for(i = 0; i < n;i++)
	{
		cout << name[i] << ' ' << get_money[i] - now_money[i] << endl;
	}
	return 0;
}
