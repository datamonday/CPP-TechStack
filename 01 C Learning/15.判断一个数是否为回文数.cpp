# include "stdio.h"
# include "string.h"

int main() {
	char a[100];
	int n, i, j; 
	printf("请输入字符(<100位)：%s \n", a);
	scanf("%s", &a); 
	
	// 字符串长度
	n = strlen(a);
	
	for (i=0, j=n-1; i < j; i++, j--) {
		if (a[i] != a[j]){
			break;
		}
	} 
	
	// i - j == 1 是判断为偶数对称的情况，如 1221 ，i=1，j=2时会继续加减，i=2，j=1 
	if (i == j || i-j==1) {
		printf("%s 是回文数！", a);
	}
	else {
		printf("%s 不是回文数！", a);
	} 
}
