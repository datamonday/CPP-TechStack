# include <stdio.h>
# include <time.h>
# include <stdlib.h>

// 注意星号运算符 
int * get_random(){
	static int r[10];
	int i;
	
	// 设置种子
	srand( (unsigned) time ( NULL) );
	for(i=0; i<10; ++i){
		r[i] = rand();
		printf("r[%d] = %d\n", i, r[i]);
	} 
	return r;
}


int main(){
	
	// 定义一个指向整数的指针
	int *p;
	int i;
	
	p = get_random();
	for (i=0; i<10; i++)
	{
		printf("*(p + [%d]) : %d\n", i, *(p + i) );
	} 
	return 0;
} 





