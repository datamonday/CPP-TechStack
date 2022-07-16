# 7.查找

## 7.1 查找的基本概念

![l1](./imgs/l1.png)

![l1](./imgs/l2.png)

![l1](./imgs/l3.png)

![l1](./imgs/l4.png)

![l1](./imgs/l5.png)

![l1](./imgs/l6.png)

![l1](./imgs/l7.png)

![l1](./imgs/l8.png)

## 7.2 线性表的查找

### 7.2.1 顺序查找（线性查找）

应用范围：

- 顺序表或线性链表表示的静态查找表
- 表内元素之间无序

**顺序表的表示**

数据元素类型定义：

```C
typedef struct {
    KeyType key;  // 关键字域
    ......  // 其他域
} ElemType;

typedef struct {  // 顺序表结构类型定义
    ElemType *R;  // 表基址
    int length;  // 表长
} SSTable;  // Sequential Search Table

SSTable ST;  // 定义顺序表ST
```

![l1](./imgs/l9.png)

![l1](./imgs/l10.png)

![l1](./imgs/l11.png)

![l1](./imgs/l12.png)

![l1](./imgs/l13.png)

![l1](./imgs/l14.png)

![l1](./imgs/l15.png)

顺序查找的特点：

- 优点：算法简单，逻辑次序无要求，且不同存储结构均适用。

- 缺点：ASL太长，时间效率太低。

### 7.2.2 二分查找（折半查找）

折半查找：每次将待查找记录所在区间缩小一半。

要求元素有序。查找过程如下：

![l1](./imgs/l16.png)

二分查找的非递归算法：

![l1](./imgs/l17.png)

二分查找的递归算法：

```C
int BinarySearch(int a[], int key, int low, int high)
{
	int mid = (low + high) / 2;
	if (low > high)
		return -1;
	if (key == a[mid])
		return mid;
	else if (key > a[mid])
		return BinarySearch(a, key, mid + 1, high);
	else return BinarySearch(a, key, low, mid - 1);
}

```

**折半查找的性能分析——判定树**

![l1](./imgs/l19.png)

![l1](./imgs/l20.png)

![l1](./imgs/l21.png)

折半查找的性能分析：

- 优点：效率比顺序查找高。
- 缺点：只适用于有序表，且限于顺序存储结构（对线性链表无效）。

### 7.2.3 分块查找（索引顺序表的查找）

块间有序，块内无序。

![l1](./imgs/l22.png)

![l1](./imgs/l23.png)

![l1](./imgs/l24.png)

![l1](./imgs/l25.png)

## 7.3 树表的查找

![l1](./imgs/l26.png)

### 7.3.1 二叉排序树

二叉排序树（Binary Sort Tree）又称为二叉搜索树、二叉查找树。

![l1](./imgs/l27.png)

![l1](./imgs/l28.png)

![l1](./imgs/l29.png)

![l1](./imgs/l30.png)

![l1](./imgs/l31.png)

![l1](./imgs/l32.png)

![l1](./imgs/l33.png)

![l1](./imgs/l34.png)

![l1](./imgs/l35.png)

![l1](./imgs/l36.png)

![l1](./imgs/l37.png)

![l1](./imgs/l38.png)

一个无序序列可以通过构造二叉排序树而变成一个有序序列。构造树的过程就是对无序序列进行排序的过程。

插入的节点均为叶子结点，故无需移动其他节点。相当于在有序序列上插入记录而无需移动其他记录。

但是：**关键字的输入顺序不同，建立的二叉排序树不同**。

![l1](./imgs/l39.png)

![l1](./imgs/l40.png)

![l1](./imgs/l41.png)

![l1](./imgs/l42.png)

![l1](./imgs/l43.png)

![l1](./imgs/l44.png)

### 7.3.2 平衡二叉树

![l1](./imgs/l45.png)

![l1](./imgs/l46.png)

![l1](./imgs/l47.png)

对于一棵有n个结点的AVL树，其高度保持在O(log2n)数量级，ASL也保持在O(log2n)数量级。

![l1](./imgs/l48.png)

![l1](./imgs/l49.png)

![l1](./imgs/l50.png)

![l1](./imgs/l51.png)

![l1](./imgs/l52.png)

![l1](./imgs/l53.png)

![l1](./imgs/l54.png)

![l1](./imgs/l55.png)

![l1](./imgs/l56.png)

![l1](./imgs/l57.png)

![l1](./imgs/l58.png)

![l1](./imgs/l59.png)

## 7.4 散列表的查找

### 7.4.2 散列函数的基本概念

![l1](./imgs/l60.png)

![l1](./imgs/l61.png)

优点：查找效率高

缺点：空间效率低

![l1](./imgs/l62.png)

冲突不可避免，只能尽可能地减少。

使用散列表要解决好两个问题：

![l1](./imgs/l63.png)

### 7.4.2 散列函数的构造方法

![l1](./imgs/l64.png)

![l1](./imgs/l65.png)

![l1](./imgs/l66.png)

![l1](./imgs/l67.png)

### 7.4.3 处理冲突的方法

![l1](./imgs/l68.png)

![l1](./imgs/l69.png)

![l1](./imgs/l70.png)

![l1](./imgs/l71.png)

![l1](./imgs/l72.png)

![l1](./imgs/l73.png)

![l1](./imgs/l74.png)

链地址法的优点：

- 非同义词不会冲突，无“聚集”现象
- 链表上结点空间动态申请，更适合于表长不确定的情况

### 7.4.4 散列表的查找

![l1](./imgs/l75.png)

![l1](./imgs/l76.png)

![l1](./imgs/l77.png)

![l1](./imgs/l78.png)

![l1](./imgs/l79.png)

![l1](./imgs/l80.png)

![l1](./imgs/l81.png)

