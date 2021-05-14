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
// 其将指向结构体的指针打包定义了 


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


// 销毁单链表 
Status DestroyLinkList(LinkList &L){
	// 只想需要删除的结点 
	LNode *p;  // LinkList p 
	
	// 没到表尾
	while(L != NULL){
		// 即p指向L（将头结点的指针赋值给p），目的是把头结点一块删除。
		p = L;
		L = L -> next;
		free(p);
	}
} 


int main(){
	LinkList L;
	InitLinkList(L);

	return 0;
}
