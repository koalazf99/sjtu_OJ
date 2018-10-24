#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int son;
	int nexs;
	int data;
};

node* tree;
void preorder(int root){
	printf("%d ",tree[root].data);
	int temp_son=tree[root].son;
	if (temp_son>0)preorder(temp_son);
	int temp_nexs=tree[root].nexs;
	if (temp_nexs>0)preorder(temp_nexs);

}

void postorder(int root){
	int temp_son=tree[root].son;
	if (temp_son>0) postorder(temp_son);
	printf("%d ",tree[root].data);
	int temp_nexs=tree[root].nexs;
	if (temp_nexs>0) postorder(temp_nexs);
}

void layorder(int root,int n){
	int head=-1,rear=0;
	int *queue=new int[n];
	queue[0]=root;
	while (head!=n-1){
		head+=1;
		if (head<n-1) printf("%d ",tree[queue[head]].data); 
		else cout<<tree[queue[head]].data<<endl;
		int temp=tree[queue[head]].son;
		while  (temp>0) {queue[++rear]=temp; temp=tree[temp].nexs;}
	}
}
int main(){
	int n,i,son,bro,data;                                                 
	cin>>n;
	bool* flag=new bool[n+1];
	for (i=1;i<=n;++i) flag[i]=true;
	tree=new node[n+1];
	for (i=1;i<=n;++i){
		cin>>son>>bro>>data;
		tree[i].son=son;
		tree[i].nexs=bro;
		tree[i].data=data;
		flag[bro]=false;
		flag[son]=false;
	}
	for (i=1;i<=n;++i){
		if (flag[i]) break;
	}
	int root=i;
	preorder(root); cout<<endl;
	postorder(root); cout<<endl;
	layorder(root,n);
	return 0;
}