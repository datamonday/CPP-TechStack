#include<stdio.h>
#include<stdlib.h> 

#define MAXSIZE 100
#define OK 1
#define ERROR 0


typedef struct{
	SElemType *base; // 栈底指针
	SElemType *top;  // 栈顶指针
	int stacksize;   // 栈可用最大容量 
}SqStack;



// 顺序栈的初始化 
void InitStackSq(sqStack *S){
	S.base = (SElemType*) malloc(MAXSIZE * sizeof(SElemType));
	
	if (!S.base) exit (OVERFLOW);
	
	S.top = S.base;
	S.stacksize = MAXSIZE;
	
	return OK;
} 

// 求顺序栈的长度
int StackLength(SqStack S){
	return S.stop - S.base;
} 

// 清空顺序栈
int ClearStack(SqStack S){
	if (S.base) S.top = S.base;
	return OK;
} 



