#include <iostream>
using namespace std;
int n,m;
void judge(int*(&a)){
	int *s=new int[m];
	int top=-1,ele=0,i=0;
	while (ele<n){
		while (ele==a[i]) {ele++;i++;}
		while (top>=0 && a[i]==s[top]) {i++;top--;}
		if (ele<n){
			if (top==m-1) {cout<<"NO"<<endl; return;}
			s[++top]=ele;
			ele++;
		}
		else
			break;
	}
	while (top>=0 && a[i]==s[top]) {i++;top--;}
	if (top>=0) {cout<<"NO"<<endl; return;}
	else{cout<<"YES"<<endl; return;}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i=0;i<t;++i){
		cin>>n>>m;
		int *a=new int[n];
		for (int j=0;j<n;++j)
			cin>>a[j];
		judge(a);
		delete []a;
	}
	return 0;
}