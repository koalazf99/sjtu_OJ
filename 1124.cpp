#include <iostream>
using namespace std;

int main(){
	long long  n,t,z,tt,zz;
	cin>>n;
	cin>>t>>z;
	temp_t=t;
	temp_z=z;
	for (int i=0;i<n;++i)
		cin>>tt>>zz;
		t+=tt;
		z+=zz*tt;
	if (t>0 && z>70){
		cout<<t*z<<endl;
	}
	else{
		cout<<"death"<<endl;
	}
	return 0;
}