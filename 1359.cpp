#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int i,encode=0;
	char *in_string=new char[1002];
	cin.getline(in_string,1000);
	for (i=0;i<strlen(in_string);++i){
		if (in_string[i]==' '){
			encode+=0;
		}
		else if (in_string[i]>=65 && in_string[i]<=90){
			encode+=(in_string[i]-65+1)*(i+1);
		}
		else{
			encode+=(in_string[i]-70)*(i+1);
		}

	}

	cout<<encode<<endl;
	return 0;
}