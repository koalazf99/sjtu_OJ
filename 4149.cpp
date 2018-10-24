#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};

int main(){
	int n,m,k,i,num;
	node *head,*rear,*pos;
	cin>>n>>m>>k;
	m=m%n;
	head=new node;rear=head;
	for (i=1;i<=n-1;++i){
		rear->data=i;
		node*temp=new node;
		rear->next=temp;
		rear=temp;
	}
	rear->data=n;
	rear->next=head;
	i=0;
	pos=head;
	while (i<k){
		i+=1;
		if (m==1) {m=n+1;}
		for (int j=0;j<m-2;++j){
			pos=pos->next;
		}
		num=pos->next->data;
		node* temp=pos->next;
		pos->next=temp->next;
		delete temp;
		pos=pos->next;
	}

	cout<<num<<endl;

}