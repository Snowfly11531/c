#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20  //图中顶点个数最多为20个
typedef struct Arcnode{
    int adjvex;
	struct Arcnode *nextarc;
    int weight;
}Arcnode;
typedef struct Vnode{
    char data;
    Arcnode * firstarc;
}Vnode,AdjList[MAX_VERTEX_NUM];
typedef struct{
    AdjList vertices;
	int vexnum,arcnum;
	int kind;
}ALGraph;
typedef struct CTNode{
    int child;
	struct CTNode *next;
}* ChildPtr;
typedef struct CtBox{
    char data;
	ChildPtr firstchild;
}CTBox;
typedef struct CTree{
    CTBox nodes[MAX_VERTEX_NUM];
	int n,r;
}CTree;
typedef struct state{
    int c;
	int a;
}state,states[20];
typedef struct Dijlist{
	int len;
    int p;
	int t;
	char path[20];
}Dijlist,Dijlists[20];
void DFS(CTree &,ALGraph,int,CTNode *,Arcnode *,states);
void view(CTree &,int,CTNode *);
ALGraph adjlist(){   //建立邻接表格式的图
	char c=NULL;
	ALGraph a;
	printf("请输入顶点总数:");
    scanf("%d",&a.vexnum);
	printf("请输入弧段总数:");
	scanf("%d",&a.arcnum);
    printf("请输入顶点:");
	getchar();
	for(int i=0;i<a.vexnum;i++){
	    c=getchar();
		if(c=='\n'){printf("顶点数不够顶点总数%d，请继续输入:",a.vexnum);i--;}
		else a.vertices[i].data=c;
	}
	c=getchar();
	if(c!='\n'){
	    printf("输入点>顶点总数%d,多余部分将被省去\n",a.vexnum);
	}
	for(i=0;i<a.vexnum;i++)a.vertices[i].firstarc=NULL;
	for(i=1;i<=a.arcnum;i++){
		char aa,b;
		int weight;
		int posa=-1,posb=-1;
	    printf("请输入第%d条弧段(格式为a->b,weight):",i);
        scanf("%c->%c,%d",&aa,&b,&weight);
		getchar();
		for( int j=0;j<a.vexnum;j++){
			if(a.vertices[j].data==aa)posa=j;
            if(a.vertices[j].data==b)posb=j;
		}
		if(posa==-1||posb==-1){printf("弧段中的点不在顶点列表中，请从新输入\n");i--;}
		else{
		    Arcnode * p,* q,*t;
			if(a.vertices[posa].firstarc==NULL){
			    t=(Arcnode *)malloc(sizeof(Arcnode));
				t->nextarc=NULL;
				t->adjvex=posb;
				t->weight=weight;
                a.vertices[posa].firstarc=t;
			}
			else {
				q=a.vertices[posa].firstarc;
				p=q;
			    while(q!=NULL&&q->adjvex<posb){p=q;q=q->nextarc;}
                if(q==NULL){
			         t=(Arcnode *)malloc(sizeof(Arcnode));
					 p->nextarc=t;
                     t->nextarc=NULL;
				     t->adjvex=posb;
				     t->weight=weight;
				}else if(q->adjvex>posb){
				     t=(Arcnode *)malloc(sizeof(Arcnode));
					 if(q==a.vertices[posa].firstarc){t->nextarc=p;a.vertices[posa].firstarc=t;}
					 else {p->nextarc=t;t->nextarc=q;}
				     t->adjvex=posb;
				     t->weight=weight;
				}else{
				     printf("该弧段已输入，不能重复输入\n");
					 --i;
					 continue;
				}
			}
		   	if(a.vertices[posb].firstarc==NULL){
			    t=(Arcnode *)malloc(sizeof(Arcnode));
				t->nextarc=NULL;
				t->adjvex=posa;
				t->weight=weight;
				a.vertices[posb].firstarc=t;
			}
			else{
				q=a.vertices[posb].firstarc;
				p=q;
			    while(q!=NULL&&q->adjvex<posa){p=q;q=q->nextarc;}
                if(q==NULL){
			         t=(Arcnode *)malloc(sizeof(Arcnode));
					 p->nextarc=t;
                     t->nextarc=NULL;
				     t->adjvex=posa;
				     t->weight=weight;
				}else if(q->adjvex>posa){
				     t=(Arcnode *)malloc(sizeof(Arcnode));
					 if(q==a.vertices[posb].firstarc){t->nextarc=p;a.vertices[posb].firstarc=t;}
					 else {p->nextarc=t;t->nextarc=q;}
				     t->adjvex=posa;
				     t->weight=weight;
				}else{
				     printf("该弧段已输入，不能重复输入\n");
					 --i;
				}
			}
		}
	}
	return a;

}
void examine(ALGraph a){   //遍历邻接表格式的图
	for(int i=0;i<a.vexnum;i++){
		printf("从%c出发的弧段有:",a.vertices[i].data);
	    Arcnode * p;
		p=a.vertices[i].firstarc;
		while(p!=NULL){
		    printf("%c->%c,%d	",a.vertices[i].data,a.vertices[p->adjvex].data,p->weight);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void DFSForest(ALGraph a){   //找到遍历图的起点
	printf("请输入起始顶点:");
	getchar();
	char c=getchar();
    CTree ctree;
	states s;
	int pos;
	ctree.n=a.vexnum;
	for(int i=0;i<ctree.n;i++){
	    ctree.nodes[i].data=a.vertices[i].data;
		s[i].c=i;
		s[i].a=0;
		ctree.nodes[i].firstchild=NULL;
        if(a.vertices[i].data==c)pos=i;
	}
    ctree.r=pos;
	DFS(ctree,a,ctree.r,ctree.nodes[ctree.r].firstchild,a.vertices[ctree.r].firstarc,s);
	printf("深度遍历算法生成树:");
    view(ctree,ctree.r,ctree.nodes[ctree.r].firstchild);
}
void view(CTree &ctree,int i,CTNode * t){  //遍历“生成树”
	while(t!=NULL){
	    printf("%c->child:%c\n",ctree.nodes[i].data,ctree.nodes[t->child].data);
		view(ctree,t->child,ctree.nodes[t->child].firstchild);
		t=t->next;
	}
}
void DFS(CTree &ctree,ALGraph a,int i,CTNode * t,Arcnode * p,states s){  //深度遍历图并生成“生成树”
	s[i].a=1;
    int pre=i;
    while(p!=NULL){
	    i=p->adjvex;
		if(s[i].a==0){
		    CTNode * q=(CTNode *)malloc(sizeof(CTNode));
			if(t==NULL){
			    t=ctree.nodes[pre].firstchild=q;
				q->child=i;
				q->next=NULL;
			}else{
				while(t->next!=NULL){
				    t=t->next;
				}
				t->next=q;
				q->child=i;
				q->next=NULL;
			}
	  	    DFS(ctree,a,i,ctree.nodes[i].firstchild,a.vertices[i].firstarc,s);   //建立子树的森林
		}
		p=p->nextarc;		
	}
}
void copy(char * a,char  * b){   //字符串复制
	int i=0;
    while(b[i]!=NULL){
		a[i]=b[i];
		i++;
	}
}
void Dijkstra(ALGraph a){   //Dijstra算法实现
	getchar();
    printf("使用Dijkstra算法计算最短路径\n输入起点:");
	char c=getchar();
	Dijlists dijlists;
	int pos,length=0;
	Arcnode * p;
	char paths[20]={NULL};
	for(int i=0;i<a.vexnum;i++){
		for(int j=0;j<a.vexnum;j++){
		    dijlists[i].path[j]=NULL;
		}
	}
	for( i=0;i<a.vexnum;i++){
	   dijlists[i].p=i;
	   dijlists[i].t=1000;
	   dijlists[i].len=1000;
	   if(a.vertices[i].data==c){
	       dijlists[i].len=0;
		   dijlists[i].path[0]=a.vertices[i].data;
		   dijlists[i].t=0;
		   pos=i;
	   }
	}
	copy(paths,dijlists[pos].path);
	for(i=0;i<(a.vexnum-1);i++){
		p=a.vertices[pos].firstarc;
		while(p!=NULL){
			if(dijlists[p->adjvex].len==1000){
				if((length+p->weight)<=dijlists[p->adjvex].t){
					dijlists[p->adjvex].t=length+p->weight;
					char reset[20]={NULL};
					int t=0;
					while(paths[t]!=NULL){
					    reset[t]=paths[t];
						t++;
					}
					reset[t]=a.vertices[p->adjvex].data;
					copy(dijlists[p->adjvex].path,reset);
				}
			}
			p=p->nextarc;
		}
		int min=1000;
		for(int k=0;k<a.vexnum;k++){
			if(dijlists[k].len==1000){
				if(dijlists[k].t<=min){min=dijlists[k].t;copy(paths,dijlists[k].path);pos=k;}
			}
		}
		dijlists[pos].len=min;
		length=min;
	}
	for(i=0;i<a.vexnum;i++){
	    printf("%c到%c的最短距离为%d,路径为:",c,a.vertices[i].data,dijlists[i].len);
		int k=0;
        while(dijlists[i].path[k+1]!=NULL){printf("%c->",dijlists[i].path[k]);k++;}
		printf("%c",dijlists[i].path[k]);
		printf("\n");
	}
    printf("haha");
}
main(){
   ALGraph a=adjlist();
   examine(a);
   printf("是否生成以某端点为根的生成树(Y or N):");
   char c=getchar();
   while(c!='Y'&&c!='N'){getchar();printf("只能输入Y或者N，请重新输入:");c=getchar();}
   if(c=='Y')DFSForest(a);
   else{printf("哦，那就不生成吧:(\n");}
   Dijkstra(a);
   return 0;
}