---
> Contributor: datamonday
>
> Repo: https://github.com/datamonday/CPP-TechStack

---
---

# 8. 函数

C——面向过程语言。

函数是一组一起执行一个任务的语句。每个 C 程序都至少有一个函数，即主函数 **main()** 。

函数**声明**告诉编译器函数的名称、返回类型和参数。函数**定义**提供了函数的实际主体。

## 8.1 定义函数

C 语言中的函数定义的一般形式如下：

```c
return_type function_name( parameter list )
{
   body of the function
}
```

在 C 语言中，函数由一个函数头和一个函数主体组成。下面列出一个函数的所有组成部分：

- **返回类型：**一个函数可以返回一个值。**return_type** 是函数返回的值的数据类型。有些函数执行所需的操作而不返回值，在这种情况下，return_type 是关键字 **void**。
- **函数名称：**这是函数的实际名称。函数名和参数列表一起构成了函数签名。
- **参数：**参数就像是占位符。当函数被调用时，向参数传递一个值，这个值被称为实际参数。参数列表包括函数参数的类型、顺序、数量。参数是可选的，也就是说，函数可能不包含参数。
- **函数主体：**函数主体包含一组定义函数执行任务的语句。

以下是 **max()** 函数的源代码。该函数有两个参数 num1 和 num2，会返回这两个数中较大的那个数：

```c
/* 函数返回两个数中较大的那个数 */
int max(int num1, int num2) 
{
   /* 局部变量声明 */
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
```

---

## 8.2 函数声明

函数**声明**会告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。

函数声明包括以下几个部分：

```c
return_type function_name( parameter list );
```

针对上面定义的函数 max()，以下是函数声明：

```c
int max(int num1, int num2);
```

**在函数声明中，只有参数的类型是必需的**，因此下面也是有效的声明：

```c
int max(int, int);
```

**当在一个源文件中定义函数且在另一个文件中调用函数时，函数声明是必需的**。在这种情况下，应该**在调用函数的文件顶部声明函数**。

### 1）内部函数（静态函数）

如果一个函数只能被本文件中其他函数所调用，它称为内部函数。在定义内部函数时，在函数名和函数类型的前面加 `static`，即

```c
static 类型名 函数名 （形参表）
```

例如，函数的首行：

```c
static int max(int a,int b)
```

内部函数又称静态函数。使用内部函数，可以使函数的作用域只局限于所在文件。即使在不同的文件中有同名的内部函数，也互不干扰。提高了程序的可靠性。

---

### 2）外部函数

如果在定义函数时，在函数的首部的最左端加关键字 extern，则此函数是外部函数，可供其它文件调用。

如函数首部可以为

```c
extern int max (int a,int b)
```

C 语言规定，如果在定义函数时省略 `extern`，则默认为外部函数。

## 8.3 调用函数

当程序调用函数时，程序控制权会转移给被调用的函数。被调用的函数执行已定义的任务，当函数的返回语句被执行时，或到达函数的结束括号时，会把程序控制权交还给主程序。

调用函数时，传递所需参数，如果函数返回一个值，则可以存储返回值。例如：

```c
#include <stdio.h>
 
/* 函数声明 */
int max(int num1, int num2);
 
int main ()
{
   /* 局部变量定义 */
   int a = 100;
   int b = 200;
   int ret;
 
   /* 调用函数来获取最大值 */
   ret = max(a, b);
 
   printf( "Max value is : %d\n", ret );
 
   return 0;
}
 
/* 函数返回两个数中较大的那个数 */
int max(int num1, int num2) 
{
   /* 局部变量声明 */
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
```

## 8.4 函数传参

如果函数要使用参数，则必须声明接受参数值的变量。这些变量称为函数的**形式参数**。

**形式参数就像函数内的其他局部变量，在进入函数时被创建，退出函数时被销毁**。

当调用函数时，有两种向函数传递参数的方式：

| 调用类型                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [传值调用](https://www.runoob.com/cprogramming/c-function-call-by-value.html) | 该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数不会影响实际参数。 |
| [引用调用](https://www.runoob.com/cprogramming/c-function-call-by-pointer.html) | 通过指针传递方式，形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。 |

<font color=red>默认情况下，C 使用**传值调用**来传递参数。这意味着函数内的代码不能改变用于调用函数的实际参数。</font>

### 1）值传参

示例程序均以交换两个整数为例。

```c
#include <stdio.h>

void swap(int x, int y);

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main( int argc, char *argv[] )
{
    int a = 5;
    int b = 10;
    swap(a, b); //调用交换函数
    printf("交换结果为 a = %d, b = %d\n", a, b);
    return 0;
}
```

由于值传递是单向传递，传递过程中只是改变了形参的数值，并未改变实参的数值，因此并不会改变a和b原有的值。

### 2）指针传参

```c
#include <stdio.h>

void swap(int *x, int *y);

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main( int argc, char *argv[] )
{
    int a = 5;
    int b = 10;
    swap(&a, &b); //调用交换函数
    printf("交换结果为 a = %d, b = %d\n",a,b);
    return 0;
}
```

指针传递过程中，将a和b的地址分别传递给了x和y，在函数体内部改变了a、b所在地址的值，即交换了a、b的数值。

本质上说，C 里面所有的函数参数传递，都是值传递。

**指针传递之所以能改变传递参数变量的值，是因为 swap 函数交换的不是传递进来的指针本身，而是指针指向的值**。

### 3）引用传参（C++）

```c
#include <stdio.h>

void swap(int &x, int &y);
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main( int argc, char *argv[] )
{
    int a = 5;
    int b = 10;
    swap(a, b); //调用交换函数
    printf("交换结果为 a = %d, b = %d\n",a,b);
    return 0;
}
```

引用传递中，在调用swap(a, b);时函数会用a、b分别代替x、y，即x、y分别引用了a、b变量，这样函数体中实际参与运算的其实就是实参a、b本身，因此也能达到交换数值的目的。

**注：**严格来说，C语言中是没有引用传递，这是C++中语言特性，因此在.c文件中使用引用传递会导致程序编译出错。

---

### 4）main函数的参数

在有些很专业的书会看到如下代码：

```c
int main( int argc, char *argv[] )
```

上面的代码中 main 函数带了参数。

但是有时又会看见main函数没有参数，如下：

```c
int main()
```

**那么 main 函数到底有没有参数，有没有参数会不会有什么影响？**

main 函数其实与我们写的函数没有什么区别，它也会有自己的参数。

argc 和 argv 是 main 函数的形式参数。

这两个形式参数的类型是系统规定的。如果 main 函数要带参数，就是这两个类型的参数；否则main函数就没有参数。

变量名称argc和argv是常规的名称，当然也可以换成其他名称。在传入参数后main函数收到参数后就会做自己的事。那么，实际参数是如何传递给main函数的argc和argv的呢？C程序在编译和链接后，都生成一个exe文件，执行该exe文件时，可以直接执行；也可以在命令行下带参数执行，命令行执行的形式为：`可执行文件名称 参数1 参数2 ... ... 参数n`。可执行文件名称和参数、参数之间均使用空格隔开。

如果按照这种方法执行，命令行字符串将作为实际参数传递给main函数。具体为：

-  1) 可执行文件名称和所有参数的个数之和传递给 argc；
-  2) 可执行文件名称（包括路径名称）作为一个字符串，首地址被赋给 argv[0]，参数1也作为一个字符串，首地址被赋给 argv[1]，... ...以此类推。

---

## 8.5 函数实例（待补充）

### 1）求三个数中的最大值

```c
# include "stdio.h"

int max_of_three(int a, int b, int c); 

int main() {
	int x, y, z, result;
	
	printf("请输入三个数字（以空格分隔）：\n");
	scanf("%d%d%d", &x, &y, &z);
	
	result = max_of_three(x, y, z);
	printf("最大值为：%d \n", result);
	
	return 0;
} 


int max_of_three(int a, int b, int c) {
	int max = a;
	
	if (b > max) {
		max = b;
		if (c > max) {
			max = c;
		}
	}
	else {
		if (c > max) {
			max = c;
		}
	}
	return max;
}
```

### 2）判断一个数是否为素数

```c
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
```

### 3）判断一个数字是否为回文数

```c
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
```

### 4）打印输出一百以内的素数

```c
#include<stdio.h>
#include<math.h>

int main(){
    int i,j;
    for(i=2;i<100;i++){
        for(j=2;j<sqrt(i);j++){
            if(i%j==0){
                break;
                }
            }
            if(j>sqrt(i)){
                printf("%d,\t",i);
            }
        }
    }

/* -------------------- 法2 ---------------------*/
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
```

第一个循环：i遍历从2到100以内的所有数字；第二个循环：判断在2到sqrt(n)是否可以整除i，可以整除则不是素数，反之是素数。

### 5）求一个十进制数的二进制





### 6）求一个数字倒过来的数字





### 7）求一个数的奇数位组成的新数





---

### 8） 求一百以内的奇数偶数和





---