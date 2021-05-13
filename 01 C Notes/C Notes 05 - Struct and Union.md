# 11. 结构体 (类似Python字典)

C 数组允许定义可存储相同类型数据项的变量，**结构** 是 C 编程中另一种**用户自定义的可用的数据类型**，它允许存储不同类型的数据项。

结构用于表示一条记录，假设想要跟踪图书馆中书本的动态，可能需要跟踪每本书的下列属性：

- Title
- Author
- Subject
- Book ID

## 11.1 定义结构体

使用 **struct** 语句定义结构体：

```c
struct tag {
    member-list
    member-list
    ...
}variable_list;
```

- tag：结构体标签；

- member-list：标准的变量定义，比如 int i 或者 float f；

- variable-list：结构变量，定义在结构的末尾，最后一个分号之前，可以指定一个或多个结构体变量。下面是声明 Book 结构体的方式：

  ```c
  struct Books {
      char title[50];
      char author[50];
      char subject[100];
      int book_id;
  }book;
  ```

一般情况下，**tag、member-list、variable-list** 至少要出现 2 个：

```c
//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//同时又声明了结构体变量s1
//这个结构体并没有标明其标签
struct 
{
    int a;
    char b;
    double c;
} s1;
 
//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//结构体的标签被命名为SIMPLE,没有声明变量
struct SIMPLE
{
    int a;
    char b;
    double c;
};
//用SIMPLE标签的结构体，另外声明了变量t1、t2、t3
struct SIMPLE t1, t2[20], *t3;
 
//也可以用typedef创建新类型
typedef struct
{
    int a;
    char b;
    double c; 
} Simple2;
//现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1, u2[20], *u3;
```

在上面的声明中，第一个和第二声明被编译器当作两个完全不同的类型，即使他们的成员列表是一样的，如果令 t3=&s1，则是非法的。

**结构体的成员可以包含其他结构体，也可以包含指向自己结构体类型的指针，而通常这种指针的应用是为了实现一些更高级的数据结构如链表和树等**。

```c
//此结构体的声明包含了其他的结构体
struct COMPLEX
{
    char string[100];
    struct SIMPLE a;
};
 
//此结构体的声明包含了指向自己类型的指针
struct NODE
{
    char string[100];
    struct NODE *next_node;
};
```

**如果两个结构体互相包含，则需要对其中一个结构体进行不完整声明**：

```c
struct B;    //对结构体B进行不完整声明
 
//结构体A中包含指向结构体B的指针
struct A
{
    struct B *partner;
    //other members;
};
 
//结构体B中包含指向结构体A的指针，在A声明完后，B也随之进行声明
struct B
{
    struct A *partner;
    //other members;
};
```

## 11.2 结构体变量的初始化

```c
#include <stdio.h>
 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book = {"C 语言", "RUNOOB", "编程语言", 123456};
 
int main()
{
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}
```

## 11.3 访问结构成员

为了访问结构的成员，使用**成员访问运算符（.）**。

```c
#include <stdio.h>
#include <string.h>
 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
int main( )
{
   struct Books Book1;        /* 声明 Book1，类型为 Books */
   struct Books Book2;        /* 声明 Book2，类型为 Books */
 
   /* Book1 详述 */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
 
   /* Book2 详述 */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   /* 输出 Book1 信息 */
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);
 
   /* 输出 Book2 信息 */
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);
 
   return 0;
}
```

## 11.4 结构作为函数参数

可以把结构作为函数参数，传参方式与其他类型的变量或指针类似。

```c
#include <stdio.h>
#include <string.h>
 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
/* 函数声明 */
void printBook( struct Books book );
int main( )
{
   struct Books Book1;        /* 声明 Book1，类型为 Books */
   struct Books Book2;        /* 声明 Book2，类型为 Books */
 
   /* Book1 详述 */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
 
   /* Book2 详述 */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   /* 输出 Book1 信息 */
   printBook( Book1 );
 
   /* 输出 Book2 信息 */
   printBook( Book2 );
 
   return 0;
}
void printBook( struct Books book )
{
   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}
```

---

## 11.5 指向结构体的指针

可以定义指向结构体的指针，方式与定义指向其他类型变量的指针相似：

```c
struct Books *struct_pointer;
```

现在，可以在上述定义的指针变量中存储结构体变量的地址。为了查找结构变量的地址，需把 `&` 运算符放在结构体名称前：

```c
struct_pointer = &Book1;
```

为了**使用指向该结构的指针访问结构的成员，必须使用 `->` 运算符**：

```c
struct_pointer -> title;
```

使用结构指针来重写上面的实例，以便理解结构体指针的概念：

```c
#include <stdio.h>
#include <string.h>
 
struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
};
 
/* 函数声明 */
void printBook( struct Books *book );
int main( )
{
    struct Books Book1;        /* 声明 Book1，类型为 Books */
    struct Books Book2;        /* 声明 Book2，类型为 Books */
    
    /* Book1 详述 */
    strcpy( Book1.title, "C Programming");
    strcpy( Book1.author, "Nuha Ali"); 
    strcpy( Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;
 
    /* Book2 详述 */
    strcpy( Book2.title, "Telecom Billing");
    strcpy( Book2.author, "Zara Ali");
    strcpy( Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;
 
    /* 通过传 Book1 的地址来输出 Book1 信息 */
    printBook( &Book1 );
 
    /* 通过传 Book2 的地址来输出 Book2 信息 */
    printBook( &Book2 );
 
    return 0;
}
void printBook( struct Books *book )
{
    printf( "Book title : %s\n", book->title);
    printf( "Book author : %s\n", book->author);
    printf( "Book subject : %s\n", book->subject);
    printf( "Book book_id : %d\n", book->book_id);
}
```

---

# 12. 共用体（union）

<font color=red>**共用体是一种特殊的数据类型，允许在相同的内存位置存储不同的数据类型。可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值**</font>。共用体提供了一种使用相同的内存位置的有效方式。

## 12.1 定义共用体

使用 **union** 语句定义共用体，方式与定义结构类似。union 语句定义了一个新的数据类型，带有多个成员。union 语句的格式如下：

```c
union [union tag]
{
   member definition;
   member definition;
   ...
   member definition;
} [one or more union variables];
```

**union tag** 是可选的，每个 member definition 是标准的变量定义，比如 int i，float f或者其他有效的变量定义。在共用体定义的末尾，可以指定一个或多个共用体变量，这是可选的。下面定义一个名为 Data 的共用体类型，有三个成员 i、f 和 str：

```c
union Data
{
    int i;
    float f;
    char str[20];
} data;
```

**共用体占用的内存应足够存储共用体中最大的成员**。例如，在上面的实例中，Data 将占用 20 个字节的内存空间，因为在各个成员中，字符串所占用的空间是最大的。下面的实例将显示上面的共用体占用的总内存大小：

```c
#include <stdio.h>
#include <string.h>
 
union Data
{
   int i;
   float f;
   char  str[20];
};
 
int main( )
{
   union Data data;        
 
   printf( "Memory size occupied by data : %d\n", sizeof(data));
 
   return 0;
}
```

## 12.2 与结构体的区别

**结构体变量所占内存长度是其中最大字段大小的整数倍**（参考：[结构体大小的计算](https://www.runoob.com/w3cnote/struct-size.html)）。

**共用体变量所占的内存长度等于最长的成员变量的长度**。例如，教程中定义的共用体Data各占20个字节（因为char str[20]变量占20个字节），而不是各占4+4+20=28个字节。

```c
union Data
{
   int i;
   float f;
   char  str[20];
} data;  
```

**节省内存**，有两个很长的数据结构，不会同时使用，比如一个表示老师，一个表示学生，如果要统计教师和学生的情况用结构体的话就有点浪费了！用共用体的话，只占用最长的那个数据结构所占用的空间，就足够了！

**共用体应用场景**：通信中的数据包会用到共用体，因为不知道对方会发一个什么包过来，用共用体的话就很简单了，定义几种格式的包，收到包之后就可以直接根据包的格式取出数据。

## 12.3 访问共用体成员

使用**成员访问运算符 (.)** 访问共用体的成员。

```c
#include <stdio.h>
#include <string.h>
 
union Data
{
   int i;
   float f;
   char  str[20];
};
 
int main( )
{
   union Data data;        
 
   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");
 
   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);
 
   return 0;
}
```

**在同一时间只使用一个变量，这也演示了使用共用体的主要目的**：

```c
#include <stdio.h>
#include <string.h>
 
union Data
{
   int i;
   float f;
   char  str[20];
};
 
int main( )
{
   union Data data;        
 
   data.i = 10;
   printf( "data.i : %d\n", data.i);
   
   data.f = 220.5;
   printf( "data.f : %f\n", data.f);
   
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str);
 
   return 0;
}
```

输出：

```c
data.i : 10
data.f : 220.500000
data.str : C Programming
```