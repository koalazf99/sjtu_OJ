#include <iostream>
using namespace std;

int main(){
	int i,n;
	int temp,num=0;
	cin>>n;
	int rear=1000000000;
	int ** ex=new int*[n];
	int *original=new int[n];
	int *length=new int [n];
	int j,index=-1;
	for (i=0;i<n;++i){
		cin>>temp;
		if (temp<=rear){
			num++;
			index++;
			ex[index]=new int[n]; ex[index][0]=temp; length[index]=0; 
			
			rear=temp;
			original[i]=temp;
			continue;
		}
		rear=temp;
		length[index]+=1;
		ex[index][length[index]]=temp;
		original[i]=temp;
	}


	cout<<num<<endl;
	cout<<"解释: {";
	for (i=0;i<n-1;++i){
		cout<<original[i]<<','<<' ';
	}
	cout<<original[i]<<'}'<<'=';

	for (i=0;i<index;++i){
		cout<<'{';
		for (j=0;j<length[i];++j){
			cout<<ex[i][j]<<','<<' ';
		}
		cout<<ex[i][j]<<'}'<<" + ";
	}

	cout<<'{';
	for (j=0;j<length[i];++j){
		cout<<ex[i][j]<<','<<' ';
	}
	cout<<ex[i][j]<<'}'<<endl;

	return 0;
}