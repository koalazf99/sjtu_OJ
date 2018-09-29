#include<iostream>
#include<cstring>
using namespace std;

int num_1,num_2,num_3,length=0;
char text[110][2010],temp_space,OrderList[110];
//using global



void list(int num_1,int num_2){
	int i;
	for(i=(num_1-1);i<=(num_2-1);i++){
		cout<<text[i]<<endl;
	}
}

void del(int num_1,int num_2,int num_3){
	int i;
	int distance=strlen(text[num_1-1]);
	for(i=0;i<((int)strlen(text[num_1-1])-num_3-num_2+1);i++){
		text[num_1-1][i+num_2-1]=text[num_1-1][i+num_3+num_2-1];
	}

	for(i=0;i<num_3;i++){
		text[num_1-1][distance-1-i]=NULL;		//in case runtime error
	}
}

void ins(int num_1,int num_2,char *insert_string){
	int i;
	for(i=(strlen(text[num_1-1])-1);i>=(num_2-1);i--){
		text[num_1-1][i+strlen(insert_string)]=text[num_1-1][i];
	}
	for(i=0;i<(int)strlen(insert_string);i++){
		text[num_1-1][i+num_2-1]=insert_string[i];
	}
}


void quit(){
	int i;
	for(i=0;i<length;i++){cout<<text[i]<<endl;}
}

int main(){
	int i;
	char insert_string[100];
	//read in text
	for(i=0;i<110;i++){
		cin.getline(text[i],2000);
		length++;
		if(strcmp(text[i],"******")==0){
			break;
		}
	}
	length--;

	// main part
	while(true){

		cin>>OrderList; //input order


		if(strcmp(OrderList,"list")==0){

			cin>>num_1>>num_2;
			if(num_1>num_2||num_1<1||num_2<1||num_2>length||num_1>length){

				cout<<"Error!"<<endl;
			}
			else {
				list(num_1,num_2);
			}

			continue;
		}	


		else if(strcmp(OrderList,"del")==0){

			cin>>num_1>>num_2>>num_3;

			if(num_1<1 || num_2<1 || num_1>length || num_2>(int)strlen(text[num_1-1])||(num_2+num_3)>((int)strlen(text[num_1-1])+1)){
				cout<<"Error!"<<endl;
			}
			else{
				del(num_1,num_2,num_3);
			}
			continue;
		}		

		else if(strcmp(OrderList,"ins")==0){

			cin>>num_1>>num_2;
			temp_space=cin.get();
			cin.getline(insert_string,100);

			if(num_1<1 || num_2<1 || num_1>length || (num_2>((int)strlen(text[num_1-1])+1))){
				cout<<"Error!"<<endl;
			}
			else{
				ins(num_1,num_2,insert_string);
			}
			continue;
		}
		

		else if(strcmp(OrderList,"quit")==0){
			break;
		}


	}
	quit();
	return 0;
}