#include <iostream>
using namespace std;


int main(){
	int l;
	cin>>l;
	int i,j,time=0;
	int a[100][100]={0};
	int temp[100][100]={0};
	for (i=0;i<l;++i)
		for (j=0;j<l;++j){
			cin>>a[i][j];
			temp[i][j]=a[i][j];
		}

	bool flag;

	while (true){
		flag=true;
		for (i=0;i<l;++i)
			for (j=0;j<l;++j){
				if (a[i][j]==0) flag=false;
				if (a[i][j]==1) {
					if (i-1>=0 && a[i-1][j]==0) temp[i-1][j]=1;
					if (i+1<l && a[i+1][j]==0) temp[i+1][j]=1;
					if (j-1>=0 && a[i][j-1]==0) temp[i][j-1]=1;
					if (j+1<l && a[i][j+1]==0) temp[i][j+1]=1;
				}
			}
		if (flag) break;
		for (i=0;i<l;++i)
			for (j=0;j<l;++j)
				a[i][j]=temp[i][j];
		time++;
		
	}

	cout<<time<<endl;
	return 0;
}