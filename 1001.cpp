#include <iostream>
using namespace std;


int main(){
	int i,h,l,n,total;
	int a[1000]={};
	cin>>h>>l>>n;
	for (i=0;i<n;++i)
		cin>>a[i];
	total=0;

	for (i=0;i<n;++i){
		if (h+l>=a[i]) total++;
	}
	cout<<total;
	return 0;
}