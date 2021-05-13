# include <stdio.h>

const int MAX = 3;

int main() {
	int var[] = {10, 100, 200};
	int i, j, *ptr;
	
	ptr = var;
	i = 0;
	while(ptr <= &var[MAX - 1]) {
		printf("存储地址： var[%d] = %p\n", i, ptr);
		printf("存储值  ： var[%d] = %d\n", i, *ptr);
		
		// 指向下一个位置 
		ptr ++;
		i ++;
	} 
	return 0;
}
