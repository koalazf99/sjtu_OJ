#include <iostream>
using namespace std;

int main(){
	int n,b;
	int *left =new int [200000];
	int *right =new int [200000];
	int a[100000];
	cin>>n>>b;
	int total=1,score,mid,i;
	for (i=0;i<n;++i){
		cin>>a[i];
		if (a[i]==b) mid=i;
	}
	for (i=0;i<200000;++i){left[i]=0;right[i]=0;}
	score=100000;
	for (i=mid-1;i>=0;--i){
		if (a[i]<a[mid]) score--;
		if (a[i]>a[mid]) score++;
		left[score]++;			
	}
	score=100000;
	for (i=mid+1;i<n;++i){
		if (a[i]<a[mid]) score--;
		if (a[i]>a[mid]) score++;
		right[score]++;
	}
	for (i=50000;i<150000;++i){
		total+=left[i]*right[200000-i];
	}
	total+=left[100000]+right[100000];
	cout<<total<<endl;
	return 0;
}