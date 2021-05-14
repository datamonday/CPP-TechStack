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



// 求单链表的表长
// 不需要对链表操作，所以传值调用即可，不需要引用 &L
// 返回单链表中元素的个数。
Status LengthLinkList(LinkList L){
	// 只想需要删除的结点 
	LNode *p;  // LinkList p;
	// p 指向第一个结点 
	p = L -> next;
	
	int i = 0;
	 
	// 遍历单链表，统计结点数 
	while(p != NULL){
		i++; 
		p = p -> next;
	}
	// 返回链表L中数据元素的个数
	// i初值为0，此处不为i+1，是因为最后一次while循环时 i已经加1了 
	return i; 
}


int main(){
	LinkList L;

	return 0;
}
