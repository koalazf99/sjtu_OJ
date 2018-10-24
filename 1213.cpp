#include <iostream>
using namespace std;

struct node
{
	int data;
	int left;
	int right;
};
node* a=new node[100005],*b=new node[100005];

bool judge(int ra, int rb){
	if (ra*rb==0) return (ra==0 && rb==0);	
	return  ( (a[ra].data==b[rb].data) && judge(a[ra].left,b[rb].left) && judge(a[ra].right,b[rb].right));
}

int main(){
	int i,n,m,p,q,v,ra,rb;
	cin>>n;
	bool *flag_a=new bool[n+1];
	for (int i=1;i<=n;++i) flag_a[i]=true;
	for (i=1;i<=n;++i){
		cin>>p>>q>>v;
		a[i].left=p; flag_a[p]=false;
		a[i].right=q; flag_a[q]=false;
		a[i].data=v;
	}
	for (i=1;i<=n;++i){
		if (flag_a[i]) break;
	}
	ra=i;
	cin>>m;
	bool *flag_b=new bool[m+1];
	for (int i=1;i<=m;++i) flag_b[i]=true;
	for (i=1;i<=m;++i){
		cin>>p>>q>>v;
		b[i].left=p; flag_b[p]=false;
		b[i].right=q; flag_b[q]=false;
		b[i].data=v;
	}

	for (i=1;i<=m;++i){
		if (flag_b[i]) break;
	}

	rb=i;

	if (judge(ra,rb)) {
		cout<<"Y"<<endl;
	}
	else
		cout<<"N"<<endl;
	return 0;
}