#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d %d",&n,&k);
	int *a=new int[n];
	int rp=0,min_rp=0;

	// enqueue
	for (int i=0;i<k;++i){
		scanf("%d",&a[i]);
		rp=(rp>a[i]?rp:a[i]);
	}

	// enqueue and compare
	min_rp=rp;
	for (int i=k;i<n;++i){
		scanf("%d",&a[i]);
		if (rp==a[i-k]){
			rp=0;
			for (int j=i-k+1;j<i;++j)
				if (a[j]>rp) rp=a[j];
		}
		if (a[i]>rp) rp=a[i];
		if (rp<min_rp) min_rp=rp;
	}
	// compare
	for (int i=n;i<n+k;++i){
		if (rp==a[i-k]){
			rp=0;
			for (int j=i-k+1;j<i;++j){
				if (a[j%n]>rp) rp=a[j%n];
			}
		}
		if (a[i-n]>rp) rp=a[i-n];
		if (rp<min_rp) min_rp=rp;
	}
	printf("%d\n", min_rp);
	return 0;
}