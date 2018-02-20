#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct BiNode{
    int number;
    struct BiNode * lchild,* rchild;
}BiNode,*Bitree;
int Search(Bitree t,int key,Bitree f,Bitree & p){
    if(!t){p=f;return 0;}
	else if(key==t->number){p=t;return 1;}
    else if(key<t->number)return Search(t->lchild,key,t,p);
	else return Search(t->rchild,key,t,p);
}
int insert(Bitree & t,int key){
    Bitree p=NULL;
    if(!Search(t,key,NULL,p)){
	    Bitree s=(Bitree)malloc(sizeof(BiNode));
		s->number=key;s->lchild=s->rchild=NULL;
		if(!p)t=s;
		else if(key<p->number)p->lchild=s;
        else p->rchild=s;
		return 0;
	}else{
	    return p->number;
	}
}
void order(FILE * & fp,Bitree t,int &sum,int &n){
    if(t->lchild!=NULL)order(fp,t->lchild,sum,n);
	fprintf(fp,"%d ",t->number);
	sum+=t->number;
	n+=1;
	if(t->rchild!=NULL)order(fp,t->rchild,sum,n);
}
void var(FILE * & fp,Bitree t,float ave,float & sum){
    if(t->lchild!=NULL)var(fp,t->lchild,ave,sum);
	sum+=((float)t->number-ave)*((float)t->number-ave);
	if(t->rchild!=NULL)var(fp,t->rchild,ave,sum);
}
void chuli(){
    Bitree p1,t=NULL;
	FILE * fp;
	int number,p;
	char choose;
	char  path1[50]="C:\\Users\\hasee\\Desktop\\",path[50]="C:\\Users\\hasee\\Desktop\\";
	char filename[30],* filepath;
	printf("输入数据文件名:");
    scanf("%s",filename);
	getchar();
	filepath=strcat(path,filename);
    if((fp=fopen(filepath,"r"))==NULL){
	     printf("无法读取改文件.");
		 exit(0);
	}
	while(!feof(fp)){
        fscanf(fp,"%d",&number);
		if(p=insert(t,number)) printf("数字%d重复,将删除\n",p);
	}
	fclose(fp);
	printf("是否覆盖原文件(Y or N):");
	scanf("%c",&choose);
	getchar();
	if(choose=='Y'){
	     fp=fopen(filepath,"w");
	}else if(choose=='N'){
	     printf("请输入新文件名:");
		 scanf("%s",filename);
		 filepath=strcat(path1,filename);
		 fp=fopen(filepath,"w");
	}
	int sum=0;
	int n=0;
	float ave;
    order(fp,t,sum,n);
    ave=(float)sum/(float)n;
	fprintf(fp,"\n%d个数的总和为:%d\n%d个数的平均数为:%.2f",n,sum,n,ave);
	float sum1=0;
	var(fp,t,ave,sum1);
	ave=sum1/(float)n;
	fprintf(fp,"\n%d个数的方差为:%.4f\n%d个数的标准差为:%.4f",n,ave,n,sqrt((double)ave));
	int min,max;
	p1=t;
    while(p1->lchild!=NULL)p1=p1->lchild;
	min=p1->number;
	p1=t;
	while(p1->rchild!=NULL)p1=p1->rchild;
	max=p1->number;
	fprintf(fp,"\n%d个数的极差为:%d",n,max-min);
	fclose(fp);
}
main(){
    chuli();
	return 0;
}