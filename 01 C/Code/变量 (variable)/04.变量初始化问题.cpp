# include "stdio.h"

//int main() {
//	int a, b, c, d;
// // 输出：a = 0, b = 1, c = 0, d = 0 
//	printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);
//} 

// 输出： a = 1, b = 11805632, c = 11815904, d = 0
int main(int a, int b, int c, int d) {
	printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);
} 

/*
变量如果未初始化，则会使用存放在内存中的垃圾值（上次使用内存，残留在内存中的值，不确定）； 

某些IDE会用填充字代替垃圾值！
 
初始化相当于给对应的内存空间赋值，变量指向该内存空间，也就被初始化了。 

程序运行完之后，操作系统回收内存空间，但并不会清空内存空间中遗留下来的数据。 
*/
