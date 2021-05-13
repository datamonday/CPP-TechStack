# include "stdio.h"

#define LONG 10
#define WIDTH 20

int main() {
	const int l = 10;
	const int w = 20;
	const char NEWLINE = '\n';
	int area1, area2;
	
	area1 = l * w;
	area2 = LONG * WIDTH;
	
	printf("value of area1 = %d", area1);
	printf("%c", NEWLINE);
	
	printf("value of area2 = %d", area2);
	printf("%c", NEWLINE);
}
