#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char code[100000];
	char if_pointer='0';
	int be_pointer=0;
	while (cin>>code){
		if (strcmp(code,"begin")==0){
			be_pointer+=1;
			continue;
		}

		else if (strcmp(code,"end")==0){
			be_pointer-=1;
			if (be_pointer<0){
				cout<<"Error!"<<endl;
				return 0;
			}
			continue;
		}

		else if (strcmp(code,"if")==0){
			if_pointer='i';
			continue;
		}

		else if (strcmp(code,"then")==0){
			if (if_pointer=='i') if_pointer='t';
			else {
				cout<<"Error!"<<endl;
				return 0;
			}
		}

		else if (strcmp(code,"else")==0){
			if (if_pointer=='t') if_pointer='e';
			else{
				cout<<"Error!"<<endl;
				return 0;
			}
		}

		else continue;

	}

	if (if_pointer!='i' && be_pointer==0)
		cout<<"Match!"<<endl;
	else cout<<"Error!"<<endl;
	return 0;
}