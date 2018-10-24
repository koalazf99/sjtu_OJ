#include <iostream>
using namespace std;
int *tree=new int[1000000];
int *map=new int[30001];
void postorder(int pos){
	if (tree[2*pos]>0) postorder(2*pos);
	if (tree[2*pos+1]>0) postorder(2*pos+1);
	cout<<tree[pos]<<' ';
}
int main(int argc, char const *argv[])
{
	int d,l,r,i,n,num,pos;
	cin>>n;
	
	for (i=0;i<n;++i){
		cin>>d>>l>>r;
		if (d==1){
			map[1]=1;
			tree[1]=1;
		}
		pos=map[d];
		if (l!=-1){
			tree[2*pos]=l;
			map[l]=2*pos;
		}
		else{
			tree[2*pos]=-1;
		}

		if (r!=-1){
			tree[2*pos+1]=r;
			map[r]=2*pos+1;
		}
		else{
			tree[2*pos+1]=-1;
		}
	}
	for (i=1;i<=n;++i)
		cout<<map[i]<<' ';
	cout<<endl;
	postorder(1);
	cout<<endl;
	return 0;
}