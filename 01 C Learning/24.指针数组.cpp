# include <stdio.h>

const int MAX = 5;

int main() {
	int var[] = {1,2,3,4,5};
	
	// 1.声明指针数组 
	int i, *ptr[MAX];
	
	// 2.为数组ptr中的元素赋值 
	for(i=0; i<MAX; i++){
		// 赋值为整数的地址 
		ptr[i] = &var[i]; 
	} 
	
	// 3.遍历打印 数组中的指针对应的值 
	for(i=0; i<MAX; i++){
		printf("Value of var[%d] = %d\n", i, *ptr[i]);
	}
	return 0;
}
