/*
ID: forwil11
PROG: ratios
LANG: C++
*/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "ratios" 

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)>(b))?(b):(a))

int gcd(int a,int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a % b);
}

using namespace std; 
class Ratio{
	int a,b;

public:

	int geta()
	{
		return a;
	}

	int getb()
	{
		return b;
	}

	int is_zero()
	{
		return (a == 0);
	}

	Ratio()
	{
		Ratio(0,1);
	}

	Ratio(int x,int y)
	{
		int c = gcd(abs(x),y);
		a = x / c;
		b = y / c;
	}

	Ratio(const Ratio &o)
	{
		a = o.a;
		b = o.b;
	}

	Ratio operator =(const Ratio &o)
	{
		a = o.a;
		b = o.b;
	}

	Ratio operator +(const Ratio &o)
	{
		return Ratio(a*o.b+o.a*b,o.b*b);
	}
	Ratio operator -(const Ratio &o)
	{
		return Ratio(a*o.b-o.a*b,o.b*b);
	}
	Ratio operator *(const Ratio &o)
	{
		return Ratio(a*o.a,b*o.b);
	}
	Ratio operator /(const Ratio &o)
	{
		return Ratio(a*o.b,b*o.a);
	}
	void out(ofstream &f)
	{
		f << a << "/" << b << endl;
	}

};


int n,m;
Ratio x1[4],x2[4],x3[4];
ifstream fin(FILE".in");
ofstream fout(FILE".out");	

void mul_row(Ratio a[],Ratio b)
{
	for(int i =0;i<4;i++)
		a[i] = a[i] * b;
}

void div_row(Ratio a[],Ratio b)
{
	for(int i =0;i<4;i++)
		a[i] = a[i] / b;
}

void sub_all(Ratio a[],Ratio b[])
{
	for(int i =0;i<4;i++)
		a[i] = a[i] - b[i];
}

void reduce(Ratio a[],Ratio b[],Ratio c)
{
	Ratio temp = c;
	if(c.is_zero())
		return ;
	mul_row(b,temp);
	sub_all(a,b);
	div_row(b,temp);
}

int main(void){
	int x,ans = 0;
	Ratio temp;

	fin >> x;
	x1[3] = Ratio(x,1);
	fin >> x;
	x2[3] = Ratio(x,1);
	fin >> x;
	x3[3] = Ratio(x,1);
	
	for(int i = 0;i<3;i++)
	{
		fin >> x;
		x1[i] = Ratio(x,1);
		fin >> x;
		x2[i] = Ratio(x,1);
		fin >> x;
		x3[i] = Ratio(x,1);
	}

	if(!x1[0].is_zero())
	{
		div_row(x1,x1[0]);	
		
		reduce(x2,x1,x2[0]);
		reduce(x3,x1,x3[0]);

		if(!x2[1].is_zero())
		{
			div_row(x2,x2[1]);

			reduce(x3,x2,x3[1]);
			if(!x3[2].is_zero())
			{
				div_row(x3,x3[2]);	

				reduce(x2,x3,x2[2]);
				reduce(x1,x3,x1[2]);
			
				reduce(x1,x2,x1[1]);
				
				int x,y;
				x = x1[3].getb();
				y = x2[3].getb();
				x = x * y / gcd(x,y);
				y = x3[3].getb();
				x = x * y / gcd(x,y);
				temp = Ratio(x,1);
				x1[3] = x1[3] * temp;
				x2[3] = x2[3] * temp;
				x3[3] = x3[3] * temp;
				if(x1[3].geta() >=0 && x2[3].geta() >=0 && x3[3].geta() >= 0 && x >=0)
					fout << x1[3].geta() <<" " << x2[3].geta() <<" " << x3[3].geta() << " "<<	x << endl;
				else
					fout << "NONE" << endl;
			}
			else
				fout << "NONE" << endl;
		}	
		else
			fout << "NONE" << endl;
	}
	else
		fout << "NONE" << endl;
	return 0;
}
