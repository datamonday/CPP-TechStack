# include <stdio.h>
# include <stdlib.h>

# define ERROR -1
# define OK     1

typedef int Status;	   // 定义别名 
typedef int ElemType;  // 定义别名 


typedef struct DLNode{
    ElemType data;
    struct DLNode *prior, *next;
}DLNode, *DLinkList;


int main(){
	return OK;
}
