#include <iostream>
using namespace std;
void cal(int &total,int num){
	while (num!=0){
		total+=num %2;
		num/=2;
	}
}

int main(){
	int i,n,num,total=0;
	cin>>n;
	for (i=0;i<n;++i){
		cin>>num;
		cal(total,num);
	}
	cout<<total<<endl;
	return 0;
}