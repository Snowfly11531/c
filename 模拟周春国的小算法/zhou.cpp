#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void Sleep( int seconds )
{
 clock_t time;

 time = ( seconds * CLOCKS_PER_SEC ) + clock();

 while( time > clock() )
 {
  ;
 }
}
main(){
	printf("******************************************\n");
	FILE * fp;
    double x[100],y[100],lnx[100],lny[100];
	int i=0,length;
	double sumx=0,sumy=0,avex,avey,sumy1=0,avey1,sumx1=0,avex1;
	char filename[20],path[50]="C:\\Users\\hasee\\Desktop\\";
	printf("�������ļ���:");
	scanf("%s",filename);
	getchar();
	strcat(path,filename);
    if((fp=fopen(path,"r"))==NULL){
	     printf("���ļ�������.\n");
		 return 0;
	}
	printf("******************************************\n");
	printf("��ȡ������:\n���	X		Y\n");
	Sleep(1);
	while(!feof(fp)){
	     fscanf(fp,"%lf",&x[i]);
		 fscanf(fp,"%lf",&y[i]);
		 if(feof(fp))break;
         printf("%d	%lf	%lf\n",i+1,x[i],y[i]);
		 i++;
	}
	fclose(fp);
    length=i;
	for(i=0;i<length;i++){sumy1+=y[i];sumx1+=x[i];}
	printf("����ת��:\n******************************************\n");
	Sleep(1);
	printf("���	LnX		LnY\n");
	for(i=0;i<length;i++){
	     lnx[i]=log(x[i]);
		 sumx+=lnx[i];
		 lny[i]=log(y[i]);
		 sumy+=lny[i];
         printf("%d	%lf	%lf\n",i+1,lnx[i],lny[i]);
	}
	avex=sumx/(double)length;
	avey=sumy/(double)length;
	double fenzi=0,fenmu=0;
	for(i=0;i<length;i++){
		fenzi+=(lnx[i]-avex)*(lny[i]-avey);
		 fenmu+=(lnx[i]-avex)*(lnx[i]-avex);
	}
	double b,a;
	b=fenzi/fenmu;
	fenzi=fenmu=0;
	a=avey-b*avex;
	a=exp(a);
	avey1=sumy1/(double)length;
    double test[100];
	for(i=0;i<length;i++){
	     test[i]=a*pow(x[i],b);
         fenzi+=(y[i]-test[i])*(y[i]-test[i]);
		 fenmu+=(y[i]-avey1)*(y[i]-avey1);
	}
	double R;
	R=1-fenzi/fenmu;
	printf("******************************************\n");
	printf("Excleʹ�õķ���:\n");
	Sleep(1);
	printf("bΪ:%lf\naΪ:%1f\nR��Ϊ:%lf\n",b,a,R);
    fp=fopen(path,"a");
	double b1,a1,R1,plus=0.001,a11;
	double bb,aa,RR=0;
	b1=b*0.7;
	printf("******************************************\n");
	printf("�ܴ���ʹ�õķ���:\n����:0%%...");
	int counter=1;
	while(b1<b*1.3){
        if(counter==150)printf("25%%...");
        if(counter==300)printf("50%%...");
		if(counter==450)printf("75%%...");
	    a1=avey-b1*avex;
		a1=exp(a1);
		a11=a1*0.7;
		while(a11<a1*1.3){
		    fenzi=fenmu=0;
		    for(i=0;i<length;i++){
		        test[i]=a11*pow(x[i],b1);
                fenzi+=(y[i]-test[i])*(y[i]-test[i]);
		        fenmu+=(y[i]-avey1)*(y[i]-avey1);
			}
            R1=1-fenzi/fenmu;
            if(R1>=RR){
		        RR=R1;
		        aa=a11;
		        bb=b1;
			}
			a11+=0.001*a1;
		}
		b1+=plus*b;
		counter++;
	}
    printf("100%%\n");
    printf("bΪ:%.10f\naΪ:%.10f\nR��Ϊ:%lf\n",bb,aa,RR);
	printf("******************************************\n");
	char ch;
	printf("�Ƿ񱣴�����(YΪ���棬�����Ϊ������):");
    ch=getchar();
	getchar();
	if(ch=='Y'||ch=='y'){
	    fprintf(fp,"******************************************\n");
	    fprintf(fp,"Excelʹ�õķ���:\nbΪ:%lf\naΪ:%1f\nR��Ϊ:%lf\n",b,a,R);
	    fprintf(fp,"�ܴ���ʹ�õķ���:\nbΪ:%.10f\naΪ:%.10f\nR��Ϊ:%lf\n",bb,aa,RR);
		printf("******************************************\n");
		printf("�ѱ�����ԭ�ļ��ײ�����鿴\n");
		Sleep(3);
	}
	fclose(fp);
	return 0;
}