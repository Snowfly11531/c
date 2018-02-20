#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define LH 1;
#define EH 0;
#define RH -1;
#define TRUE 1;
#define FALSE 0;
typedef struct BSTNode{
    int data;
	int bf;
	struct BSTNode * lchild,* rchild;
}BSTNode,* BSTree;
void leftbalence(BSTree &);
void rightbalence(BSTree &);
void R_Rotate(BSTree &p){
	BSTree lc;
    lc=p->lchild;
	p->lchild=lc->rchild;
	lc->rchild=p;
	p=lc;
}
void L_Rotate(BSTree &p){
	BSTree rc;
    rc=p->rchild;
	p->rchild=rc->lchild;
	rc->lchild=p;
	p=rc;
}
int InsertAVL(BSTree &T,int e,int &taller){
    if(!T){
	    T=(BSTree)malloc(sizeof(BSTNode));
		T->data=e;
		T->bf=0;
		T->lchild=T->rchild=NULL;
		taller=1;
	}else if(T->data==e){
	    taller=0;return 0;
	}else if(T->data>e){
	    if(!InsertAVL(T->lchild,e,taller))return 0;
		if(taller){
			switch(T->bf){
			  case 1:
				  leftbalence(T);taller=FALSE;break;
			  case 0:
				  T->bf=1;taller=TRUE;break;
			  case -1:
				  T->bf=0;taller=FALSE;break;
			}
		}
	}else{
		if(!InsertAVL(T->rchild,e,taller))return 0;
		if(taller){
			switch(T->bf){
			   case 1:
				   T->bf=0;taller=FALSE;break;
			   case 0:
				   T->bf=-1;taller=TRUE;break;
			   case -1:
				   rightbalence(T);taller=FALSE;break;
			}
		}
	}
	return 1;
}
void leftbalence(BSTree & T){
	printf("ok");
    BSTree lc=T->lchild;
	switch(lc->bf){
	    case 1: 
			T->bf=lc->bf=0;
			R_Rotate(T);
	    case -1:
			BSTree rd=lc->rchild;
			switch(rd->bf){
			  case 1:
                 T->bf=-1;lc->bf=rd->bf=0;break;
			  case 0:
				  T->bf=lc->bf=0;
			  case -1:
				  T->bf=0;lc->bf=1;
			}
			L_Rotate(T->lchild);
			R_Rotate(T);
	}
}
void rightbalence(BSTree & T){
	printf("ok");
    BSTree rc=T->rchild;
	switch(rc->bf){
	case -1:
		T->bf=rc->bf=0;
		L_Rotate(T);
	case 1:
		BSTree ld=rc->lchild;
		switch(ld->bf){
		case 1:
			T->bf=0;rc->bf=-1;
		case 0:
			T->bf=rc->bf=0;
		case -1:
			T->bf=1;rc->bf=ld->bf=0;break;
		}
		R_Rotate(T->rchild);
		L_Rotate(T);
	}
}
void qianxu(BSTree t){
    if(t->lchild!=NULL)qianxu(t->lchild);
	printf("%d,",t->data);
	if(t->rchild!=NULL)qianxu(t->rchild);
}
void zhongxu(BSTree t){
	if(t!=NULL)printf("%d,",t->data);
    if(t->lchild!=NULL)zhongxu(t->lchild);
	if(t->rchild!=NULL)zhongxu(t->rchild);
}
int main(){
    int i,taller=1;
	char c=NULL;
	BSTree T=NULL;
    printf("请输入数据(以逗号','隔开):");
	scanf("%d",&i);
    while(c!='\n'){
		printf("%d",i);
	    InsertAVL(T,i,taller);
        c=getchar();
		putchar(c);
		if(c=='\n')break;
		scanf("%d",&i);
	}
	printf("前序:");qianxu(T);
    putchar('\n');
	printf("后序:");zhongxu(T);
	return 0;
}
