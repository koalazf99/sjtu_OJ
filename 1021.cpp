#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int i,j,index,row,col,n;
	int a[150][150]={0};
	cin>>n;
	index=0;
	row=0;
	col=0;
	if (n==1){
		cout<<setw(6)<<1<<endl;
		return 0;
	}
	while (true){
		for (j=col;j<n-1-row;++j)
			a[row][j]=++index;
		for (i=row;i<n-1-row;++i)
			a[i][j]=++index;
		for (j=j;j>col;--j)
			a[i][j]=++index;
		for (i=i;i>row;--i)
			a[i][j]=++index;
		row++; col++;
		if (index-n*n>=-1) break;
	}
	if (index<n*n) a[row][col]=++index;
	for (i=0;i<n;++i){
		for (j=0;j<n;++j)
			cout<<setw(6)<<a[i][j];
		cout<<endl;
	}

	return 0;
}