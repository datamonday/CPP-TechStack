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


Status ListDeleteSeq(SeqList &L, int i){
    int j;
    int e; 
    if (i < 1 || i > L.length) 
    {
        return ERROR;
    }
    else 
    {	
    	// 保存被删除的元素 
        e = L.elem[i - 1];
        for (j = i; j <= L.length - 1; j++)
        {
            L.elem[j - 1] = L.elem[j];
        }
        L.length --;
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
	
	// 删除第2个元素 
	ListDeleteSeq(L, 2);
	
	printf("L.length after Delete = %d\n", L.length);
	
	return 0;
}
