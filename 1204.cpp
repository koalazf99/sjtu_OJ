#include <iostream>
#include <cstring>
using namespace std;
char** ans=new char*[200000];
char* error=new char[7];
void order_list(char** (&tt),int n1, int n2 ,int max_length,int &count){
	if (n1>max_length || n2>max_length || n1<1 || n2<1 || n2<n1){
		ans[count]=new char[7];
		ans[count]=error;
		count++;
		return;
	}
	int i,j;
	for (i=n1;i<=n2;++i){
		ans[count]=new char[strlen(tt[i])+1];
		for (j=0;j<int(strlen(tt[i]));++j){
			ans[count][j]=tt[i][j];
		}
		ans[count][j]='\0';
		count++;
	}
}

void order_insert(char** (&tt),int i,int j,int max_length,char* str,int *ll,int &count){
	if (i>max_length || i<1 || ll[i]+1<j || ll[i]+strlen(str)>2000){
		ans[count]=new char[7];
		ans[count]=error;
		count++;
		return;
	}
	int d=strlen(str)-1;
	int index;
	for (index=ll[i]+strlen(str)-1;index>ll[i]+1;index--){
		tt[i][index]=tt[i][index-d];
	}
	ll[i]+=d;
	for (index=j-1;index<j+d-1;++index){
		tt[i][index]=str[index-j+2];
	}
}

void order_del(char** (&tt),int i,int j,int num,int *ll,int &count){
	if (i<1 || j>ll[i] || j+num-1>ll[i] || j<0){
		ans[count]=new char[7];
		ans[count]=error;
		count++;
		return;
	}
	
	int index=j-1;
	for (index=index;index<ll[i]-num;++index){
		tt[i][index]=tt[i][index+num];
		tt[i][index+num]=NULL;
	}
	tt[i][index]='\0';
	ll[i]-=num;
}

int main(){
	char **tt=new char*[101];
	int ll[100]={0};
	int i,n1,n2,j,num;
	for (i=0;i<100;++i)
		tt[i]=new char[2001];
	int length=0;

	char *order=new char[7];
	char *str=new char[2000];
	error[0]='E'; error[1]='r'; error[2]='r'; error[3]='o'; error[4]='r'; error[5]='!'; error[6]='\0';
	while(true){
		cin.getline(tt[++length],2001);
		if (strlen(tt[length])==6 && tt[length][0]=='*') {length--; break;}
		ll[length]=strlen(tt[length]);
	}
	int count=0;
	while (true){
		cin>>order;
		if (strcmp(order,"quit")==0) {
			break;
		}
		if (strcmp(order,"list")==0) {
			cin>>n1>>n2;
			order_list(tt,n1,n2,length,count);
			continue;
		}
		if (strcmp(order,"ins")==0){
			cin>>i>>j;
			cin.getline(str,2000);
			order_insert(tt,i,j,length,str,ll,count);
			continue;
		}
		if (strcmp(order,"del")==0){
			cin>>i>>j>>num;
			order_del(tt,i,j,num,ll,count);
			continue;
		}
	}
	for (i=0;i<count;++i){
		cout<<ans[i]<<endl;
	}
	
	for (i=1;i<=length;++i){
		cout<<tt[i]<<endl;
	}
	return 0;
}