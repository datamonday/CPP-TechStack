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


// 单链表的插入 
Status InsertElemLinkList(LinkList &L, int i, ElemType e) {
	LNode *p;
	p = L;
	int j = 0;
	
	// 寻找第 i-1 个结点，p指向该结点
	while(!p || j < i-1){
		p = p -> next;
		++j;
	} 
	
	// i大于表长+1或小于1，插入位置非法 
	if (!p || j >= i){
		return ERROR;
	}
	
	// 生成新结点s，将s的数据域置为e
	LNode *s;
	s -> data = e;
	// 将结点s插入到L中，以下语句的顺序不能调换！ 
	s -> next = p -> next;
	p -> next = s; 
	
	return OK;
}


int main(){
	LinkList L;

	return 0;
}
