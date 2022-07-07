# include "stdio.h"
# include "math.h"

int is_prime(int x);

int main() {
	int x;
	
	printf("请输入要判断的数：\n");
	scanf("%d", &x);
	is_prime(x);
}

int is_prime(int x) {
	int sqrt_x; 
	int i; // 循环次数 
	
	if (x <= 1) {
		return 0;
	}
	else if (x == 2) {
		return 1;
	}
	else {
		// sqrt()的参数为 double 类型，这里要强制转换m的类型
		sqrt_x = (int)sqrt((double)x);
		
		printf("sqrt_x = %d\n", sqrt_x);
		
		for (i=2; i<=sqrt_x; i++) {
			printf("i = %d \n", i);
			if (x % i == 0) {
				break;
			} 
		} 
		// 如果完成循环则为复数
		// 最后一次循环，会执行 i++, 此时 i = k+1, 所以 i>k 
		if (i > sqrt_x) {
			printf("%d 是素数！\n", x);
		} 
		else {
			printf("%d 不是素数！", x);
		}
	}
} 
