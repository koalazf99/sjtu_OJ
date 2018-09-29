#include <iostream>
using namespace std;

template <class elemtype>
class reqlist{
	
private:
	int length;
	elemtype *data;
public:
	friend istream &operator>>(istream &ob, reqlist<elemtype> &a){
		int i;
		for (i=0;i<a.length;++i) ob>>a.data[i];
		return ob;
	}
	friend ostream &operator<<(ostream &ob, reqlist<elemtype> &a){
		int i;
		for (i=0;i<a.length;++i) ob<<a.data[i]<<' ';
		ob<<endl;
		return ob;
	}
	reqlist(int initsize=0){
		data=new elemtype[initsize];
		length=initsize;
	}
	reqlist(reqlist<elemtype> &a){
		data=new elemtype[a.length];
		length=a.length;
		for (int i=0;i<length;++i)
			data[i]=a.data[i];
	}
	~reqlist(){}
	reqlist operator+ (reqlist<elemtype>& a){
		elemtype *tmp=new elemtype[a.length+length];
		int i;
		for (i=0;i<length;++i)
			tmp[i]=data[i];
		for (i=0;i<a.length;++i)
			tmp[i+length]=a.data[i];
		data=tmp;
		length+=a.length;
		reqlist<elemtype> temp(*this);
		return  temp;
	}

};


int main(){
	char Type[10];
	int n,m;
	cin>>Type;
	cin>>n>>m;
	if (Type[0]=='i') {reqlist<int> a(n); reqlist<int> b(m);
		cin>>a;
		cin>>b;
		a=a+b;
		cout<<a;}
	if (Type[0]=='c') {reqlist<char>a(n); reqlist<char>b(m);
	cin>>a;
	cin>>b;
	a=a+b;
	cout<<a;}
	if (Type[0]=='d') {reqlist<double>a(n); reqlist<double>b(m);
	cin>>a;
	cin>>b;
	a=a+b;
	cout<<a;}

	return 0;
}