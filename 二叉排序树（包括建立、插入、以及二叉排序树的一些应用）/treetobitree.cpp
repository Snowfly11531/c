#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct tre{
    char tag;
	int key;
}tre,tree[20];
typedef struct Bitre{
    char tag;
    struct bitree * lchild,* rchild;
}Bitre,* Bitree;
int printin(tree &bt){
    printf("ÇëÊäÈë½Úµã×Ö·û:");
	char c;
	c=getchar();
	int i=0;
    while(c!='\n'){
	    bt[i].tag=c;
        i++;
		c=getchar();
	}
	return i;
}
main(){
    tree bt;
	int length;
	length=printin(bt);
    for(int i=0;i<length;i++){
		printf("%c ",bt[i].tag);
	}
}