# 18. 其它知识

## 18.1 位域

如果程序的结构中包含多个开关量，只有 **TRUE/FALSE** 变量，如下：

```c
struct
{
  unsigned int widthValidated;
  unsigned int heightValidated;
} status;
```

这种结构需要 8 字节的内存空间，但每个变量只存储 0 或 1。在这种情况下，C 语言提供了一种更好的利用内存空间的方式。如果在结构体内使用这样的变量，可以定义变量的宽度来告诉编译器。例如，上面的结构可以重写成：

```c
struct
{
  unsigned int widthValidated : 1;
  unsigned int heightValidated : 1;
} status;
```

现在，上面的结构中，status 变量将占用 4 个字节的内存空间，但是只有 2 位被用来存储值。如果用了 32 个变量，每一个变量宽度为 1 位，那么 status 结构将使用 4 个字节，但只要再多用一个变量，比如使用33 个变量，那么它将分配内存的下一段来存储第 33 个变量，这个时候就开始使用 8 个字节。

```c
#include <stdio.h>
#include <string.h>
 
/* 定义简单的结构 */
struct
{
  unsigned int widthValidated;
  unsigned int heightValidated;
} status1;
 
/* 定义位域结构 */
struct
{
  unsigned int widthValidated : 1;
  unsigned int heightValidated : 1;
} status2;
 
int main( )
{
   printf( "Memory size occupied by status1 : %d\n", sizeof(status1));
   printf( "Memory size occupied by status2 : %d\n", sizeof(status2));
 
   return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```c
Memory size occupied by status1 : 8
Memory size occupied by status2 : 4
```

<font color=blue>**有些信息在存储时，并不需要占用一个完整的字节，而只需占几个或一个二进制位**。例如在存放一个开关量时，只有 0 和 1 两种状态，用 1 位二进位即可。**为了节省存储空间，并使处理简便**，C 语言又提供了一种数据结构，称为**位域** 或 **位段**。</font>

<font color=blue>**位域**：把一个字节中的二进位划分为几个不同的区域，并说明每个区域的位数。每个域有一个域名，允许在程序中按域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。</font>

典例：

- 用 1 位二进位存放一个开关量时，只有 0 和 1 两种状态。
- 读取外部文件格式——可以读取非标准的文件格式。例如：9 位的整数。

位域定义与结构定义体类似：

```c
struct 位域结构名 
{

 位域列表

};
```

其中位域列表的形式为：

```c
type [member_name] : width ;
```

下面是有关位域中变量元素的描述：

| 元素        | 描述                                                         |
| :---------- | :----------------------------------------------------------- |
| type        | 只能为 int(整型)，unsigned int(无符号整型)，signed int(有符号整型) 三种类型，决定了如何解释位域的值。 |
| member_name | 位域的名称。                                                 |
| width       | 位域中位的数量。宽度必须小于或等于指定类型的位宽度。         |

带有预定义宽度的变量被称为**位域**。位域可以存储多于 1 位的数，例如，需要一个变量来存储从 0 到 7 的值，可以定义一个宽度为 3 位的位域：

```c
struct
{
  unsigned int age : 3;
} Age;
```

上面的结构定义指示 C 编译器，age 变量将只使用 3 位来存储这个值，如果试图使用超过 3 位，则无法完成。

```c
struct bs{
    int a:8;
    int b:2;
    int c:6;
}data;
```

data 为 bs 变量，共占两个字节。其中位域 a 占 8 位，位域 b 占 2 位，位域 c 占 6 位。

```c
struct packed_struct {
  unsigned int f1:1;
  unsigned int f2:1;
  unsigned int f3:1;
  unsigned int f4:1;
  unsigned int type:4;
  unsigned int my_int:9;
} pack;
```

packed_struct 包含了 6 个成员：四个 1 位的标识符 f1..f4、一个 4 位的 type 和一个 9 位的 my_int。

```c
#include <stdio.h>
#include <string.h>
 
struct
{
    unsigned int age : 3;
} Age;
 
int main( )
{
    // age 变量用 3 位来存储这个值，如果超过 3 位，则无法完成
    Age.age = 4;
    printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
    printf( "Age.age : %d\n", Age.age );
   
    // 二进制表示为 111 有三位，达到最大值
    Age.age = 7;
    printf( "Age.age : %d\n", Age.age );
 
    Age.age = 8; // 二进制表示为 1000 有四位, 超出, 直接丢掉, 存不进去

    printf( "Age.age : %d\n", Age.age );
 
    return 0;
}
```

上面的代码被编译时，带有警告，执行上面的代码：

```
Sizeof( Age ) : 4
Age.age : 4
Age.age : 7
Age.age : 0
```

<font color=red>**从以上分析可以看出，位域在本质上就是一种结构类型，不过其成员是按二进位分配的**。</font>

位域的使用和结构成员的使用相同，其一般形式为：

```c
位域变量名.位域名
位域变量名->位域名
```

位域允许用各种格式输出。

```c
int main(){
    struct bs{
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    } bit,*pbit;
    
    bit.a=1;   // 给位域赋值（应注意赋值不能超过该位域的允许范围）
    bit.b=7;   // 给位域赋值（应注意赋值不能超过该位域的允许范围）
    bit.c=15;  // 给位域赋值（应注意赋值不能超过该位域的允许范围）
    // 以整型格式输出三个域的内容
    printf("%d,%d,%d\n", bit.a, bit.b, bit.c);
    // 把位域变量 bit 的地址送给指针变量 pbit
    pbit=&bit;
    // 用指针方式给位域 a 重新赋值，赋为 0
    pbit -> a = 0;
    /* 复合位运算符 "&=" 相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit -> b &= 3;
    /* 复合位运算符 "|=" 相当于：pbit->c=pbit->c|1，其结果为 15 */
    pbit->c|=1;
    // 用指针方式输出了这三个域的值
    printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);
}
```

上例程序中定义了位域结构 bs，三个位域为 a、b、c。说明了 bs 类型的变量 bit 和指向 bs 类型的指针变量 pbit。这表示位域也是可以使用指针的。

## 18.2 强制类型转换（待补充）





## 18.3 错误处理（待补充）





## 18.4 可变参数（待补充）





## 18.5 命令行参数（待补充）





## 18.6 递归（待补充）






---

> 参考：
>
> 1. 翁凯 《C 语言程序设计》
> 2. [郝斌C语言自学教程（video）](https://www.bilibili.com/video/BV1os411h77o?p=12)
> 3. [C语言程序设计教程（video）](https://www.bilibili.com/video/BV1q54y1q79w?from=search&seid=9645914219204074845)
> 4. [C语言教程（page）](https://www.runoob.com/cprogramming/c-basic-syntax.html)
> 5. [C指针详解](https://www.runoob.com/w3cnote/c-pointer-detail.html)
> 6. [C语言中文网（page）](http://c.biancheng.net/view/1760.html)
> 7. 《C Primer Plus》