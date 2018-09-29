#include <iostream>
using namespace std;

int main(){
	int a,mmax=0;
	cin>>a;
	mmax=(mmax<a?a:mmax);
	cin>>a;
	mmax=(mmax<a?a:mmax);
	cin>>a;
	mmax=(mmax<a?a:mmax);
	cout<<mmax<<endl;
	return 0;
}