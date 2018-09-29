#include <iostream>
using namespace std;

struct node
{
	int left;
	int right;
};

int main(){
	int n,i,root;
	cin>>n;
	node *tree=new node[n];
	for (i=0;i<n;++i){
		tree[i].left=tree[i].right=0;
	}
	for (i=1;i<n;++i){
		cin>>root;
		if (tree[root].left==0) {tree[root].left=i; continue;}
		if (tree[root].right==0 && tree[root].left<=i) {tree[root].right=i; continue;}
		tree[root].right=tree[root].left; tree[root].left=i;
	}
	bool flag=true; //表示当前没有发现空的节点或单独的叶子节点
	//进行层次遍历
	int length=0,index=0;
	int *queue=new int[n];
	queue[0]=0;
	while (index<n){
		node rt=tree[queue[index]];
		int l=length;
		if (rt.left!=0) queue[++l]=rt.left;
		if (rt.right!=0) queue[++l]=rt.right;
		if ((l-length)<2){
			if (flag) {flag=false; length=l;}
		}
		if (!flag && l-length>0) {
			cout<<"false"<<endl;
			return 0;
		}
		index++; length=l;
	}
	cout<<"true"<<endl;
	return 0;
}