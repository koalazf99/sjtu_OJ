#include <iostream>
using namespace std;
 int main(){
 	int v,n,tw,tc,total,num,i,j;
 	int w[1000]={0},c[1000]={0};
 	cin>>v>>n;
 	for (i=0;i<n;++i){
 		cin>>c[i]>>w[i];
 	}

 	for (i=0;i<n-2;++i)
 		for (j=i+1;j<n-1;++j)
 			if ((w[i]/c[i])<(w[j]/c[j])) {
 				tw=w[i]; w[i]=w[j]; w[j]=tw;
 				tc=c[i]; c[i]=c[j]; c[j]=tc;
 			}

 	total=0;
 	for (i=0;i<n;++i){
 		num=v / c[i];
 		total+=num*w[i];
 		v-=num*c[i];
 	}
 	cout<<total<<endl;
 	return 0;
 }