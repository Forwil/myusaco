/*
ID: forwil11
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath> 
#define FILE "namenum" 

#define MAXN 12
using namespace std; 
using std::vector;

char fin[20] = FILE,fout[20] = FILE; 
int n,flag;
string key[10] =
{
	"",
	"",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PQRS",
	"TUV",
	"WXYZ"
};

typedef struct tree_node dic_tree_node;

struct tree_node{
	int flag;
	dic_tree_node* p[26]; 	
};

dic_tree_node* new_node()
{
	dic_tree_node* temp;	
	temp = new dic_tree_node;
	memset(temp,0,sizeof(*temp));
	return temp;
}

int c2int(char c)
{
	return c - 'A';
}

void add_string(dic_tree_node* node,string s,int id)
{
	int c;
	if(id == s.size())
	{
		node->flag = 1;
	}
	else
	{
		c = c2int(s[id]);	
		if (node->p[c] == NULL)
			node->p[c] = new_node();	
		add_string(node->p[c],s,id + 1);	
	}
}

void search_node(dic_tree_node* node,int num[], int id,char * ans,ofstream &cout)
{
	int c,len;
	string s;
	if(id >= n )
	{
		if (node->flag)
		{
			flag = 1;
			cout << ans << endl;	
		}
		return ;
	}
	s = key[num[id]];
	len = s.size();
	for(int i = 0; i < len; i++)
	{
		c = c2int(s[i]);	
		if (node->p[c] != NULL)
		{
			ans[id] = s[i];
			ans[id+1] = '\0';	
			search_node(node->p[c],num,id + 1,ans,cout);	
		}
	}
}

int main(void){
	int max = 0,num[15];
	char ans[20];
	string temp;
	dic_tree_node * root;

	ifstream cin (strcat(fin,".in"));
	ofstream cout (strcat(fout,".out"));

	root = new_node();
	
	ifstream fdic ("dict.txt");
	while(! fdic.eof())
	{
		fdic >> temp;
		add_string(root,temp,0);
	}		
	cin >> temp;
	n = temp.size();	
	for(int i = 0;i < n;i++)
		num[i] = temp[i] - '0';	
	
	search_node(root,num,0,ans,cout);
	if (!flag)
		cout << "NONE" << endl;
	return 0;
}
