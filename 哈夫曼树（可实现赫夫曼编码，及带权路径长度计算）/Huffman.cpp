#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct HTNode{
     int weight;
	 int parent,lchild,rchild;
}HTNode,* Tree;
void create(){
    printf("构建哈夫曼树\n输入权值个数:");
	int n,m;
	scanf("%d",&n);
	m=2*n-1;
	Tree tree=(Tree)malloc(m*sizeof(HTNode));
	for(int i=0;i<n;i++){
	    printf("输入第%d个权值:",i+1);
		scanf("%d",&tree[i].weight);
		tree[i].parent=tree[i].lchild=tree[i].rchild=0;
	}
	for(;i<m;++i) tree[i].weight=tree[i].lchild=tree[i].parent=tree[i].rchild=0;
    for(i=n;i<m;i++){
		int min=1000,posa=0,posb=0;
		for(int j=0;j<i;j++){
			if(tree[j].parent==0){
				if(tree[j].weight<=min){min=tree[j].weight;posa=j;}  
			}
		}
		min=1000;
		for(j=0;j<i;j++){
			if(tree[j].parent==0&&j!=posa){
				if(tree[j].weight<=min){min=tree[j].weight;posb=j;}  
			}
		}
        tree[i].weight=tree[posa].weight+tree[posb].weight;
		tree[i].lchild=posa;tree[i].rchild=posb;
		tree[posa].parent=i;tree[posb].parent=i;
	}
    int sum=0;
	for(i=0;i<n;i++){
		int t=i;
		int len=0;
		while(t!=m-1){
		   t=tree[t].parent;
		   len++;
		}
		sum=sum+len*tree[i].weight;
	}
	printf("带权路径长度:%d\n",sum);
	getchar();
}
main(){
    create();
	return 0;
}
