#include <stdio.h>


int func(int x, int y){
    return x + y;
} 

int main(){
	int (*pfunc) (int, int);
	
	pfunc = func;
	// pfunc = &func;
	// &func 与 func 的值和类型都一样，二者均可 
	
	/* 以下几种调用方式的结果均相同*/ 
	// 通过 函数指针 调用函数 
	int a = (*pfunc) (5, 7);	
	int b = pfunc(5, 7);
	int c = (&func) (5, 7);
	int d = (*func) (5, 7);
	int e = func(5, 7);
	
	printf("results of different ways: %d, %d, %d, %d, %d", a, b, c, d, e);
	
	return 0;
}
