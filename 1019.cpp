#include <iostream>
#include <cstring>
using namespace std;

void ppair(char *s){
	int mark,i;
	mark=0;
	i=0;

	for (i=0;i<strlen(s);i++){
		if (s[i]=='(') {mark++;}
		if (s[i]==')') {mark--;}
		if (mark<0){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<(mark==0?"YES":"NO")<<endl;
	return;
}

int main(){
	int i,n;
	cin>>n;

	char **s=new char*[n];
	for (i=0;i<n;++i){
		s[i]=new char[100];
		cin>>s[i];
	}

	for (i=0;i<n;++i){
		ppair(s[i]);
		delete []s[i];
	}
	return 0;

}