#include <iostream>
#include <cstdio>
using namespace std;


struct node
{
	int num;
	node* next;	
};

node *head;
node *pos;
int count=1;

void circle(int k){
	while (--k>0){
		pos=pos->next;
	}
}

void Add(int m){
	count+=m;
	node* temp=new node;
	temp->num=m;
	temp->next=pos->next;
	pos->next=temp;
	pos=pos->next;
}

void del(){
	node* Del_pos=pos->next;
	count-=Del_pos->num;
	pos->next=(pos->next)->next;
	//cout<<"del"<<Del_pos->num<<endl;
	delete Del_pos;
}
int main(){
	head=new node;
	head->num=1;
	pos=head;
	int k,order,n,m,ookk;
	scanf("%d %d",&n,&m);
	for (int i=2;i<=n;++i){
		node* temp=new node;
		temp->num=i;
		pos->next=temp;
		pos=temp;
		count+=i;
	}
	//cout<<head->num<<endl;
	pos->next=head;
	pos=head;
	for (int i=0;i<m;++i){
		cin>>order>>k;
		k=k%n;
		if (k>1) {
			circle(k-1);
		}
		else{
			if(k==1) circle(n);
			else circle(n-1);
		}
		if (order){ 
			n+=1;
			pos=pos->next;
			//cout<<"adding after "<<pos->num<<endl;
			scanf("%d",&ookk);
			Add(ookk);	
		}
		else{
			n-=1;
			//cout<<"delete"<<pos->next->num<<endl;
			del();
			pos=pos->next;
			//cout<<pos->num<<endl;
		}
	}
	printf("%d",count);
	return 0;
}