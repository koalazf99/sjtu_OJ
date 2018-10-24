#include <iostream>
#include <cstring>
using namespace std;
char *s=new char[102];
int *pos=new int[102];
int pt=0;


int main(int argc, char const *argv[])
{
	char *str=new char[102];

	cin.getline(str,102);
	for (int i=0;i<(int)strlen(str);++i){
		if (str[i]=='(') {s[pt]='$'; pos[pt]=i; pt++;}
		else if (str[i]==')') {
			if (s[pt-1]=='$') pt-=1;
			else {s[pt]='?'; pos[pt]=i; pt++;}
		}
		continue;
	}
	int p=0;
	cout<<str<<endl;
	for (int i=0;i<(int)strlen(str);++i){
		if (i==pos[p] && p<pt) cout<<s[p++];
		else cout<<' ';
	}
	return 0;
}