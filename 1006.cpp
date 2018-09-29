#include <iostream>
using namespace std;

int main(){
	int n,i,flag,maxx=-2147483647;
	int *a=new int [1000000];
	int *dp=new int [1000000];
	cin>>n;
	for (i=0;i<n;++i){
		cin>>a[i];
		dp[i]=0;
	}
	if (a[0]<0){
		flag=0; dp[0]=0;
	}
	else{
		flag=1; dp[0]=a[0];
	}
	for (i=1;i<n;++i){
		if (a[i]+dp[i-1]<0){
			dp[i]=0;
			flag=0;
		}
		if (a[i]+dp[i-1]>=0){
			dp[i]=dp[i-1]+a[i];
			flag++;
		}
		if (flag>1){
			maxx=max(maxx,dp[i]);
		}
		maxx=max(maxx,a[i]+a[i-1]);
	}
	if (maxx>0){
		cout<<maxx<<endl;
	}
	else 
		cout<<"Game Over"<<endl;
	return 0;
}