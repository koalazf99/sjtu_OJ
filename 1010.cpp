#include <iostream>
using namespace std;

int main(){
	int save,rest,pre,i;

	save=0;
	rest=0;
	bool flag=true;
	int ff=0;
	for (i=1;i<=12;++i){
		cin>>pre;
		rest+=300;
		if (rest-pre<0){
			flag=false;
			break;
		}
		if (rest-pre>=0 && rest-pre<100){
			rest-=pre;
		}
		if (rest-pre>=100){
			save+=((rest-pre)/100)*100;
			rest-=((rest-pre)/100)*100;
			rest-=pre;
		}
	}

	cout<<(flag ?(save*1.2+rest):(-1)*ff)<<endl;
	return 0;
}