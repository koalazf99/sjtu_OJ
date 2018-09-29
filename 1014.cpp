//需要高精度加法、乘法


#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int sum[100002]={0};
	char ca[100000];	
	char cb[100000];
	int la,lb,det,flag;

	cin.getline(ca,100000);
	cin.getline(cb,100000);
	la=strlen(ca);
	lb=strlen(cb);
	det=0;
	flag=0;
	while (la>0 || lb>0){
		if (la<=0) sum[flag]=cb[lb-1]-int('0')+det;
		else{ 
			if (lb<=0) sum[flag]=ca[la-1]-int('0')+det;
			else 	   sum[flag]=ca[la-1]+cb[lb-1]-2*int('0')+det;
		}
		det=sum[flag]/10;
		sum[flag]%=10;
		la--;lb--;flag++;
	}
	if (det!=0) cout<<det;
	for (int i=--flag;i>=0;--i) cout<<sum[i];
	cout<<endl;
	return 0;
}