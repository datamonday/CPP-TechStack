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

// 单链表的逆置——迭代反转 
LinkList IterReverseLinkList(LinkList &L){
	if (L == NULL || L -> next == NULL){
		return L;
	}
	else{
		LNode *beg = NULL;
		LNode *mid = L;
		LNode *end = L -> next;
	
		while(1){
			// 修改 mid 指针的指向
			mid -> next =beg;
			// 判断 end 是否为空（到达最后一个结点），如果成立则退出循环
			if (mid == NULL) {
				break;
			} 
			// 整体向后移动 3 的指针
			beg = mid;
			mid = end;
			end = end -> next; 
		}
		// 修改链表L头指针的指向
		L = mid; 
	} 
}


int main(){
	LinkList L;
	InitLinkList(L);
	IterReverseLinkList(L);

	return OK;
}
