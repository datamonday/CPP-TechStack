# include <stdio.h>
# include <stdlib.h>
# define InitSize 50	// 定义初始分配容量(以sizeof(ElemType)为单位)

typedef struct{
	int id;
	//char *name;
}ElemType;

typedef struct{
	ElemType *elem;  // 存储空间基地址
	int length;		 // 当前长度(个数)
    int MaxSize;     //最大容量
}SeqList; 


int main(){
	SeqList L;
	L.elem = (ElemType*)malloc(InitSize * sizeof(ElemType));
	L.elem -> id = 10;
	L.length = 2;
	
	printf("L.length  = %d\n", L.length);
	printf("L.elem[0] = %d\n", L.elem[0]);
	
	return 0;
}
