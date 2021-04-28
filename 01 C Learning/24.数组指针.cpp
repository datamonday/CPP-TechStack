# include <stdio.h>

const int MAX = 5;

int main() {
	int var[MAX] = {1,2,3,4,5};
	
	// 1.声明数组指针 
	int i, (*ptr)[MAX];
	
	// 2.将数组names的首地址赋值给指针ptr 
	ptr = &var;
	
	// 3. 遍历打印 
	for(i=0; i<MAX; i++){
		printf("Value of var[%d] = %d\n", i, var[i]);
	}
	return 0;
}
