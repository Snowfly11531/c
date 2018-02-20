#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int k=5;    //占用的内存大小约等于文件大小除以k
typedef int losertree[k];
int partition(int * array,int low,int high){
    array[0]=array[low];
	while(low<high){
	     while(low<high&&array[high]>=array[0])--high;
		 array[low]=array[high];
		 while(low<high&&array[low]<=array[0])++low;
		 array[high]=array[low];
	}
    array[low]=array[0];
	return low;
}
void Quick_sort(int * array,int low,int high){
    if(low<high){
	     int middle=partition(array,low,high);
         Quick_sort(array,low,middle-1);
		 Quick_sort(array,middle+1,high);
	}
}
void sorting(char * path){
	FILE * fp;
	fp=fopen(path,"r");
    int array[2000],length=0;
	while(!feof(fp)){
	   fscanf(fp,"%d",&array[length+1]);
	   length++;
	}
	length--;
	fclose(fp);
	Quick_sort(array,1,length);	
	fp=fopen(path,"w");
	for(int i=1;i<=length;i++){
	    fprintf(fp,"%d ",array[i]);
	}
	fclose(fp);
}
void Adjust(losertree &ls,int s,int * b){
   int t=(s+k)/2;
   int change;
   while(t>0){
       if(b[s]>b[ls[t]]){change=s;s=ls[t];ls[t]=change;}
	   t=t/2;
   }
   ls[0]=s;
}
void Createlosertree(losertree &ls,int * b){
     b[k]=-1;
     for(int i=0;i<k;i++)ls[i]=k;
	 for(i=k-1;i>=0;i--)Adjust(ls,i,b);
}
main(){
    FILE * fp,* fp1;
	FILE * FP[k];
	int length,counter=0,i,number,input;
	char filename[20],path[50]="C:\\Users\\hasee\\Documents\\test\\";
	printf("请输入文件名:");
	scanf("%s",filename);
	length=strlen(filename);
	getchar();
	strcat(path,filename);
	if((fp=fopen(path,"r"))==NULL){
	    printf("此文件不存在.\n");
		return 0;
	}
	while(!feof(fp)){
	    fscanf(fp,"%d",&input);
		counter++;
	}
	rewind(fp);
    number=counter/k;
	for(i=1;i<=k;i++){
		char path1[50]="C:\\Users\\hasee\\Documents\\test\\",filename1[20]={NULL},shuzi[5];
		strncpy(filename1,filename,length-4);
        sprintf(shuzi,"%d",i);
		strcat(filename1,shuzi);
		strcat(filename1,".txt");
		strcat(path1,filename1);
        fp1=fopen(path1,"w");
		for(int j=0;j<number;j++){
		    if(feof(fp))break;
			fscanf(fp,"%d",&input);
			fprintf(fp1,"%d ",input);
		}
		if(i==k){
			while(!feof(fp)){
				printf("ok");
			    fscanf(fp,"%d",&input);
				printf("%d",input);
				fprintf(fp1,"%d ",input);
			}
		}
		fclose(fp1);
        sorting(path1);
		FP[i-1]=fopen(path1,"r");
	}
	fclose(fp);
	fp=fopen("C:\\Users\\hasee\\Documents\\test\\test_result.txt","w");
	int b[k+1];
	losertree ls;
	rewind(FP[1]);
    for(i=0;i<k;i++){
		if(!feof(FP[i]))fscanf(FP[i],"%d",&b[i]);
		else b[i]=10000;
	}
	Createlosertree(ls,b);
	printf("ok");
	while(b[ls[0]]!=10000){
		fprintf(fp,"%d ",b[ls[0]]);
		printf("%d ",b[ls[0]]);
		if(!feof(FP[ls[0]])){
				fscanf(FP[ls[0]],"%d",&b[ls[0]]);
                if(feof(FP[ls[0]]))b[ls[0]]=10000;
		}
		else {b[ls[0]]=10000;printf("ok");}
		Adjust(ls,ls[0],b);
	}
	return 0;
}
