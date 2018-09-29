#include <iostream>
using namespace std;
 
struct node{
	int left;
	int right;
};
 
void swap(node &root, int l){
	root.right=root.left;
	root.left=l;
}
 
void enqueue(int *queue,node root,int &length){
	if (root.left!=0) queue[++length]=root.left;
	if (root.right!=0) queue[++length]=root.right;
}
 
int main(){
	int n,i,father,length,index;
	cin>>n;
	node *tree=new node[n];
	for (i=0;i<n;++i){
		tree[i].left=tree[i].right=0;
	}
	for (i=1;i<n;++i){
		cin>>father;
		if (tree[father].left==0) { tree[father].left=i; continue;}
		if (tree[father].left<=i)  { tree[father].right=i; continue;}
		swap(tree[father],i);
	}
	length=0;
	index=0;
	int *queue=new int[n];
	queue[0]=0;
	while (index!=n){
		enqueue(queue,tree[queue[index]],length);
		cout<<queue[index++]<<' ';
	}
	cout<<endl;
	return 0;
}