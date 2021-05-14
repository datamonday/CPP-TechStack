# include <stdio.h>
# include <stdlib.h>
# define InitSize 50   // 定义初始分配容量(以sizeof(ElemType)为单位)

# define ERROR -1
# define OK     1

typedef int Status;	   // 定义别名 
typedef int ElemType;  // 定义别名 


// 单链表的存储结构 
typedef struct LNode{
	// 声明结点的类型和指向结点的指针类型 
	ElemType data;			// 结点的数据域 
	struct LNode *next;		// 结点的指针域 
}LNode, *LinkList; 	
// LinkList为为指向LNode结构体类型（有两个成员）的指针; 


// 求单链表中第i个元素的内容, 并通过变量e返回 
Status GetElemLinkList(LinkList L, int i, ElemType &e){
	LNode *p;
	// p 指向第一个结点 
	p = L -> next;
	// 定义计数器变量
	int j = 1; 
	
	// 向后扫描，直至p指向第i个元素或p为空 
	while (p && j < i) {
		p = p -> next;
		++j; 
	}
	 
	// 要查找的第 i 个元素不存在 
	if(!p || j>i ){
		return ERROR;
	}
	else {
		e = p -> data;
		return OK;
	}
}


int main(){
	LinkList L;

	return 0;
}
