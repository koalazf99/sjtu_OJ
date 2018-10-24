#include <iostream>
#include <cstring>
using namespace std;



struct tel_record{
	char tel[10];
	int length;
};
tel_record* tel_book=new tel_record[100000];
int record_num=0;
char* tel_num=new char[10];

void quick_sort(){
	int i,j;
	for (i=0;i<record_num;++i){
		for (j=i;j<record_num;++j){
			if (tel_book[j].tel>tel_book[i].tel){
				tel_record temp;
				temp=tel_book[j];
				tel_book[j]=tel_book[i];
				tel_book[i]=temp;

			}
		}
	}
}
void quick_sort1(int head,int rear){
	if (head>=rear) return;

	tel_record pivot=tel_book[head];
	int left=head+1,right=rear;
	tel_record temp;

	while (left<=right){
		while (tel_book[right].tel>pivot.tel && left<=right) right--;
		while (tel_book[left].tel<pivot.tel && left<right) left++;
		if (left>=right) break;

		temp=tel_book[left]; tel_book[left]=tel_book[right]; tel_book[right]=temp;
		left++; right--;
	}
	tel_book[head]=tel_book[right];
	tel_book[right]=pivot;

	quick_sort1(head,right-1);
	quick_sort1(left,rear);

}

void fit(){
	int i;
	bool flag=false;
	for (int i=0;i<record_num;++i){
		if (strcmp(tel_book[i].tel,tel_num)==0){
			tel_book[i].length+=1;
			flag=true;
			break;
		}
	}
	if (!flag){
		for (i=0;i<8;++i)
			tel_book[record_num].tel[i]=tel_num[i];
		tel_book[record_num].tel[i]='\0';

		tel_book[record_num].length=1;
		record_num++;
	}
}

void transfer(char number[]){
	int index,i;
	index=0;
	for (i=0;i<int(strlen(number));++i){
		if (number[i]=='-'){continue;}
		if (number[i]>='0' && number[i]<='9'){
			tel_num[index]=number[i];
			index++;
		}
		if (number[i]>='A' && number[i]<='Z'){
			if (number[i]<='C'){tel_num[index]='2';index++;}
			else if (number[i]<='F'){tel_num[index]='3';index++;}
			else if (number[i]<='I'){tel_num[index]='4';index++;}
			else if (number[i]<='L'){tel_num[index]='5';index++;}
			else if (number[i]<='O'){tel_num[index]='6';index++;}
			else if (number[i]<='S'){tel_num[index]='7';index++;}
			else if (number[i]<='V'){tel_num[index]='8';index++;}
			else if (number[i]<='Y'){tel_num[index]='9';index++;}
		}
		if (index==3){
			tel_num[index]='-';
			index++;
		}
	}
	tel_num[index]='\0';
}

int main(){
	int n,i;
	char* number=new char[10];
	cin>>n;
	for (i=0;i<n;++i){
		cin>>number;
		transfer(number);
		fit();
	}
	quick_sort();	
	for (i=0;i<record_num;++i){
		if (tel_book[i].length>1){
			cout<<tel_book[i].tel<<' '<<tel_book[i].length<<endl;
		}
	}
	return 0;
}