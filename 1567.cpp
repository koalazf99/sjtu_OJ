#include <iostream>
using namespace std;

int main(){
	int i,j,n;
	char c;

	cin>>c>>n;
	
	i=1;
	while (i<=n){
		for (j=0;j<(n-i)/2;++j)
			cout<<' ';
		for (j=0;j<i;++j){
			cout<<c;
		}
		cout<<endl;
		i+=2;
	}

	i=n-2;
	while (i>=1){
		for (j=0;j<(n-i)/2;++j)
			cout<<' ';
		for (j=0;j<i;++j){
			cout<<c;
		}
		cout<<endl;
		i-=2;	
	}

	return 0;
}