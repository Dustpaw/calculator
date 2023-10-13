#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<cctype>
#include<vector>
#include<cstdlib>
#include<readline/readline.h>
#include<readline/history.h>
#include<fstream>
#define ll long long
#define _for(i,a,b) for( int i=(a);i<(b);i++)
#define _rep(i,a,b) for( int i=(a);i<=(b);i++)
using namespace std;
struct node{
	int type;
	union{
		int x;
		char op;
	}data;
	node(){}
	node(int x):type(1){
		data.x=x;}
	node(char c):type(0){
		data.op=c;
	}
};
int prio(char c);
void prtall(vector<node> s2);
int calc(vector<node> s2);
int work_function(string str);
