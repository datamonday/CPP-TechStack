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


// 单链表的删除 
Status DeleteElemLinkList(LinkList &L, int i, ElemType &e) {
	LNode *p;
	p = L;
	int j = 0;
	
	// 寻找位置为 i-1 的结点，p指向该结点
	while(p -> next && j < i-1){
		p = p -> next;
		++j;
	} 
	
	// i大于表长+1或小于1，删除位置不合理 
	if (!(p -> next) || j >= i){
		return ERROR;
	}
	
	// 临时保存被删除结点的地址以备释放
	LNode *q;
	q = p -> next;
	// 改变删除节点前驱结点的指针域
	p -> next = q -> next;
	// 保存删除结点的数据域
	e = q -> data;
	// 释放删除结点的空间
	free(q);
	
	return OK;
}


int main(){
	LinkList L;

	return 0;
}
