#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void Bolan(char * s,int length){
	int lengtha=0,lengthb=0,lengthpara=0,lengthsymbol=0;
	char a[10],b[10];
    if(length!=1){
		for(int i=1;i<length;i++){
			if(s[i]>=97&&s[i]<=122) lengthpara++;
			else lengthsymbol++;
			if(lengthpara>lengthsymbol)break;
		}
		lengtha=i;
		lengthb=length-lengtha-1;
        for(int j=0;j<lengtha;j++)
			a[j]=s[j+1];
		for(j=0;j<lengthb;j++)
			b[j]=s[j+1+lengtha];
        Bolan(a,lengtha);//左叉递归起点
        Bolan(b,lengthb);//右叉递归起点
		char symbol1=s[0];
		for(j=0;j<lengtha;j++)
			s[j]=a[j];
		for(j=0;j<lengthb;j++)
			s[j+lengtha]=b[j];
		s[length-1]=symbol1;
	}
}
int main(){
    printf("请输入前缀表达式:");
	char s[25];
	int i=0;
	char c=getchar();
	while(c!='\n'){
	    s[i]=c;
		c=getchar();
		i++;
	}
	Bolan(s,i);
    printf("后缀表达式为:");
	for(int j=0;j<i;j++){
	    putchar(s[j]);
	}
	printf("\n");
	return 0;
}