#include<stdio.h>
#include<stdlib.h>
typedef struct SStable{
	int number[50];
	int length;
	float w[50];
	float sw[50];
}SStable;
void Create(SStable & st){
	int change;
	float weight;
    printf("�������:");
	scanf("%d",&st.length);
	getchar();
	for(int i=1;i<=st.length;i++){
	    printf("�������%d��������Ȩֵ(number weight):",i);
		scanf("%d %f",&st.number[i-1],&st.w[i-1]);
		getchar();
	}
	for(i=st.length-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(st.number[j]>st.number[j+1]){change=st.number[j];
			st.number[j]=st.number[j+1];st.number[j+1]=change;
			weight=st.w[j];st.w[j]=st.w[j+1];st.w[j+1]=weight;
			}
		}
	}
	float sum=0;
	for(i=0;i<st.length;i++){
	    st.sw[i]=sum+st.w[i];
		sum=st.sw[i];
	}
}
void search(SStable st){
    printf("��������Ҫ���ҵ���:");
	int key;
	scanf("%d",&key);
	getchar();
	int low=0,high=st.length-1,mid;
	while(low<=high){
	    mid=(low+high)/2;
		if(key==st.number[mid]) {printf("�������ڵ�%d��λ����",mid+1);exit(0);}
		else if(key>st.number[mid])low=mid+1;
		else high=mid-1;
	}
	printf("���������޴���");
}
main(){
    SStable st;
	Create(st);
	search(st);
	return 0;
}