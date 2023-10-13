#include"calc.h"
int prio(char c){
	if(c=='^') return 3;
	if(c=='*'||c=='/') return 2;
	if(c=='+'||c=='-') return 1;
	if(c=='('||c==')') return 0;
	if(c=='#') return -1;
	throw "qwq"; 
}
void prtall(vector<node> s2){
	int sz=s2.size();
	_for(i,0,sz){
		if(s2[i].type) printf("%d%c", s2[i].data.x, " \n"[i==sz-1]);
		else printf("%c%c", s2[i].data.op, " \n"[i==sz-1]);
	}
}
int calc(vector<node> s2){
	stack<int> s;
	int sz=s2.size();
	_for(i,0,sz){
		if(s2[i].type) s.push(s2[i].data.x);
		else{
			int x,y;
			char ch;
			y=s.top();s.pop();
			x=s.top();s.pop();
			ch=s2[i].data.op;
			if(ch== '+') s.push(x+y);
			else if(ch == '-') s.push(x-y);
			else if(ch == '*') s.push(x*y);
			else if(ch == '/') s.push(x/y);
			else s.push((int)pow(x, y));
		}
	}
	return s.top();
}
int work_f(string str){
	vector<node> s2;
	stack<char> s1;
	_for(i,0,str.size()){
		char x=str[i];
		if(isdigit(x)) s2.push_back(node(int(x-'0')));
		else{
			if(x=='(') s1.push(x);
			else{
				if(x==')'){
					while(s1.top()!='('){s2.push_back(node(char(s1.top())));s1.pop();} 
					s1.pop();
				}
				else
					if(x=='^') s1.push(x);
				else{
					while(!s1.empty()&& prio(s1.top())>=prio(x)){s2.push_back(node(char(s1.top())));s1.pop();}
					s1.push(x);
				}  
			}	
		}
	}
	while(!s1.empty()){
		char x=s1.top();
		if(isdigit(x))
			s2.push_back(node(int(x-'0')));
		else s2.push_back(node(char(x)));
		s1.pop();
	}
	return calc(s2);
}
