#include<stdio.h>
#include<math.h>
main(){
   long a;
   int c[20];
   int length=0;
   long weishu=10;
   printf("请输入数字:");
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
   if(k==0){printf("该数为回文数.\n");}
   else{printf("该数不为回文数.\n");}
   return 0;
}