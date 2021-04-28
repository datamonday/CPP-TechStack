# include "stdio.h"

int main(){
	/* 实际变量的声明
	   此时 VAR 变量存储了某个地址，该地址对应某个内存单元，这个单元中存储了数据10 
	*/ 
	int var = 10;
	
	/* 指针变量的声明
	   定义一个指针，即一个内存单元的地址变量 
	*/
	int *ip;
	
	/* 在指针变量中存储 var 的地址
	   将地址的值 赋值给指针变量 var 
	*/ 
	ip = &var;
	
	/* 在指针变量中存储的地址
	   &var 输出了 var 变量所存储的数据的内存单元的地址 
	*/
	printf("Address of var variable: %p\n", &var);
	
	/* ip 表示赋值变量的地址的值 */ 
	printf("Address stored in ip variable: %p\n", ip);
	
	/* 使用指针访问值 
	   *ip 表示定义内存单元后，内存单元中所存储的数据的值，本例中即为 10  
	*/ 
	printf("Value of *ip variable: %d\n", *ip);
	
	return 0;
} 
