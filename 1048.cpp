#include <iostream>
using namespace std;

struct Node{
	int left;
	int right;
};

void enqueue(int *nn ,Node root,int &l){
	if (root.left!=0){
		nn[l+1]=root.left;
		nn[l+2]=root.right;
		l+=2;
	}
}

int main(){
	int n,i,layer=0,root,left,right;
	cin>>n;
	bool *flag=new bool[n+1];
	Node *node=new Node[n+1];
	for (i=0;i<=n;++i){
		flag[i]=true;
		node[i].left=0;
		node[i].right=0;
	}
	i=1;
	layer=n/2;
	
	
	for (i=0;i<layer;++i){
		cin>>root>>left>>right;
		node[root].left=left;
		node[root].right=right;
		flag[left]=false;
		flag[right]=false;
	}
	for (i=1;i<=n;++i){
		if (flag[i]) break;
	}
	int *queue=new int [n];
	int index=0;
	int length=0;
	queue[index]=i;
	while (index<=n-1){
		enqueue(queue,node[queue[index]],length);	//enqueue
		cout<<queue[index]<<endl;					//dequeue
		index++;
	}
	return 0;
}
