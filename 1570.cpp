#include <iostream>
#include <cstdio>
using namespace std;
void quicksort(int *(&a),int *(&pos),int head,int rear){
	if (head>=rear) return;

	int pivot=a[head],pp=pos[head];
	int left=head+1,right=rear;
	int temp,tmp;

	while (left<=right){
		while (a[right]>pivot && left<=right) right--;
		while (a[left]<pivot && left<=right) left++;
		if (left>=right) break;

		temp=a[left]; a[left]=a[right]; a[right]=temp;
		tmp=pos[left]; pos[left]=pos[right]; pos[right]=tmp;
		left++; right--;
	}
	a[head]=a[right]; pos[head]=pos[right];
	a[right]=pivot;   pos[right]=pp;

	quicksort(a,pos,head,right-1);
	quicksort(a,pos,left,rear);
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int i,j,n,t;
	scanf("%d %d",&n,&t);
	int *num=new int[t],*x=new int[n],*y=new int[t],*pos=new int[t];
	for (i=0;i<n;++i){
		scanf("%d",&x[i]);
	}
	for (i=0;i<t;++i){
		scanf("%d",&y[i]);
		pos[i]=i;
		num[i]=n;
	}
	quicksort(y,pos,0,t-1);
	//cout<<"done"<<endl;
	i=0;j=0;
	while (i<n && j<t){
		while (y[j]<x[i] && j<t) {num[pos[j]]=i; j++;}
		if (j==t) break;
		while (x[i]<=y[j] && i<n) i++;
		
	}
	for (i=0;i<t;++i){
		printf("%d\n",n-num[i] );
	}
	return 0;
}
