# include <stdio.h>
# include <stdlib.h>
# define InitSize 50	// 定义初始分配容量(以sizeof(ElemType)为单位)

#define TRUE  1
#define False 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int Status;		// 定义别名 
typedef int ElemType;  // 定义别名 

//typedef struct{
//	int id;
//}ElemType;

typedef struct{
	ElemType *elem;  // 存储空间基地址
	int length;		 // 当前长度(个数)
    int MaxSize;     //最大容量
}SeqList; 


// 1.线性表初始化
Status InitListSeq(SeqList &L){
	// 构造一个空的线性表L
	L.elem = (ElemType *)malloc(InitSize * sizeof(ElemType)); 
	// 异常情况处理
	if(!L.elem){
		exit(OVERFLOW);	// 存储分配失败 
	} 
	// 空表长度为1
	L.length = 0;
	
	return OK; 
} 


// 2.销毁线性表
void DestroyList(SeqList &L){
	if(L.elem) {
		// 释放空间 
		free(L.elem);
	}
} 

// 3.清空线性表
void ClearList(SeqList &L){
	L.length = 0; 
} 

// 4. 求表L的长度
int GetLength(SeqList &L) {
	return (L.length);
} 

// 5. 判断线性表L是否为空
int IsEmpty(SeqList &L) {
	if(L.length == 0){
		return true;
	}
	else{
		return false;
	}
} 

// 6. 根据位置i获取元素内容
int GetItem(SeqList L, int i, ElemType &e){
	if(i < 0 || i > L.length){
		return ERROR;
	}
	else{
		// 第i-1的单元存储着第i个数据 
		e = L.elem[i - 1];
		return e;
	}
}


int main(){
	int i;
	SeqList L;
	
	InitListSeq(L);
	L.elem[0] = 10;
	L.elem[1] = 20;
	L.length = 2;
	
	printf("L.length  = %d\n", L.length);
	for(i=0; i < L.length; ++i) {
		printf("L.elem[%d] = %d\n", i, L.elem[i]);
	}
	
	ElemType e;
	e = GetItem(L, 1, e);
	printf("The elem found is %d\n", e);
	
	
	DestroyList(L);
	printf("L.elem after destroied:\n");
	printf("L.length  = %d\n", L.length);
	printf("L.elem[0] = %d\n", L.elem[0]);
	
	ClearList(L);
	printf("L is Empty?");
	if(IsEmpty(L) == true){
		printf("true!\n");
	} 
	else{
		printf("false!\n");
	}
	
	return OK;
}


