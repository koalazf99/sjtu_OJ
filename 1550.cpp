#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n,i,start,e,water=0,max=0,h,num;
	char c;
	scanf("%d\n",&n);
	int *a=new int[n];
	scanf("[%d,",&a[0]);
	for (i=1;i<n;++i){
		scanf("%d,",&a[i]);
		if (a[i]>max) max=a[i];
	}
	scanf("%c",&c);
	for (h=0;h<max;++h){
		start=0; while (a[start]==0) start++;
		e=n-1;	while (a[e]==0) e--;
		for (i=start;i<=e;++i){
			if (a[i]==0) water++;
			else a[i]-=1;
		}
	}
	printf("%d\n",water);
	return 0;
}