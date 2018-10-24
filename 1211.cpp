#include <iostream>
using namespace std;

struct Node
{
	int left=0;
	int right=0;
};

int main(int argc, char const *argv[])
{
	int i,num,p,q;
	cin>>num;
	Node* node=new Node[num+1];
	bool *flag=new bool[num+1];
	int* queue=new int[num+1];
	for (int i=1;i<=num;++i){
		flag[i]=true;
	}
	for (int i=1;i<=num;++i){
		cin>>p>>q;
		node[i].left=p; node[i].right=q;
		flag[p]=false;	flag[q]=false;
	}
	for (i=1;i<=num;++i){
		if (flag[i]) break;
	}
	int head=0,rear=0;
	bool mark=false;
	queue[head]=i;
	while (true){
		if (mark && (node[queue[head]].left || node[queue[head]].right)){cout<<'N'<<endl; return 0;}
		if (node[queue[head]].left && node[queue[head]].right) {
			queue[++rear]=node[queue[head]].left;
			queue[++rear]=node[queue[head]].right;
			head+=1;
		}
		else{
			if (node[queue[head]].right) {cout<<'N'<<endl; return 0;}
			if (node[queue[head]].left) { queue[++rear]=node[queue[head]].left; head+=1;}
			head+=1;
			mark=true;
		}
		if (head==rear) {cout<<'Y'<<endl; return 0;}
	}
	return 0;
}