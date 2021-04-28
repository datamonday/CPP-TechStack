# include <stdio.h>

int main(){
	int var_x = 10;
	int *p;
	
	p = &var_x;
	
	printf("var_x 变量的地址为：%p\n", p);
	
	return 0;
}
