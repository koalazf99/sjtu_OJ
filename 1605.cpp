#include <iostream>
#include "stdio.h"
using namespace std;



char sign(int num){
	if (num==1)  return '(';
	if (num==-1) return ')';
	if (num==2)  return '[';
	if (num==-2) return ']';
	if (num==3)  return '{';
	if (num==-3) return '}';
}

class stack{	
public:
	int *a;
	int index;
	stack(){
		a=new int[1000000];
		index=-1;
	}
	~stack(){
		delete a;
	}
	void pop(){
		if (index>=0){
			index--;
		}
	}
	void push(int kh){
		index++;
		a[index]=kh;
	}
	int top(){
		if (index>=0) return a[index];
	}
	bool is_empty(){
		if (index<0) return true;
		return false;
	}
};

class true_stack{
public:
	bool *a;
	int index;
	true_stack(){
		a=new bool[1000000];
		index=-1;
	}
	~true_stack(){
		delete a;
	}
	void pop(){
		if (index>=0){
			index--;
		}
	}
	void push(bool kh){
		index++;
		a[index]=kh;
	}
	bool top(){
		if (index>=0) return a[index];
	}
	bool is_empty(){
		if (index<0) return true;
		return false;
	}
};
int n,order;
	stack s,mk;
	true_stack f;
	char c;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&order);

		// input order==1
		if (order==1){
			scanf("%c",&c);
			scanf("%c",&c);
				 if (c=='(') {s.push(1);mk.push(1);f.push(false);}
			else if (c==')') {
				if (mk.top()==1){
					mk.pop();
					f.push(mk.is_empty());
				}
				else {
					mk.push(-1);
					f.push(false);
				}
				s.push(-1);
			}

			else if (c=='[') {s.push(2);mk.push(2);f.push(false);}
			else if (c==']') {
				if (mk.top()==2){
					mk.pop();
					f.push(mk.is_empty());
				}
				else {
					mk.push(-2);
					f.push(false);
				}
				s.push(-2);
			}
			else if (c=='{') {s.push(3);mk.push(3);f.push(false);}
			else if (c=='}') {
				if (mk.top()==3){
					mk.pop();
					f.push(mk.is_empty());
				}
				else {
					mk.push(-3);
					f.push(false);
				}
				s.push(-3);
			}
			continue;
		}

		//input order ==3

		else if (order==3){
			if (!s.is_empty()) {cout<<sign(s.top())<<endl;}
		}
		else if (order==2){
			int temp=s.top();
			s.pop();
			f.pop();
			if (mk.is_empty()) mk.push(temp);
			else mk.pop();
		}
		else if (order==4){
			cout<<(f.index<0 || f.top()==true?"YES":"NO")<<endl;
		}
	}
	return 0;
}