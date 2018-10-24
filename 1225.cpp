#include <iostream>
using namespace std;

void quicksort(int *(&a), int head, int rear){
	if (head>=rear) return;

	int left=head+1,right=rear;
	int pivot=a[head];
	int temp;

	while(left<=right){
		while (a[right]>pivot && left<=right) right--;
		while (a[left]<pivot  && left<=right) left++;
		
		if (left>right) break;
		temp=a[left]; a[left]=a[right]; a[right]=temp;
		left++; right--;
	}
	a[head]=a[right];
	a[right]=pivot;

	quicksort(a,head,right-1);
	quicksort(a,left,rear);
}

int main(int argc, char const *argv[])
{
	int n,num,flag;
	cin>>n;
	int *a=new int[n];
	for (int i=0;i<n;++i){
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	flag=a[0];
	num=1;
	for (int i=1;i<n;++i){
		if (a[i]!=flag) {num+=1; flag=a[i];}
	}
	cout<<num<<endl;
	return 0;
}