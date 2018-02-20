#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
     char name[20];
	 char num[10];
	 int age;
}* Group;
void output(){   //字符串的输入和输出
    FILE * fp;
	int i=-1;
	char ch,* abspath,filename[10],path[]="C:\\Users\\hasee\\Desktop\\";
	printf("please enter a file name(the file will be save to the desktop):");
	scanf("%s",filename);
	abspath=strcat(path,filename);
    getchar();
	if((fp=fopen(abspath,"r"))==0){
		printf("该文件不存在需要新建.\n");
	    if((fp=fopen(abspath,"w"))==NULL){
	        printf("无法建立这样的一个新文件.");
		    exit(0);
		}
	}else{
	    printf("改文件以存在，请选择追加或覆盖(a=add;c=cover):");
		ch=getchar();
		getchar();
		if(ch=='a'){
			fp=fopen(abspath,"a");
		}else if(ch=='c'){
			if((fp=fopen(abspath,"w"))==NULL){
			     printf("无法建立一个新文件.");
				 exit(0);
			}
		}else{
			printf("请正确输入。");
			exit(0);
		}
	}
	printf("请输入一个准备储存到位置的字符串:");
    ch=getchar();
	while(ch!='\n'){
	    fputc(ch,fp);
		ch=getchar();
	}
	fclose(fp);
	if((fp=fopen(abspath,"r"))==NULL){
	    exit(0);
	}
	while(!feof(fp)){
		ch=fgetc(fp);
		putchar(ch);
	}
	putchar('\n');
}
void inout(){   //fscanf及fprintf的应用
	int i,j;
	FILE * fp;
	char * path="C:\\Users\\hasee\\Desktop\\haha.txt";
    if((fp=fopen(path,"r"))==NULL){
	     printf("创建文件失败");
		 exit(0);
	}
	while(!feof(fp)){
		fscanf(fp,"%d %d",&i,&j);
		printf("%d %d ",i,j);
	}
}
void pack(){   //打包输出数据，main程序中已有此功能
    FILE * fp;
	int i;
	printf("please enter number:");
	scanf("%d",&i);
	getchar();
    student stu;
	if((fp=fopen("C:\\Users\\hasee\\Desktop\\student1.dat","ab"))==NULL){
	    printf("cannot open file\n");
        exit(0);
	}
	for(int j=0;j<i;j++){
		printf("请输入第%d个同学的信息(格式:名字 学号 年龄):",j+1);
	    scanf("%s%s%d",stu.name,stu.num,&stu.age);
        if((fwrite(&stu,sizeof(student),1,fp))==NULL){
		   printf("file write error");
		}
	}
	fclose(fp);
	fp=fopen("C:\\Users\\hasee\\Desktop\\student1.dat","rb");
	printf("从文件读出已有学生信息:\n");
	int number=0;
	while(!feof(fp)){
	    fread(&stu,sizeof(student),1,fp);
		if(feof(fp))break;
		number++;
		printf("第%d个学生信息:%s %s %d\n",number,stu.name,stu.num,stu.age);
	}
	fclose(fp);
}
main(){  //main
    pack();
	return 0;
}
