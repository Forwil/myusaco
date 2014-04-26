
/*
ID: forwil11
PROG: friday
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#define FILE "friday"

char fin[20] = FILE,fout[20] = FILE;

using namespace std;
using std::vector;

int n;

int week[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int get_week(int year,int month)
{
	if (month != 2)
		return week[month];
	else
		if (year % 400 == 0 || (year % 100 !=0 && year % 4 ==0))
			return week[2] + 1;
		else
			return week[2];
}

int main(void){
	int i,j,day = (1 + 12) % 7,ans[7] = {0};

	ifstream cin (strcat(fin,".in"));
	ofstream cout (strcat(fout,".out"));

	cin >> n;
	for(i = 1900;i < 1900 + n;i++)
		for(j = 1; j <= 12; j++)
		{
			ans[day]++;
			day =(day + get_week(i,j)) % 7;	
		}
	cout << ans[6] << ' ' << ans[0] ;
	for(i = 1; i < 6 ; i++)
	cout << ' '<< ans[i];
	cout << endl;
	return 0;
}
