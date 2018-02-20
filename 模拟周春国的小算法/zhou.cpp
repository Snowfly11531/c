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
	printf("请输入文件名:");
	scanf("%s",filename);
	getchar();
	strcat(path,filename);
    if((fp=fopen(path,"r"))==NULL){
	     printf("该文件不存在.\n");
		 return 0;
	}
	printf("******************************************\n");
	printf("读取数据中:\n序号	X		Y\n");
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
	printf("对数转换:\n******************************************\n");
	Sleep(1);
	printf("序号	LnX		LnY\n");
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
	printf("Excle使用的方法:\n");
	Sleep(1);
	printf("b为:%lf\na为:%1f\nR方为:%lf\n",b,a,R);
    fp=fopen(path,"a");
	double b1,a1,R1,plus=0.001,a11;
	double bb,aa,RR=0;
	b1=b*0.7;
	printf("******************************************\n");
	printf("周春国使用的方法:\n进度:0%%...");
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
    printf("b为:%.10f\na为:%.10f\nR方为:%lf\n",bb,aa,RR);
	printf("******************************************\n");
	char ch;
	printf("是否保存数据(Y为保存，其余键为不保存):");
    ch=getchar();
	getchar();
	if(ch=='Y'||ch=='y'){
	    fprintf(fp,"******************************************\n");
	    fprintf(fp,"Excel使用的方法:\nb为:%lf\na为:%1f\nR方为:%lf\n",b,a,R);
	    fprintf(fp,"周春国使用的方法:\nb为:%.10f\na为:%.10f\nR方为:%lf\n",bb,aa,RR);
		printf("******************************************\n");
		printf("已保存至原文件底部，请查看\n");
		Sleep(3);
	}
	fclose(fp);
	return 0;
}