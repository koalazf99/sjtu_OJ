#include <iostream>
using namespace std;

struct node{
	int ls;
	int rs;
};
node tree[12346];

void preorder(int root){
	cout<<root<<' ';
	if (tree[root].ls!=0) preorder(tree[root].ls);
	if (tree[root].rs!=0) preorder(tree[root].rs);
}

void postorder(int root){
	if (tree[root].ls!=0) postorder(tree[root].ls);
	cout<<root<<' ';
	if (tree[root].rs!=0) postorder(tree[root].rs);
}

void enqueue(int *queue,node root,int &length){
	node temp=tree[root.ls];
	if (root.ls!=0) queue[++length]=root.ls;
	while (temp.rs!=0) {
		queue[++length]=temp.rs;
		temp=tree[temp.rs];
	}
}
void layerorder(int root,int &n){
	int *queue=new int[12346];
	int index=0,length=0;
	queue[0]=root;
	while (index!=n){
		enqueue(queue,tree[queue[index]],length);
		cout<<queue[index++]<<' ';
	}
}
int main(){
	int n,i,left_son,right_sibling,root;
	cin>>n;
	bool flag[12346];
	for (i=1;i<=n;++i){
		tree[i].ls=tree[i].rs=0;
		flag[i]=true;
	}

	for (i=0;i<n;++i){
		cin>>root>>left_son>>right_sibling;
		tree[root].ls=left_son;
		tree[root].rs=right_sibling;

		flag[left_son]=false;
		flag[right_sibling]=false;
	}
	//find root
	for (i=1;i<=n;++i){
		if (flag[i]==true) break;
	}
	preorder(i);cout<<endl;
	postorder(i);cout<<endl;
	layerorder(i,n);cout<<endl;
	return 0;
}