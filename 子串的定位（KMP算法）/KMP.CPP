#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct SString{
    char c[20];
    int length;
}SString;
void get_next(SString ,int *);
void KMP(){
	SString sstringa,sstringb;
	int i=0;
    printf("输入主串:");
	char c=getchar();
	while(c!='\n'){
	    sstringa.c[i]=c;
		c=getchar();
		i++;
	}
	sstringa.length=i;
	printf("输入定位串:");
	i=0;
	c=getchar();
	while(c!='\n'){
	    sstringb.c[i]=c;
		c=getchar();
		i++;
	}
	sstringb.length=i;
	int next[20];
	get_next(sstringb,next);
    i=0;
	int j=0;
	while(i<sstringa.length && j<sstringb.length){
		if(j==-1||sstringa.c[i]==sstringb.c[j]){i++;j++;}
		else{j=next[j];}
	}
    if(j=sstringb.length-1){
		printf("定位串在主串的第%d位到第%d位之间\n",i-j,i);
	}else{
	    printf("定位串不在主串当中。\n");
	}
}
void get_next(SString sstringb,int * next){
    int i=0,j=-1;
	next[0]=-1;
	while(i<sstringb.length-1){
		if(j==-1||sstringb.c[i]==sstringb.c[j]){++i;++j;next[i]=j;}
		else{j=next[j];}
	}
}
main(){
    KMP();
	return 0;
}