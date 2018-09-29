#include <iostream>
using namespace std;

int main(){
	int l,w,ll,ww;
	int a[1000][1000];
	int b[1000];
	int i,j,temp,mmax;
	// 输入
	cin>>l>>w;
	for (i=0;i<l;++i)
		for (j=0;j<w;++j)
			cin>>a[i][j];
	// 初始列之和
	for (j=0;j<w;++j){
		for (i=0;i<l-1;++i)
			b[j]+=a[i][j];
	}
	mmax=0;

	i=0;
	while (true){
		temp=0;
		for (j=0;j<ww;++j) 
			temp+=b[j];
		for (j=1;j<=w-ww;++j) 
			temp=max(temp,temp-b[j-1]+b[j+ww-1]);
		mmax=max(temp,mmax);

		i++;
		if (i==l-ll) 
			break;
		for (j=0;j<w;++j)
			b[j]=b[j]-a[i-1][j]+a[i+ww-2][j];

	}
	cout<<mmax<<endl;
	return 0;

}