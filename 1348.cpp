#include <iostream>
#include <iomanip>
using namespace std;
void quicksort(long long *(&a), int head, int rear){
	if (head>=rear) return;
 
	long long pivot=a[head];
	int left=head+1,right=rear;
	long long temp;
 
	while (left<=right){
		while (a[right]>pivot && left<=right) right--;
		while (a[left]<pivot && left<right) left++;
		if (left>=right) break;
 
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
 	long long* a=new long long[1000001],* b=new long long[1000001],*min=new long long[100000];
 	long long n,m,p,q,ha=0,ra=0,hb=0,rb=0,atime=0,btime=0;
 	cin>>n;
 	for (int i=0;i<n;++i){
 		cin>>min[i];
 	}
 	cin>>m;
 	for (int i=0;i<m;++i){
 		cin>>p>>q;
 		if (p==1) a[ra++]=q;
 		else b[rb++]=q;
 	}
 	quicksort(a,0,ra-1);
 	quicksort(b,0,rb-1);
 	m=0;
 	for (int i=0;i<n-1;++i){
 		while (ha<ra && hb<rb && a[ha]<=m && b[hb]<=m){
 			atime+=m-a[ha];ha++;
 			btime+=m-b[hb];hb++;
 		}
 		m+=min[i];
 	}
 	while (ha<ra) {atime+=m-a[ha];ha++;}
 	while (hb<rb) {btime+=m-b[hb];hb++;}
 	cout<<setiosflags(ios::fixed)<<setprecision(2)<<1.0*atime/(ra>0?ra:1)<<' '
 		<<setiosflags(ios::fixed)<<setprecision(2)<<1.0*btime/(rb>0?rb:1)<<endl;
 	return 0;
 }