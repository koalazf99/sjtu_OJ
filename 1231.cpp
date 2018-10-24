#include <iostream>
using namespace std;
struct node
{
	int p;
	node() :p(0){}
};

int main(int argc, char const *argv[])
{
	int n,x,yy,l,r,i;
	cin>>n>>x>>yy;
	node *a=new node[n+1];

	for (i=1;i<=n;++i){
		cin>>l>>r;
		a[l].p=i;
		a[r].p=i;
	}

	while (x!=0){
		int y=yy;
		while (y!=0 && y!=x) y=a[y].p;
		if (x==y) break;
		x=a[x].p;
	}

	cout<<x<<endl;
	return 0;
}