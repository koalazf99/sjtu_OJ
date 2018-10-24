#include <iostream>
#include "string.h"
using namespace std;
int len(char s[]){
	int i=0;
	while (s[i]!='\0') i++;
	return i;
}
int  main(){
	char *word;
	word=new char[260];
	char c;
	bool flag;
	int num,length,total_pos=0,count=0,fst=-1;
	int pos;
	cin.getline(word,260);
	length=(len(word));
	//cout<<length<<endl;

	cin>>num;
	cin.get(c);
	c=' ';
	while (num--){
		pos=0; flag=true;
		while (c==' ') cin.get(c);
		while (true){
			flag=flag && (pos<length) &&
				(c-word[pos]==0 || word[pos]-c==32 || c-word[pos]==32);
				pos++;
				total_pos++;
				cin.get(c);
				if (c==' ' || c=='\n') break;
		}
		if (flag){
			count++;
			if (fst==-1) fst=total_pos-pos;
		}
	}
	if (count) cout<<count<<' '<<fst<<endl;
	else cout<<-1<<endl;
	return 0;
}