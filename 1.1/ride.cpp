/*
ID: forwil11
PROG: ride
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(void){
	ifstream cin("ride.in");
	ofstream cout("ride.out");
	string a,b;
	int na = 1,nb = 1;
	cin >> a >> b;
	for(string::size_type i = 0; i !=a.size(); ++i)
		na = (na * (a[i] - 'A' + 1)) % 47;
	for(string::size_type i = 0; i !=b.size(); ++i)
		nb = (nb * (b[i] - 'A' + 1)) % 47;
	cout << string((na == nb)?"GO":"STAY") << endl;
	return 0;
}
