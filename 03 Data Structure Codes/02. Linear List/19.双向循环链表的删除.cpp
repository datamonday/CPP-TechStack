int a[] 

// 删除带头结点的双向循环链表L的第i个元素，并用e返回 
int DeleteElemDLinkList(DLinkList &L, int i, ElemType &e){
	if(!( p = GetElemP_DLinkList(L, i) )) {
		return ERROR;
	}
	else{
		// 将待删除结点的数据域赋值给e 
		e = p -> data;
		// 1. 将前一个结点的next域指向待删除结点的下一个结点 
		p -> prior -> next = p -> next;
		// 2. 将待删除结点的下一个结点的prior域指向前一个结点
		p -> next -> prior = p -> prior; 
		// 3.释放被删除结点的空间
		free(p); 
	}
	return OK; 
} 


