#include <iostream>
using namespace std;
void add((&old)[1000],mmid[]){
	for 
}

int main(){
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	int New[1000]={0},
		Mid[1000]={0},
		MMid[1000]={0},
		Old[1000]={0},
		OOld[1000]={0};
	New[0]=1;
	for (int i=0;i<n;++i){
		Old+=MMid;
		Mid=New;
		New=a*New+MMid*b+OOld*c;

		OOld=Old; MMid=Mid;
	}

	cout<<(Old+Mid+New)<<endl;

	return 0;
}