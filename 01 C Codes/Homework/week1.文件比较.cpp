/*
gets()函数的缺陷：不检查预留存储区是否能够容纳实际输入的数据。
即如果输入字符数目大于数组的长度，gets无法检测到这个问题，会发生内存越界。 

fgets() 比 gets() 安全，也更常用，其包含三个参数：

	char *fgets(char *s, int size, FILE *stream);

	- param s: 表示要保存到内存空间的首地址， 可以使字符数组名，也可以是指向字符数组的字符指针变量名。 
	- param size: 代表读取字符串的长度。 
	- param stream: 表示从何种流中输入，可以是标准输入流stdin，也可以是文件流。 

----

命令行使用：17.文件比较 filename1 filename2 

-- 17.文件比较 17.file1.txt 17.file2.txt 
	 
*/

# include "stdio.h"
# include "stdlib.h"
# include "string.h"


# define MAXLINE 80

// 声明 文件比较函数 
void filecamp(FILE *fp1, FILE *fp2);

// 定义主函数
/*
1.argc为整数
2.argv为指针的指针（char **argv or: char *argv[] or: char argv[][]，argv是一个指针数组）
	argv[0]指向输入的程序路径及名称。
    argv[1]指向参数para_1字符串。
    argv[2]指向参数para_2字符串。
*/ 
int main(int argc, char *argv[]){
	FILE *fp1, *fp2;
	
	// 检查命令行参数
	if (argc != 3) {
		printf("You must pass three args!\n Like: filecamp filename1 filename2 \n");
		exit(1);
	}
	// 打开文件
	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("Can't open %s \n", argv[1]);
		exit(1);
	} 
	if ((fp2 = fopen(argv[2], "r")) == NULL) {
		printf("Can't open %s \n", argv[2]);
		exit(1);
	} 
	
	// 比较文件
	filecamp(fp1, fp2);
	
	// 关闭文件
	fclose(fp1);
	fclose(fp2); 
}

// 比较两个文件第一个不同行
void filecamp(FILE *fp1, FILE *fp2)  {
	char line1[MAXLINE], line2[MAXLINE];
	char *lp1, *lp2;
	
	do{
		lp1 = fgets(line1, sizeof(line1), fp1);
		lp2 = fgets(line2, sizeof(line2), fp2);
		
		if (lp1 == line1 && lp2 == line2) {
			if (strncmp(line1, line2, MAXLINE) != 0) {
				printf("first difference line: \n file1: %s\n file2: %s\n", line1, line2);
			
			// 找到不同行，循环结束 
			lp1 = lp2 = NULL;
			}
		}
		
		else if (lp1 != line2 && lp2 == line2) {
			printf("end of file1.");
		}
		else if (lp1 == line2 && lp2 != line2) {
			printf("end of file2.");
		}
	} while (lp1 == line1 && lp2 == line2);
}




















