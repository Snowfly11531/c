#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
     char name[20];
	 char num[10];
	 int age;
}* Group;
void output(){   //�ַ�������������
    FILE * fp;
	int i=-1;
	char ch,* abspath,filename[10],path[]="C:\\Users\\hasee\\Desktop\\";
	printf("please enter a file name(the file will be save to the desktop):");
	scanf("%s",filename);
	abspath=strcat(path,filename);
    getchar();
	if((fp=fopen(abspath,"r"))==0){
		printf("���ļ���������Ҫ�½�.\n");
	    if((fp=fopen(abspath,"w"))==NULL){
	        printf("�޷�����������һ�����ļ�.");
		    exit(0);
		}
	}else{
	    printf("���ļ��Դ��ڣ���ѡ��׷�ӻ򸲸�(a=add;c=cover):");
		ch=getchar();
		getchar();
		if(ch=='a'){
			fp=fopen(abspath,"a");
		}else if(ch=='c'){
			if((fp=fopen(abspath,"w"))==NULL){
			     printf("�޷�����һ�����ļ�.");
				 exit(0);
			}
		}else{
			printf("����ȷ���롣");
			exit(0);
		}
	}
	printf("������һ��׼�����浽λ�õ��ַ���:");
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
void inout(){   //fscanf��fprintf��Ӧ��
	int i,j;
	FILE * fp;
	char * path="C:\\Users\\hasee\\Desktop\\haha.txt";
    if((fp=fopen(path,"r"))==NULL){
	     printf("�����ļ�ʧ��");
		 exit(0);
	}
	while(!feof(fp)){
		fscanf(fp,"%d %d",&i,&j);
		printf("%d %d ",i,j);
	}
}
void pack(){   //���������ݣ�main���������д˹���
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
		printf("�������%d��ͬѧ����Ϣ(��ʽ:���� ѧ�� ����):",j+1);
	    scanf("%s%s%d",stu.name,stu.num,&stu.age);
        if((fwrite(&stu,sizeof(student),1,fp))==NULL){
		   printf("file write error");
		}
	}
	fclose(fp);
	fp=fopen("C:\\Users\\hasee\\Desktop\\student1.dat","rb");
	printf("���ļ���������ѧ����Ϣ:\n");
	int number=0;
	while(!feof(fp)){
	    fread(&stu,sizeof(student),1,fp);
		if(feof(fp))break;
		number++;
		printf("��%d��ѧ����Ϣ:%s %s %d\n",number,stu.name,stu.num,stu.age);
	}
	fclose(fp);
}
main(){  //main
    pack();
	return 0;
}
