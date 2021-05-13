# include <stdio.h>
# include <stdlib.h>
# define MaxSize 255

//typedef int ElemType;

typedef struct{
	int id;
}ElemType;


typedef struct{
	ElemType *elem;
	int length;
}SeqList; 


int main(){
	// 第二种定义方法 
	SeqList *L;
	
	L -> elem = (ElemType*)malloc(MaxSize * sizeof(ElemType));
	L -> length = 2;
	L -> elem -> id = 100;
	
	printf("L -> length  = %d\n", L -> length);
//	printf("L -> elem[0] = %d\n", L -> elem[0]);

	return 0;
}


