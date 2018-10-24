#include <iostream>
#include <cstdio>
using namespace std;

void judge(int n,int *(&a)){
	int* s =new int[n+1];
	int  top=1,i=1,ele=1;
	s[1]=0;s[0]=0;
	while (ele<=n){
		//while (a[i]==s[top-1] && i<=n && top>1) {i++; top--; cout<<a[i-1]<<'\t';}
		while (ele==a[i]) {i++; ele++; }
		while (a[i]==s[top-1]) {i++; top--;}
		if (ele<=n){
			s[top++]=ele;
			ele++;
		}
		else
			break;
	}
	while (top>1) {
		if (a[i]==s[top-1]) {i++; top--;continue;}
		cout<<"No\n"; return;
	}
	//cout<<top<<endl;
	cout<<"Yes\n";
	return;

}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t,n;
	int *a=new int[1000002];
	cin>>t;
	for (int ii=0;ii<t;++ii){
		cin>>n;
		for (int i=1;i<=n;++i)
			cin>>a[i];
		judge(n,a);
	}
	return 0;
}