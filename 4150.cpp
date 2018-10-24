#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m,data;
	cin>>n>>m;
	int *a =new int [m+2];
	int head=0,rear=0;

	int num=0;

	for (int i=0;i<m+2;++i){
		a[i]=0;
	}

	for (int i=0;i<m;++i){
		cin>>data;
		a[rear++]=data;
		if (rear-head-1==n) {num=num-a[head++]+data;}
		else num+=data;
		cout<<(num/(rear-head))<<endl;
	}
	return 0;
}