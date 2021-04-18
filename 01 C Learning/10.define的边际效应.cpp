# include "stdio.h"

# define N1 2+3
# define N2 (2+3)

int main() {
	double a1, a2;
	a1 = (float)N1 / (float)2;
	a2 = (float)N2 / (float)2;
	
	printf("N1 = %lf \n", a1);
	printf("N2 = %lf \n", a2);
}
