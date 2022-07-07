# include "stdio.h"

int main() {
	int a[3][2] = { {1,2}, {4,5}, {7,8}	};
	int i, j;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("a[%d][%d] = %d\n", i, j, a[i][j]);
		}
	}
    for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
            // 另一种格式化输出方式
            // - 表示左对齐
            printf("%-5d  ", a[i][j]);
		}
        printf("\n");
	}
	return 0; 
} 
