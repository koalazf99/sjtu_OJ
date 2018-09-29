#include <iostream>
using namespace std;

void quicksort(int **(&a),int head,int rear){
	if (head>=rear) return;

	int pivot=a[head][0],ppivot=a[head][1];
	int left=head+1,right=rear;
	int temp;

	while (left<=right){
		while (a[right][0]>pivot && left<=right) right--;
		while (a[left][0]<pivot && left<right) left++;
		if (left>=right) break;
		temp=a[left][0]; a[left][0]=a[right][0]; a[right][0]=temp;
		temp=a[left][1]; a[left][1]=a[right][1]; a[right][1]=temp;
		left++;right--;
	}
	a[head][0]=a[right][0];
	a[head][1]=a[right][1];
	a[right][0]=pivot;
	a[right][1]=ppivot;


	quicksort(a,head,right-1);
	quicksort(a,left,rear);
	
}

int main(){
	//快排+递推
	int n,i;
	cin>>n;

	int **a=new int*[n];
	for (i=0;i<n;++i){
		a[i]=new int[2];
	}
	for (i=0;i<n;++i){
		cin>>a[i][0]>>a[i][1];
	}
	quicksort(a,0,n-1);

	int rear=a[0][1],total=a[0][1]-a[0][0];
	for (i=1;i<n;++i){
		if (a[i][0]>=rear){
			total+=(a[i][1]-a[i][0]);
			rear=(a[i][1]>rear?a[i][1]:rear);
		}
		else {
			if (a[i][1]>rear){
				total+=(a[i][1]-rear);
				rear=a[i][1];
			}
		}
	}
	cout<<total<<endl;
	return 0;
}