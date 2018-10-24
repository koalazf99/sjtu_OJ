#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
long long comp=0;
void search(int num,node* (&head)){
	node *pos=head->next;
	node *tmp;
	if (num==pos->data) {comp+=1; return;}
	comp+=1;
	while (pos->next!=NULL){
		if ((pos->next)!=NULL &&num==(pos->next)->data){
			comp+=1;
			tmp=pos->next;
			pos->next=tmp->next;
			tmp->next=head->next;
			head->next=tmp;
			return;
		}
		pos=pos->next; comp+=1;
	}
	
	//cout<<comp<<endl;
	return;
}
int main(int argc, char const *argv[])
{
	int n,m,num;
	node *head,*rear;
	cin>>n;
	head=new node;rear=head;
	for (int i=0;i<n;++i){
		cin>>num;
		node* temp=new node;
		temp->data=num;
		rear->next=temp;
		rear=temp;
	}
	rear->next=NULL;
	cin>>m;
	for (int i=0;i<m;++i){
		cin>>num;
		search(num,head);
	}
	cout<<comp<<endl;
	return 0;
}