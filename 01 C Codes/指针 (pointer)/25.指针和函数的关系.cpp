#include <stdio.h>
#include <stdlib.h>

void test( ){
    printf(" func test called!\n");
}

int max_of_three(int x, int y, int z){
	int max;
	
	max = z;
	
	if (x > y){
		max = x;
	}
	else{
		if (y > z){
			max = y;
		}
	}
	return max;
} 

int main() {
    /* ---------------------------测试1-------------------------*/
    void (*f) ();
    f = test;
    
    f ();    // 函数调用方式 1
    (*f)();  // 函数调用方式 2
    
    printf("  test = %p\n",  test);
    printf(" &test = %p\n", &test);
    printf(" *test = %p\n", *test);
	
	printf("-------------------------------\n");
    /* ---------------------------测试2-------------------------*/
	// 定义一个函数指针
	int (*p)(int, int, int);
	int a, b, c, result;
	
	// 把函数max_of_three赋值给变量p, 使p指向函数
	p = max_of_three;
	
	// 非法操作： 
	// max_of_three ++;   // 禁止对指向函数的指针进行自增运算 
	// max_of_three += 1; // 不能对函数名赋值，函数名也不能进行算术运算 
	// p ++;
	// p += 1;
	
	printf("please enter three variable:");
	scanf("%d %d %d", &a, &b, &c);
	printf("you entered: a = %d, b = %d, c = %d\n", a, b, c);
	result = (*p)(a, b, c);
	printf("the maximum is: %d\n", result);
	
	system("pause");
	
	return 0;
}
