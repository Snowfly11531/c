#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define Firstsize 100;
#define each_size 10;
typedef struct {
    char *base;
	char *top;
	int listsize;
}sqStack;
typedef struct Nnode{
    int data;
	struct Nnode *next;
}Nnode, *List;
void Initlist(List list){
    list=(List)malloc(sizeof(Nnode));
	list->next=NULL;
}
void add(List list,int e){
    List p=(List)malloc(sizeof(Nnode));
	List q;
	q=list;
	while(q->next!=NULL){
	     q=q->next;
	}
	q->next=p;
	p->data=e;
	p->next=NULL;
}
void destroy(List list){
    List p,q;
	p=list->next;
	while(p!=NULL){
	    q=p;
		p=p->next;
		free(q);
	}
	list->next=NULL;
}
void average(){
    List list,p;
	list=(List)malloc(sizeof(Nnode));
	list->next=NULL;
	int i,sum=0,a=1;
	char c;
	printf("请输入数字:");
	scanf("%d",&i);
	c=getchar();
	while(a=1){
		if(c=='\n'){add(list,i);break;}
		else if(c!=','){
		   printf("请正确输入\n请输入数字:");
		   while(c!='\n'){
			   c=getchar();
		   }
		   scanf("%d",&i);
		   c=getchar(); 
		   destroy(list);
		   continue;
		}else{
		   add(list,i);
		   scanf("%d",&i);
		   c=getchar();
		}
	}
	p=list->next;
	while(p!=NULL){
	    sum=sum+p->data;
		p=p->next;
	}
	printf("和为：%d",sum);
}
void InitStack(sqStack &s){
    s.base=(char *)malloc(100 * sizeof(char));
    if(!s.base)exit(OVERFLOW);
	s.top=s.base;
	s.listsize=100;
}
void push(sqStack &s,char e){
    if((s.top-s.base)>=s.listsize){
	   s.base=(char *)realloc(s.base,(s.listsize+10)*sizeof(char));
	   if(!s.base)exit(OVERFLOW);
	   s.top=s.base+s.listsize;
	   s.listsize+=10;
	}
	*s.top++=e;
}
void pop(sqStack &s){
    if(s.top==s.base)printf("empty");
	else --s.top;
}
void kuohao(){
	sqStack s;
    InitStack(s);
	char N;
	char e;
	int a=1;
  while(a==1){
	printf("please write(if you want exit,please write:e):");
	scanf("%c",&N);
	if(N=='e')exit(0);
	while(N!='\n'){
		if(N=='['||N==']'||N=='('||N==')'){
			if(s.top==s.base)push(s,N);
			else{
				e=*(s.top-1);
			    if((N==']'&&e=='[')||(N==')'&&e=='('))pop(s);
				else push(s,N);
			}
		}
		scanf("%c",&N);
	}
	if(s.top==s.base)printf("yes\n");
	else {printf("no\n");s.top=s.base;}
  }
}
float abs(float a){
   if(a<0)return (-a);
   else return(a);
}
void sqrt(float a,float p,float e){
    if(abs(p*p-a)<=e)printf("%0.4f",p);
	else{
	   sqrt(a,(p+a/p)/2,e);
	}
}
float jiecheng(int n){
    float sum=1;
	for(int i=1;i<=n;i++){
	     sum=sum*i;
	}
	return sum;
}
double exp(){
	double f=1;
	int i=1;
    while((double)1/(double)jiecheng(i)>=10e-10){
	   f=f+((double)1/(double)jiecheng(i));
	   i++;
	}
	return f;
}
int max(int a,int b){
	return a>=b?a:b;    
}
int min(int a,int b){
    return a<=b?a:b;
}
void compare(){
    char c,a[50],b[50];
	c=getchar();
	int k,f;
	int lengtha=0,lengthb=0;
	while(c!=','){
		a[lengtha]=c;
		lengtha++;
		c=getchar();
	}
	c=getchar();
	while(c!='\n'){
	    b[lengthb]=c;
		lengthb++;
		c=getchar();
	}
	for(int i=0;i<lengthb;i++){
	    putchar(b[i]);
	}
	char kit[50],bit[50];
	for(int j=0;j<lengthb;j++){
	    k=lengthb-j-1;
		k=min(lengtha,k);
		f=0;
		if(j==0){
		   for(i=0;i<k;i++){
			  if(a[i]=b[i+j]){kit[i]=f;f++;i++;}
              else{f=0;kit[i]=0;i++;}
		   }
		}else{
			for(i=0;i<k;i++){
			  if(a[i]=b[i+j]){bit[i]=f;f++;i++;}
              else{f=0;bit[i]=0;i++;}
			}
            for(i=0;i<k;i++){
			  kit[i]=max(kit[i],bit[i]);
			}
		}
		j++;
	}
}
main(){
	kuohao();
	return 0;
}