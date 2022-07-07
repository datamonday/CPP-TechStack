#include "stdio.h"
#include "limits.h"  // sizeof 函数所在的库
#include "float.h"

int main() {
	printf("char  类型的存储大小：%lu 字节(Byte)\n", sizeof(char));
	printf("int   类型的存储大小：%lu 字节(Byte)\n", sizeof(int));
	printf("short 类型的存储大小：%lu 字节(Byte)\n", sizeof(short));
	printf("long  类型的存储大小：%lu 字节(Byte)\n", sizeof(long));
	printf("-----------------------------------\n");
	
	printf("float  类型的存储大小：%lu 字节(Byte)\n", sizeof(float));
	printf("double 类型的存储大小：%lu 字节(Byte)\n", sizeof(double));
	printf("-----------------------------------\n");
	
	// %E 为以指数形式输出单、双精度实数
	printf("float  类型存储的最大字节数：%lu 字节\n", sizeof(float));
	printf("float  类型的最小值：%E \n", FLT_MIN);
	printf("float  类型的最小值：%E \n", FLT_MAX);
	printf("精度值：%d \n", FLT_DIG);
}



