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
Status LocateElemLinkList(LinkList L, ElemType e) {
	LNode *p;
	p = L -> next;
	int j = 1;
	
	while(p && p -> data != e){
		p = p -> next;
		j++;
	}
	if (p != NULL){
		return j;
	}
	else{
		return 0;
	}
}


int main(){
	LinkList L;

	return 0;
}
