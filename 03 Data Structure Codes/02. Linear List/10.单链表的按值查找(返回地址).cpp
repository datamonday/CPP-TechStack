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
}LNode, *LinkList; 	// LinkList为为指向LNode结构体类型（有两个成员）的指针; 


// 单链表按照值查找
// LNode * 表示这个函数返回的类型是LNode指针类型
LNode *LocateElemLinkList(LinkList L, ElemType e) {
	// 在链表L中查找值为 e 的元素
	// 若找到，则返回L中值为e的元素的地址；否则返回NULL
	
	LNode *p;
	// p指向第一个结点
	p = L -> next;
	
	while(p && p->data != e) {
		p = p -> next;
	} 
	// 如果找到了，则p为元素的地址；如果未找到，则p已经到表尾，其值为NULL 
	return p;
}


int main(){
	LinkList L;

	return 0;
}
