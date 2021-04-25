# include "stdio.h"

int main(){
	double balance[5] = {450, 85, 90, 140, 135};
	double *p;
	int i;
	
	// 数组balance的第一个元素的地址 赋给变量p 
	p = balance;
	
	for (i=0; i < 5; ++i){
		printf("* (p + %d) : %.10lf\n", i, *(p + i));
	} 
	printf( "使用 balance 作为地址的数组值\n");
	for ( i = 0; i < 5; i++ ){
		printf("*(balance + %d) : %f\n",  i, *(balance + i) );
	}
	return 0;
} 
