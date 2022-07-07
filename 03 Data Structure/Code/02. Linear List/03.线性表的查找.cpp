# include <stdio.h>
# include <stdlib.h>
# define InitSize 50   // 定义初始分配容量(以sizeof(ElemType)为单位)

typedef int Status;	   // 定义别名 
typedef int ElemType;  // 定义别名 

typedef struct{
	ElemType *elem;  // 存储空间基地址
	int length;		 // 当前长度(个数)
    int MaxSize;     //最大容量
}SeqList; 


int LocateItem(SeqList L, ElemType e){
	int i;
	for (i=0; i < L.length; ++i) {
		if (L.elem[i] == e){
			return i + 1;  // 返回元素的位置(位序) 
		}
	return 0;
	}
} 

int main(){
	SeqList L;
	L.elem = (ElemType*)malloc(InitSize * sizeof(ElemType));
	L.elem[0] = 10;
	L.elem[1] = 20;
	L.length = 2;
	
	int pos;
	// 查找元素 10 
	pos = LocateItem(L, 10);
	
	printf("Item position = %d\n", pos);
	
	return 0;
}
