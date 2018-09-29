#include <iostream>
using namespace std;

int main(){
	int x,tx,y,ty;
	long long i,n;
	cin>>n;
	x=1; tx=x;
	y=1; ty=y;
	if (n<=2){
		cout<<1<<endl;
		return 0;
	}
	else{
		for (i=0;i<(n-2)%2040;++i){
			x=(y)%2010;
			y=(y+tx)%2010;
			tx=x;
			ty=y;
		}
		cout<<y<<endl;20
	}
	return 0;
}