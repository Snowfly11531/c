#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct pNode{
    char data;
	struct pNode * lchird,* rchird;
}pNode,*ptree;
void comtree(ptree &p,char *a,char *b){
    int length=0;
	int i=0;
	while(a[i]!=NULL){
	   length++;
	   i++;
	}
    if(length==0){p=NULL;}
	else{
	   p->data=a[0];
	   for(int j=0;j<length;j++){
	      if(b[j]==a[0])break;
	   }
	   char a1[20]={NULL},a2[20]={NULL},b2[20]={NULL},b1[20]={NULL};
	   int f1=0,f2=0;
	   for(int k=1;k<length;k++){
		   if(k<=j){a1[f1]=a[k];f1++;}
		   else {a2[f2]=a[k];f2++;}
	   }
	   f1=0;f2=0;
	   for( k=0;k<length;k++){
		   if(k<j){b1[f1]=b[k];f1++;}
		   if(k>j){b2[f2]=b[k];f2++;}
	   }
	   p->lchird=(ptree)malloc(sizeof(pNode));
	   comtree(p->lchird,a1,b1);
	   p->rchird=(ptree)malloc(sizeof(pNode));
	   comtree(p->rchird,a2,b2);
	}
}
void houxu(ptree p){
	if(p!=NULL){
    houxu(p->rchird);
	printf("%c",p->data);
	houxu(p->lchird);
	}
}
void shuru(){
	char a[20]={NULL};
	char b[20]={NULL};
    printf("请输入前序:");
	scanf("%s",a);
	printf("请输入中序:");
    scanf("%s",b);
	ptree p=(ptree)malloc(sizeof(pNode));
	comtree(p,a,b);
	printf("后序遍历为:");
	houxu(p);
	printf("\n");
}
main(){
  shuru();
  return 0;
}