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

// 初始化单链表 
Status InitLinkList(LinkList &L){
	// 从内存中找一块空间分配给LNode
	// LinkList 为取出这块空间的地址，并赋值给L 
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL){
		printf("申请内存空间失败！\n");
    }
	L -> next = NULL;
	return OK;
}


// 单链表的逆置——就地逆置 
LinkList LocalReverseLinkList(LinkList &L){
	if (L == NULL || L -> next == NULL){
		return L;
	}
	else{
		LNode *beg = L;
		LNode *end = L -> next;
	
		while(end != NULL){
			// 将 end 从链表中摘除
			beg -> next = end -> next;
			// 将 end 移动至链表头
			end -> next = L;
			L = end; 
			// 调整 end 的指向，令其指向 beg 后一个结点，为反转下一个结点做准备 
			end = beg -> next; 
		}
	} 
}


int main(){
	LinkList L;
	InitLinkList(L);
	LocalReverseLinkList(L);

	return OK;
}
