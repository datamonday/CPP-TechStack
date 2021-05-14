# include <stdio.h>
# include <stdlib.h>
# define InitSize 50   // 定义初始分配容量(以sizeof(ElemType)为单位)

# define ERROR -1
# define OK     1

typedef int Status;	   // 定义别名 
typedef int ElemType;  // 定义别名 

typedef struct{
	ElemType *elem;  // 存储空间基地址
	int length;		 // 当前长度(个数)
    int MaxSize;     //最大容量
}SeqList; 


Status ListInsert(SeqList &L, int i, ElemType e) {
	int j;
	// 插入不合法 
	if (i < 1 || i > L.length + 1) 
	{
		return ERROR;
	}
	// 当前存储空间已满 
	else if (L.length == L.MaxSize)
	{
		return ERROR;
	}
	else 
	{
		// 从最后一个元素一直到第 i 个位置上的元素依次向后移动 
		for (j = L.length-1; j >= i-1; --j) 
		{
			L.elem[j + 1] = L.elem[j];
		}
		// 将新元素放入第 i 个位置  
		L.elem[i - 1] = e;
		// 表长增加1 
		L.length ++;
	} 
	return OK;
} 


int main(){
	SeqList L;
	L.elem = (ElemType*)malloc(InitSize * sizeof(ElemType));
	L.elem[0] = 10;
	L.elem[1] = 20;
	L.length = 2;
	
	int pos;
	
	// 插入元素 30
	ListInsert(L, 3, 30);
	
	printf("Insert Item = %d\n", L.elem[2]);
	
	return 0;
}
