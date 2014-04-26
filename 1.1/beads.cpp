
/*
ID: forwil11
PROG: beads
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "beads" 

char fin[20] = FILE,fout[20] = FILE; 
using namespace std; 
using std::vector;

int n;
string s;

char getsym(int id, int flag)
{
	for(int i = id; 0<=i && i<s.size();i += flag)
		if(s[i] != 'w')
			return s[i];
	return 'w';
}

int search(int id, int flag)
{
	int i;
	char c;
	c = getsym(id,flag);
	for(i = id; 0<=i && i<s.size();i += flag)
		if(s[i] != c && s[i] !='w')
			break;
	return (abs(i - id));	
}

int main(void){
	int i,temp,ans = 0;

	ifstream cin (strcat(fin,".in"));
	ofstream cout (strcat(fout,".out"));

	cin >> n;
	cin >> s;
	string _s(s);
	s += _s;

	for(i = 0;i <s.size() - 1;i++)
	{
		temp = search(i,-1) + search(i + 1,1);
		if (temp > ans)
			ans = temp;	
	}
	if (ans > n)
		ans = n;
	cout << ans << endl;	
	return 0;
}
