#include <iostream>
using namespace std;
#include <iomanip>
int main(int argc, char const *argv[])
{
	int *a=new int[20000],*b=new int[20000];
	int ha=0,ra=0,hb=0,rb=0,atime=0,btime=0;
	int n,p,q,min,a_num;

	cin>>n;
	for (int i=0;i<n;++i){
		cin>>p>>q;
		if (p) b[rb++]=q;
		else a[ra++]=q;
	}
	a[ra]=2000000;b[rb]=2000000;
	//cout<<ra<<rb;
	min=0;
	while (ha<ra || hb<rb){
		for (int i=0;i<2;++i){
			a_num=0;
			while (a_num<4 && ha<ra){
				if (a[ha]<=min) {atime+=min-a[ha]; ha++;}
				else break;
				a_num+=1;
			}
			while (5-a_num>0 && hb<rb){
				if (b[hb]<=min) {btime+=min-b[hb]; hb++;}
				else break;
				a_num+=1;
			}
		}
		min+=10;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<(1.0*atime/(ra>0?ra:1))<<' '
		<<setiosflags(ios::fixed)<<setprecision(3)<<(1.0*btime/(rb>0?rb:1))<<endl;
	return 0;
}