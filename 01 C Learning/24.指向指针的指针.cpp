# include <stdio.h>

int main(){
	int var = 408;
	int *ptr1;
	int **ptr2;
	
	// 获取 var 的地址
	ptr1 = &var;
	 
	ptr2 = &ptr1;
	
	printf("var = %d\n", var);
	printf("(  ptr1) address of ptr1 = %p\n",   ptr1);
	printf("( *ptr1) value   of ptr1 = %d\n",  *ptr1);
	
	printf("(  ptr2) address of ptr2 = %p\n",   ptr2);
	printf("(**ptr2) value   of ptr2 = %d\n", **ptr2);
	
	
	return 0;
}
