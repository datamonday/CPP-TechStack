# include <stdio.h>
# include <stdlib.h>

# define ERROR -1
# define OK     1

typedef int Status;	   // 定义别名 
typedef int ElemType;  // 定义别名 

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

Status InitialLinkList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL){
		printf("申请内存空间失败！\n");
    }
    // 单向循环链表的空表表示: 头结点的指针域指向头指针 
	L -> next = L;
	
	return OK;
}


// 时间复杂度为 O(1)
LinkList ConnectLinkList (LinkList Ta, LinkList Tb){
    // 假设Ta Tb均为非空的单向循环链表
    // (1) p保存表Ta的头结点
    LNode *p;
    p = Ta -> next;
    // (2) Tb表头链接到Ta的表尾
    Ta -> next = Tb -> next -> next;
    // (3) 释放Tb表头结点
    free(Tb -> next);
    // (4) 修改指针
    Tb -> next = p;
}

Status printLinkList(LNode *head){
    LNode *p = head;
    while(p -> next != head) {
        p = p -> next;
        printf("%d", p -> data);
    }
    printf("\n");
    
    return OK;
}

Status main(){
	return OK;
}

