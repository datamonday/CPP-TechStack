# include "stdio.h"

int main() {
	int a = 12345;
	float b = 3.1415926535;
	double c = 1.732;
	char d = 'x';
//	char *e = "abcde";
	char e[] = "abcde";
	
	printf("int a = %d \n", a);
	printf("short int a = %hd \n", a);
	printf("long int a = %ld \n", a);
	printf("-------------------- \n");
	
	printf("float b = %f \n", b);
	printf("4 bit 2 decimal of b = %4.2f \n", b);
	printf("-------------------- \n");
	
	printf("double c = %lf \n", c);
	printf("-------------------- \n");
	
	printf("char d = %c \n", d);
	printf("-------------------- \n");
	
	printf("string e = %s \n", e);
	
}
