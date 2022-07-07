

// 在带头结点的双向循环链表L中的第i个位置之前插入元素e 
int InsertDLinkList(DLinkList &L, int i, ElemType e){
	// 查找插入位置p
	if(!( p = GetElemP_DLinkList(L, i) )){
		return ERROR;
	} 
	else{
		// 为待插入结点分配内存空间 
		DLNode *s;
		s -> data = e;
		// 1. 将待插入结点s的prior域 指向 前一个结点 
		s -> prior = p -> prior;
		// 2. 将前一个结点的next域 指向 待插入结点 
		p -> prior -> next = s;
		// 3. 将待插入结点的next域 指向 下一个结点 
		s -> next = p;
		// 4. 将下一个结点的prior域 指向 待插入结点 
		p -> prior = s;
	}
} 
