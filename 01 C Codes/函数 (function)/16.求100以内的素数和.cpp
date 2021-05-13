# include "stdio.h"
# include "math.h"

int is_prime(int x);

int main() {
	int i, rst;
	int sum = 0;
	
	for (i=2; i <= 100; i++){
//		printf("%d \n", i);
		rst = is_prime(i);
//		printf("%d \n", rst);
		if (rst == 1){
			sum += i;
		}
		
		else {
			continue;
		}
	}
	
	printf("100以内的素数和为：%d", sum);
} 

int is_prime(int x) {
	
	int j;
	int k;
	
	if (x <= 1) {
		return 0;
	}
	
	else if (x == 2){
		return 1;
	}
	
	else {
		k = (int)sqrt((double)x);
		
		for (j=2; j <= k; j++){
			if (x % j == 0){
				break;
			}
		}
		if (j > k) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

