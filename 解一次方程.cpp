#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdio>

using namespace std;

int main(){
	char eq[100000];
	cin.getline(eq,100000);
	int length=strlen(eq);		//方程字符串输入

	char c;
	int i,x,y,flag,temp_num,mark;

	// flag:表示在等号左边还是右边
	// temp_num:当前所要加的数字
	// mark：数字前对应的符号
	flag=1; temp_num=0; mark=1;
	x=0; y=0;						
	for (i=0;i<length;++i){
		//记录小写字母，并加上系数
		if ((int)(eq[i])-97>=0 && (int)(eq[i])-97<=25){
			c=eq[i];
			x=x+flag*temp_num*mark;
			temp_num=0;
			mark=1;
			continue;
		}
		//设置符号
		if (eq[i]=='+' || eq[i]=='-'){
			y+=(-1)*mark*temp_num*flag;
			temp_num=0;
			if (eq[i]=='+') mark=1;
			if (eq[i]=='-') mark=-1;
			continue;

		}
		//等号左右判断
		if (eq[i]=='='){
			y+=(-1)*mark*temp_num*flag;
			temp_num=0;
			flag=-1;
			mark=1;
			continue;
		}
		//数字处理
		if ((int)(eq[i])-(int)('0')>=0 && (int)(eq[i])-(int)('0')<=9){
			temp_num=(temp_num*10)+(int)(eq[i])-(int)('0');
		}
		//cout<< temp_num<<'\t'<<y<<'\t'<<x<<'\n'<<endl;

	}
	y+=(-1)*mark*temp_num*flag;
	double ans=1.0*y/x;
	if (abs(ans)<=0.0001) ans=0;
	printf("%c=%.3f\n",c,ans);
	return 0;
}