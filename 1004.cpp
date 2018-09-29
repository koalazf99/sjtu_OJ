#include <iostream>
using namespace std;

int main(){
	long long  m,t,u,f,d,i;

	long long  total=0,temp_time=0;
	char road;

	cin>>m>>t>>u>>f>>d;

	for (i=0;i<t;++i){
		cin>>road;
		if (road=='u'){
			temp_time=temp_time+(u+d);
			if ((temp_time)<=m){
				total++;
			}
		}
		if (road=='f'){
			temp_time=temp_time+2*f;
			if (temp_time<=m){
				total++;
			}
		}
		if (road=='d'){
			temp_time=temp_time+(u+d);
			if ((temp_time)<=m){
				total++;
			}
		}
	}

	cout<<total<<endl;
	return 0;
}