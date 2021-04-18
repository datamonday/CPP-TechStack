# include "stdio.h"

int main() {
	int i = 408;
	// [Warning] overflow in implicit constant conversion [-Woverflow] 
	long j = 9090145145;
	i = j;
	
	// Êä³ö£º500210553, 500210553 
	printf("%ld, %d \n", i, j);
	
	float x = 3.14;
	double y = 6.28;
	
	// Êä³ö£º3.140000, 6.280000 
	printf("%f, %lf \n", x, y);
}
