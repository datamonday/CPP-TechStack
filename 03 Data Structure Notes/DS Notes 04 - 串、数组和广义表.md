# 4. 串、数组和广义表

栈和队列——操作受限的线性表。

串——内容受限的线性表，只能是字符。

数组和广义表——线性结构的推广。

## 4.1 串的定义

串（string）：零个或多个任意字符组成的有限序列。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\串1.png)

几个术语：

- 子串：传中任意个连续字符组成的子序列称为该串的子串。
- 主串：包含子串的串相应的称为主串。
- 字符位置：字符在序列中的序号为该字符在串中的位置。
- 子串位置：子串第一个字符在主串中的位置。
- 空格串：由一个或多个空格组成的串，与空串不同。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\串2.png)

串相等：当且仅当两个串的长度相等并且各个对应位置上的字符都相同时，这两个串才是相等的。

所有的空串是相等的。

## 4.2 案例引入

计算机上的非数值处理的对象大部分是字符串数据。例如：文字编辑、符号处理、各种信息处理系统等等。

### 4.2.1 病毒感染检测（字符串的匹配）

研究者将人的DNA和病毒DNA均表示成一系列字母组成的字符串序列。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\串3.png)

## 4.3 串的类型定义、存储结构及运算

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\串4.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\串5.png)

串中元素逻辑关系与线性表的相同，串可以采用与线性表相同的存储结构。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\串6.png)

### 4.3.1 串的顺序存储结构

```C
#define MAXLEN 255
typedef struct{
    char ch[MAXLEN+1];  // 存储串的一维数组，一般第一个位置不用
    int length;  //串的当前长度
}SString;
```

### 4.3.2 串的链式存储结构

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\块的链式存储结构.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\块链结构.png)

### 4.3.3 串的模式匹配算法

算法目的：用来确定主串中所含子串（模式串）第一次出现的位置（定位）。

算法应用：搜索引擎、拼写检查、语言翻译、数据压缩。

算法种类：

- 暴力算法（Brute-Force，BF，又称古典的、经典的、朴素的、穷举的）
- KMP算法（速度快）

---

BF算法：从主串S的每一个字符开始依次与模式串T的字符进行匹配。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\BF算法.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\BF算法2.png)

**T 从 1 位置移动到 j，移动长度为 j-1，S 的移动长度也应该是 j-1；S 现在的位置是 i，用现在的位置 i 减去移动的长度 j-1 再加1，就是下一个位置，即 i - (j-1) + 1**。注意，KMP算法中，主串不使用回溯，所以提高了速度。

Index(S,T,pos)：将主串的第pos个字符和模式串的第一个字符比较。

- 若相等，继续逐个比较后续字符。
- 若不等，从主串的下一字符起，重新与模式串的第一个字符比较。
  - 直到主串的第一个连续子串字符序列与模式串相等。返回值为S中与T匹配的子序列第一个字符的序号，即匹配成功。
  - 否则，匹配失败，返回值0。

```C
int IndexBF(SString S, SString T){
    int i=1, j=1;
    while (i <= S.length && j <= T.length){
        if (S.ch[i] == T.ch[j]) {
            ++i;  // 依次匹配
            ++j;
        }
        else{
            i = i - (j - 1) + 1;  // 回溯，重新开始下一次匹配
            j = 1;
        }
    }
    if (j > T.length){
        return i - T.length;  // 返回匹配的第一个字符的下标
    }
    else {
        return 0;  // 模式匹配不成功
    }
}
```

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\BF算法3.png)

**KMP（Knuth Morris and Pratt）算法**

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP1.png)

j 如何回溯？用一个数组 next[j] 来存放下一个位置。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP2.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP3.png)

直接移动模式串，将模式串的公共前缀移动到后缀位置：

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP4.png)

最长公共前后缀：如果模式串中有多对公共前后缀，要取最长的那一对，并且长度要小于子串长度。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP5.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP6.png)

KMP算法的关键是挖掘模式串的信息。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP7.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP8.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP9.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP10.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP11.png)

```C
int IndexKMP(SString S, SString T, int pos){
    i = pos, j = 1;
    while (i < S.length && j < T.length){
        if (j == 0 || S.ch[i] == T.ch[j]){
            i++;
            j++;
        }
        else{
            j = next[j];  // i 不变，j回溯
        }
    }
    if (j > T.length){
        return i - T.length;
    }
    else{
        return 0;
    }
}

void GetNext(SString T, int &next[]){
    i = 1; 
    next[1] = 0;
    j = 0;
    while(i < t.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else{
            j = next[j];
        }
    }
}

void GetNextVal(SString T, int &nextval[]){
    i = 1;
    nextval[1] = 0;
    j = 0;
    while(i < T.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            ++i;
            ++j;
            if(T.ch[i] != T.ch[j]){
                nextval[i] = j;
            }
            else{
                nextval[i] = nextval[j];
            }
        }
        else{
            j = nextval[j];
        }
    }
}
```

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP12.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\KMP13.png)

## 4.4 数组

数组：按一定格式排列起来，具有相同类型的数据元素的集合。

一维数组：若线性表中的数据元素维非结构的简单元素，则称为一维数组。

一维数组的逻辑结构：线性结构。定长的线性表。

声明格式：`数据类型 变量名称[长度];`

二维数组：若一维数组中的数据元素又是一维数组结构，则称为二维数组。

二维数组的逻辑结构：

- 非线性结构：每一个数据元素既在一个行表中，又在一个列表中。
- 线性结构，定长的线性表：该线性表的每个数据元素也是一个定长的线性表。

三维数组：若二维数组中的元素又是一个一维数组，则称为三维数组。

n维数组：若n-1维数组中的元素又是一个一维数组结构在，则称为n维数组。

### 4.4.1 数组的抽象数据类型和定义

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array.png)

### 4.4.2 数组的顺序存储

因为数组一般不做插入和删除操作，所以一般采用顺序存储结构来表示数组。

数组可以是多维的，但存储数据元素的内存单元地址是一维的，因此，在存储数组结构之前，需要解决**将多维关系映射到一维**关系的问题。

一维数组存储：

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array2.png)

二维数组存储：

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array3.png)

存储单元是一维结构，而数组是多维结构，则用一组连续存储单元存放数组的数据元素就有个**次序约定问题**。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array4.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array5.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array6.png)

三维数组存储：

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array7.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array8.png)

n维数组存储：

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array9.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\array10.png)

### 4.4.3 特殊矩阵的压缩存储

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix.png)

1. 什么是压缩存储？——若U盾讴歌数据元素的值都相同，则只分配一个元素值的存储空间，且零元素不占存储空间。
2. 什么样的矩阵能够压缩？——一些特殊矩阵，如：对阵矩阵，对角矩阵，三角矩阵，稀疏矩阵等。
3. 什么叫稀疏矩阵？——矩阵中非零元素的个数较少（一般少于5%）。

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix2.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix3.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix4.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix5.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix6.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix7.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix8.png)

**三元组顺序表**又称有序的**双下标法**。

三元组顺序表的优点：非零元在表中按行序有序存储，因此便于进行依行顺序处理的矩阵运算。

三元组顺序表的缺点：不能随机存取。若按行号存取某一行中的非零元，则需从头开始进行查找。

### 4.4.4 稀疏矩阵的链式存储结构——十字链表

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix9.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix10.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\matrix11.png)

## 4.5 广义表

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\广义表1.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\广义表2.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\广义表3.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\广义表4.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\广义表5.png)

![](D:\GitHub\CPP-TechStack\03 Data Structure Notes\imgs\广义表6.png)



---

参考资料：

1. 严蔚敏《数据结构(C语言描述)》
2. 数据结构与算法基础：[bilibili](https://www.bilibili.com/video/BV1nJ411V7bd?p=5&spm_id_from=pageDriver)
3. KMP算法易懂版：[bilibili](bilibili.com/video/BV1jb411V78H?spm_id_from=333.337.search-card.all.click&vd_source=ac46eb1ed05880558bab17857f8e57c2)

