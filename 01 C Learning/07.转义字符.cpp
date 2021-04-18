# include "stdio.h"

int main() {
	// 以下两种表示方式等价
	char ch1 = '\101'; 
	char ch2 = 0101; 
	
	printf("字符 '\101' = %c \n",  ch1);
	printf("字符 0101 = %c \n",  ch2);
	
	char x1 = '\61';   // 字符 1
	char x2 = '\141';  // 字符 a 
	
	char x3 = '\x31';  // 字符 1
	char x4 = '\x61';  // 字符 a
	
//	char *str1 = "hello world";
//	char *str2 = "\x31 \x32 \x33";  // 字符串123 
	char str1[] = "hello world";
	char str2[] = "\x31 \x32 \x33";  // 字符串123 
	
	// 混用八进制和十六进制转义字符
//	char *str3 = "\61 \62 \63";  // 字符串123
	char str3[] = "\61 \62 \63";
	
	printf("字符 '\61' = %c \n",  x1);
	printf("字符 '\141' = %c \n", x2);
	printf("字符 '\x31' = %c \n", x3);
	printf("字符 '\x61' = %c \n", x4);
	
	printf("字符串 str1 = %s \n", str1);
	printf("字符串 str2 = %s \n", str2);
}
