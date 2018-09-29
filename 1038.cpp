#include <iostream>
using namespace std;

int main(){
	int i,flag,m,time;
	long long k[10001]={0};
	bool a[10001];
	cin>>m;
	for (i=0;i<m-1;++i){
		cin>>k[i];
		k[i]=(k[i]%(m-i)==0?(m-i):k[i]%(m-i));
		a[i+1]=true;
	}
	a[m]=true;
	flag=0;
	for (i=0;i<m-1;++i){
		time=0;
		while (time<k[i]){
			flag++;
			if (flag==(m+1)){
				flag=1;
			}
			while (a[flag]==false){
				flag+=1;
				if (flag==(m+1)){
					flag=1;
				}
			}
			time++;
		}
		a[flag]=false;
	}
	while (a[flag]==false){
		flag+=1;
		if (flag==(m+1)){
			flag=1;
		}
	}
	cout<<flag<<endl;
	return 0;
}