#include <iostream>

using namespace std;
int *father=new int[150001];
int *rankk=new int[150001];

int find_father(int sun){
	if (sun!=father[sun]){
		father[sun]=find_father(father[sun]);
	}
	return father[sun];
}


void merge(int x,int y){
	x=find_father(x);
	y=find_father(y);
	if (x==y) return;
	if (rankk[x]>rankk[y]){
		father[y]=x;
	}
	else {
		if (rankk[x]==rankk[y]) rankk[y]++;
		father[x]=y;
	}
}

int main(){
	long long n,m,i,x,y,total=0;
	int *num=new int[150001];
	cin>>n>>m;
	for (i=0;i<n;++i){
		father[i]=i;
		rankk[i]=0;
		num[i]=0;
	}
	for (i=0;i<m;++i){
		cin>>x>>y;
		merge(x,y);
	}
	for (i=1;i<=n;++i){
			num[father[i]]+=1;
	}
	
	for (i=0;i<=n;++i){
		total+=num[i]*(num[i]-1)/2;
	}
	if (total==m) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}




