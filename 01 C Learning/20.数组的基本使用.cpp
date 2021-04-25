# include "stdio.h"

int main() {
	int n[10]; // n 是一个包含10个整数的数组
	int i, j;
	
	// 初始化数组元素 
	for (i = 0; i < 10; i++) {
		n[i] = i + 100; 
	} 
	
	// 输出数组中的元素
	for (j = 0; j < 10; j++) {
		printf("Element[%d] = %d\n", j, n[j]);
	} 
	
	return 0;
} 
