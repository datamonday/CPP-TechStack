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

// 前插法建立单链表 
// 时间复杂度为O(n)
LinkList HeadCreateLinkList(int n)
{
    LinkList L;
	InitLinkList(L);
	
    ElemType x;
    for (int i=n; i > 0; --i)
    {
    	printf("Please input linklist element[%d]:\n", i);
    	
    	scanf("%d", &x);
        LNode *p;
        p = (LNode *)malloc(sizeof(LNode));
        p -> data = x;
        
        p -> next = L -> next;
        L -> next = p;
    }
    return L;
}


int main(){
	LinkList L, start;
	InitLinkList(L);
	
	int n;
	printf("Please input number of linklist element:\n");
	scanf("%d", &n);
	
    L = HeadCreateLinkList(n);
    for (start = L->next; start != NULL; start = start->next){
    	printf("%d \t", start->data);
	}

	return 0;
}
