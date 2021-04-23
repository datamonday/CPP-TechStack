/*
fputs() 函数用来显示字符串：

# include <stdio.h>
int fputs(const char *s, FILE *stream);

	- param s: 要输出的字符串的首地址，可以是字符数组名或字符指针变量名。
	- param stream: 向何种流中输出，可以是标准输出流 stdout，也可以是文件流。
	                标准输出流即屏幕输出，printf 其实也是向标准输出流中输出的。
	                
----
- 18.删除原程序注释并添加行号 18.1234可以组成多少位无重复三位数.cpp 18.cpp
 
*/


# include "stdio.h"
# include "stdlib.h"
# include "string.h"

# define MAXLINE 99

void del_anno_add_rows(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[]) {
	
	FILE *fp1, *fp2;
	
	// 检查命令行参数
	if (argc != 3) {
		printf("You must pass three args!\nLike: c source filename filename1.c filename2.c \n");
		exit(1);
	}
	// 打开文件
	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s \n", argv[1]);
		exit(1);
	}
	
	if ((fp2 = fopen(argv[2], "w")) == NULL) {
		printf("Can't open %s \n", argv[2]);
		exit(1);
	}
	
	del_anno_add_rows(fp1, fp2);
	
	fclose(fp1);
	fclose(fp2); 
}

void del_anno_add_rows(FILE *fp1, FILE *fp2) {
	char str1[MAXLINE]="", str2[MAXLINE]="";
	int i, j, no=0;
	// 定义行号 
	int ln=1;
	
	while (fgets(str1, MAXLINE, fp1) != NULL) {
		for (i=0; i < MAXLINE; i++){
			// 遇到注释 // 
			if (str1[i] == '/' && str1[i-1] == '/') {
				str1[i - 1] = '\n';
				str1[i] = '\0';
			}
			// 遇到注释 /* 
			if (str1[i] == '*' && str1[i-1] == '/') {
				str1[i-1] = '\0';
				no = 1;
				// fputs(str1, fp2);
				fprintf(fp2, "[%2d]", ln);
				fputs(str1, fp2);
				ln++;
			}
			// 遇到注释 */ 
			if (str1[i] == '/' && str1[i-1] == '*') {
				for (j=0; j < 98-i; j++) {
					str1[j] = str1[i + j + 1];
					str1[j] = '\0';
					no = 0;
				} 
			}
		}
		if (no == 0) {
			// fputs(str1, fp2);
			fprintf(fp2, "[%2d]", ln);
			fputs(str1, fp2);
			ln++;
		}	
	}
}

