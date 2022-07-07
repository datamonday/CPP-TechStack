# 3. 栈 (Stack) 和队列 (Queue) 

普通线性表的插入和删除操作：

![image-20210517193804064](D:\Github\CPP-TechStack\03 Data Structure\imgs\普通线性表的插入和删除操作.png)

---

## 3.1 栈和队列的特点

栈（先进后出，类似弹夹）和队列（先进先出，类似排队）是两种重要的数据结构。

- 定义：栈和队列是**限定插入和删除只能在表的端点进行**的**线性表**。
- 逻辑结构：与线性表相同，仍为一对一的关系。
- 存储结构：用顺序栈或链栈存储均可，但顺序栈更常见。
- 运算规则：只能在栈顶 (表尾) 运算，且访问结点时依照后进先出 (LIFO，last in first out) 的规则。
- 实现方式：关键是编写入栈和出栈函数，具体实现依顺序栈或链栈的不同而不同。

![image-20210517194414165](D:\Github\CPP-TechStack\03 Data Structure\imgs\线性表栈队列的比较.png)

栈是仅在 **表尾** 进行插入、删除操作的线性表。

表尾 ($a_n$ 端) 称为 **栈顶Top**；表头 ($a_1$ 端) 称为 **栈底Base**。

例如：栈 $S = (a_1, a_2, ..., a_{n-1}, a_n)$

- 入栈：插入元素到栈顶 (表尾) 的操作。

- 出栈：从栈顶 (表尾) 删除最后一个元素的操作。

![栈](D:\Github\CPP-TechStack\03 Data Structure\imgs\栈.jpg)

假设有3个元素，a，b，c，入栈顺序是a，b，c，则它们的出栈顺序有几种可能？

![image-20210517200327754](D:\Github\CPP-TechStack\03 Data Structure\imgs\出栈顺序计算例题.png)

栈与一般线性表的区别：仅在于运算规则的不同。

![image-20210517200723266](D:\Github\CPP-TechStack\03 Data Structure\imgs\线性表与栈的对比.png)

---

**队列 (Queue)** 是一种先进先出 (FIFO, first in first out) 的线性表。**在表一端插入 (表尾)，在另一端 (表头) 删除**。

- 定义：头删尾插的线性表。
- 逻辑结构：
- 存储结构：顺序队或链队，以循环顺序队列更为常见。
- 运算法则：只能在队首和队尾运算，且访问结点时依照先进先出 (FIFO) 的原则。
- 实现方式：关键是编写入队和出队函数，具体实现依顺序队或链队的不同而不同。

---

## 3.2 栈的应用

栈的应用，适用于**后进先出**的情况：

- 数制转换
- 括号匹配的检验
- 表达式求值
- 迷宫求解
- 表达式求值
- 八皇后问题
- 函数调用
- 递归调用的实现

### 3.2.1 数制转换

十进制整数N向其他进制数的转换是计算机实现的基本问题。简单的算法原理：

`n = (n div d) * d + n mod d`

### 3.2.2 括号匹配的检验

假设表达式中允许包含两种括号：圆括号和方括号，其嵌套的顺序任意。

### 3.2.3 表达式求值

表达式求值是程序设计语言编译中一个最基本的问题，其需要使用栈实现。常用算符优先算法——由运算符优先级确定运算顺序的表达式求值算法。

表达式的组成：

- 操作数（operand）：常数、变量。
- 运算符（operator）：算术运算符、关系运算符和逻辑运算符。
- 界限符（delimiter）：左右括弧和表达式结束符。

任何一个算术表达式都是由操作数、算术运算符和界限符组成，后两者统称为算符。例如 `# 3 * (7-2) #`。

为了实现表达式求值，需要设置两个栈：

- 算符栈 OPTR：用于寄存运算符。
- 操作数栈 OPND：用于寄存运算数和运算结果。

求值的处理过程是从左至右扫描表达式的每一个字符：

- 当扫描到的是运算数，则将其压入栈OPND；
- 当扫描到的是运算符，
  - 若这个运算符比OPTR栈顶运算符的优先级高，则入栈OPTR，继续向后处理。
  - 若这个运算符比OPTR栈顶运算符优先级低，则从OPND栈中弹出两个运算数，从栈OPTR中弹出栈顶运算符进行运算，将运算结果压入栈OPND。
- 继续处理当前字符，直到遇到结束符为止。

---

## 3.3 队列的应用

队列的应用，适用于**先进先出**的情况：

- 脱机打印输出：按申请的先后顺序依次输出；
- 多用户系统中，多个用户排成队，分时的循环使用CPU和主存；
- 按用户的优先级排成多个队，每个优先级一个队列；
- 实时控制系统，信号按照接收的先后顺序依次处理；
- 网络电文传输，按到达的时间先后顺序依次进行。

---

### 3.3.1 舞伴问题

舞伴问题的描述：假设在周末舞会上，男士们和女士们进入舞厅时各自排成一队，跳舞开始时，依次从男队和女队的队头上各出一人配成舞伴，若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。现要求设计一个函数模拟上述舞伴配对问题，试设计程序实现之。

## 3.4 栈的表示和操作实现

### 3.4.1 栈的抽象数据类型和定义

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\栈的抽象数据类型和定义2.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\栈的抽象数据类型和定义.png)

由于栈本身就是线性表，因此也有顺序存储和链式存储两种实现方式。

- 顺序存储——顺序栈
- 链式存储——链栈

### 3.4.2 顺序栈的表示和实现

存储方式：同一般线性表的顺序存储结构完全相同，利用一组地址连续的存储单元一次存放自栈底到栈顶的数据元素。栈底一般在低地址端。

- 附设top指针，指示栈顶元素在顺序栈中的位置。**为了方便，通常top指示真正的栈顶元素之上的下标地址**。
- 另设base指针，指示栈底元素在顺序栈中的位置。
- stacksize表示栈可使用的最大容量。

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\顺序栈1.png)

使用数组作为顺序栈存储方式的特点：简单、方便、但是容易产生溢出（数组大小固定）。

- 上溢（overflow）：栈已满，还要压入元素。
- 下溢（underflow）：栈已空，还要弹出元素。

注意：上溢是一种错误，使问题的处理无法进行，而下溢一般认为是一种结束条件，即问题处理结束。

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\顺序栈2.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\顺序栈3.png)

```C
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef struct{
	SElemType *base; // 栈底指针
	SElemType *top;  // 栈顶指针
	int stacksize;   // 栈可用最大容量 
}SqStack;

void InitStackSq(sqStack *S){
	S.base = (SElemType*) malloc(MAXSIZE * sizeof(SElemType));
	
	if (!S.base) exit (OVERFLOW);
	
	S.top = S.base;
	S.stacksize = MAXSIZE;
	
	return OK;
}
```

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\顺序栈4.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\顺序栈5.png)

### 3.4.3 链栈的表示和实现

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\顺序栈6.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\顺序栈7.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\顺序栈8.png)

## 3.5 栈与递归

递归对象：若一个对象部分地包含自己，或用他自己给自己定义，则称这个对象是递归的。

递归：若一个过程直接或间接地调用自己，则称这个过程是递归的过程。例如求n的阶乘，斐波那契数列。以下三种情况常常用到递归方法：

- 递归定义的数学函数
  - 阶乘
  - 斐波那契数列
- 具有递归特性的数据结构
  - 二叉树
  - 广义表
- 可递归求解的问题
  - 迷宫问题
  - Hanoi塔问题

---

递归问题——用分治法求解

分治法：对于一个较为复杂的问题，能够分解成几个相对简单的且解法相同或类似的子问题来求解。必备的三个条件：

- 能够将一个问题转变为一个新问题，而新问题与原问题的解法相同或类同，不同的仅仅是处理的对象，且这些处理对象是变化有规律的；
- 可以将上述转化而使问题简化；
- 必须要有一个明确的递归出口，或成为递归的边界。

分治法求解递归问题算法的一般形式：

```C
void p(参数表){
    if(递归条件结束){
        可直接求解步骤；——基本项
    }
    else{
        p(较小的参数)；——归纳项
    }
}
```

例如：

```C
long Fact(long n){
    if(n == 0){
        return 1;
    }
    else{
        return n * Fact(n-1);
    }
}
```

函数调用过程：

调用前，系统完成：

（1）将实参，返回地址等传递给被调用函数

（2）为被调用函数的局部变量分配存储区

（3）将控制转移到被调用函数的入口

调用后，系统完成：

（1）保存被调用函数的计算结果

（2）释放被调用函数的数据区

（3）依照被调用函数保存的返回地址将控制转移到调用函数

当多个函数构成嵌套调用时，遵循后调用的先返回原则，用栈实现。

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\递归问题1.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\递归问题2.png)

递归函数调用的实现：

- 层次
- 递归工作栈：递归程序运行期间使用的数据存储区
- 工作记录：实在参数，局部变量，返回地址

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\递归问题3.png)

递归的优缺点：

- 优点：结构清晰，程序易读
- 缺点：每次调用要生成工作记录，保存状态信息，入栈；返回时要出栈，恢复状态信息，时间开销大。

递归——>非递归

- 方法1：尾递归，单项递归——>循环结构
- 方法2：自用栈模拟系统的运行时栈

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\递归问题4.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\递归问题5.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\递归问题6.png)

借助栈改写递归

- 递归程序在执行时需要系统提供栈来实现。
- 仿照递归算法执行过程中递归工作栈的状态变化可写出相应的非递归程序。
- 改写后的非递归算法与原来的递归算法相比，结构不够清晰，可读性较差，有的还需要经过一系列优化。

借助栈改写递归的方法

- 设置一个工作栈存放递归工作记录（包括实参、返回地址及局部变量等）。
- 进入非递归调用入口（即被调用程序开始处）将调用程序传来的实在参数和返回地址入栈（递归程序不可以作为主程序，因而可认为初始是被某个调用程序调用）。
- 进入递归调用入口：当不满足递归结束条件时，逐层递归，将实参、返回地址及局部变量入栈，这一过程可用循环语句来实现——模拟递归分解的过程。
- 递归结束条件满足，将到达递归出口的给定常数作为当前的函数值。
- 返回处理：在栈不空的情况下，反复退出栈顶记录，根据记录中的返回地址进行题意规定的操作，即逐层计算当前函数值，直至栈空为止——模拟递归求职过程。

## 3.6 队列的表示和操作的实现

队列（Queue）是仅在表尾进行插入操作，在表头进行删除操作的线性表。队列的存储结构维链队或顺序队（常用循环顺序队）。

1. 定义：只能在表的一端进行插入运算，在表的另一端进行删除运算的线性表（头删尾插）。
2. 逻辑结构：与同线性表相同，仍为一对一关系。
3. 存储结构：顺序队或链队，以循环顺序队列更常见。
4. 运算规则：只能在队首和队尾运算，且访问节点时依照先进先出的原则。
5. 关键是掌握入队和出队操作，具体实现依顺序队或链队的不同而不同。

队列的常见应用

- 脱机打印输出：按申请的先后顺序依次输出。
- 多用户系统中，多个用户排成队，分时地循环使用CPU和主存。
- 按用户的优先级排成多个队，每个优先级一个队列。
- 实时控制系统，信号按接收的先后顺序依次处理。
- 网络电文传输，按到达的时间先后顺序依次进行。

### 3.6.1 队列的抽象数据类型定义

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列1.png)

### 3.6.2 队列的顺序表示和实现

队列的物理存储可以使用顺序存储结构，也可以使用链式存储结构。队列的存储方式可以分为两种：顺序队列和链式队列。

队列的顺序表示——用一维数组base[MAXQSIZE]

```C
#define MAXQSIZE 100  // 最大队列长度
typedef struct{
    QElemType *base;  // 初始化的动态分配存储空间
    int front;  // 头指针
    int rear;  // 尾指针
}SqQueue;  // 普通类型
```

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列2.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列3.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列4.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列5.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列6.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列7.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列8.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列9.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列10.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列11.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列12.png)

### 3.6.3 队列的链式表示和实现

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列13.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列14.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列15.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure\imgs\队列16.png)



---

参考资料：

1. 严蔚敏《数据结构(C语言描述)》
2. 数据结构与算法基础：[bilibili](https://www.bilibili.com/video/BV1nJ411V7bd?p=5&spm_id_from=pageDriver)
