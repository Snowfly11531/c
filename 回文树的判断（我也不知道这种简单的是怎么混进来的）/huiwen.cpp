#include<stdio.h>
#include<math.h>
main(){
   long a;
   int c[20];
   int length=0;
   long weishu=10;
   printf("����������:");
   scanf("%d",&a);
   while(a!=0){
	   c[length]=a%weishu;
       a=a/weishu;
	   length++;
   }
   int k=0;
   for(int i=0;i<length/2;i++){
       if(c[i]!=c[length-i-1]){k=1;break;}
   }
   if(k==0){printf("����Ϊ������.\n");}
   else{printf("������Ϊ������.\n");}
   return 0;
}