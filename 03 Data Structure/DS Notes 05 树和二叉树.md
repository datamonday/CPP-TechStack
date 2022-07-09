# 5. 树和二叉树

![](D:./imgs/tree.png)

## 5.1 树和二叉树的定义

![](D:./imgs/tree1.png)

![](D:./imgs/tree1.png)

![](D:./imgs/tree2.png)

![](D:./imgs/tree3.png)

![](D:./imgs/tree4.png)

### 5.1.1 树的基本概念

![](D:./imgs/tree5.png)

![](D:./imgs/tree6.png)

树的深度：树汇总结点的最大层次。

![](D:./imgs/tree7.png)

![](D:./imgs/tree8.png)

### 5.1.2 二叉树

![](D:./imgs/tree9.png)

![](D:./imgs/tree10.png)

![](D:./imgs/tree11.png)

![](D:./imgs/tree12.png)

![](D:./imgs/tree13.png)

## 5.2 案例引入

### 5.2.1 数据压缩问题

![](D:./imgs/tree14.png)

### 5.2.2 利用二叉树求解表达式的值

![](D:./imgs/tree15.png)

## 5.3 树和二叉树的抽象数据类型定义

![](D:./imgs/tree16.png)

![](D:./imgs/tree17.png)

## 5.4 二叉树的性质和存储结构



![](D:./imgs/tree18.png)

![](D:./imgs/tree19.png)

![](D:./imgs/tree20.png)

![](D:./imgs/tree21.png)

![](D:./imgs/tree22.png)

![](D:./imgs/tree23.png)

![](D:./imgs/tree24.png)

![](D:./imgs/tree25.png)

![](D:./imgs/tree26.png)

![](D:./imgs/tree27.png)

![](D:./imgs/tree28.png)

## 5.5 遍历二叉树和线索二叉树

![](D:./imgs/tree29.png)

![](D:./imgs/tree30.png)

![](D:./imgs/tree31.png)

![](D:./imgs/tree32.png)

![](D:./imgs/tree33.png)

![](D:./imgs/tree34.png)

![](D:./imgs/tree35.png)

![](D:./imgs/tree36.png)

![](D:./imgs/tree37.png)

若二叉树中各节点的值均不相同，则二叉树节点的先序序列、中序序列和后序序列都是唯一的。

由二叉树的先序序列和中序序列，或由二叉树的后序序列和中序序列可以确定唯一一棵二叉树。

![](D:./imgs/tree38.png)

![](D:./imgs/tree39.png)

### 5.5.1 先序遍历

![](D:./imgs/tree40.png)

```C
Status PreOrderTraverse(BiTree T){
    if (T == NULL){
        return OK;
    }
    else{
        visit(T);  // 访问根节点
        PreOrderTraverse(T -> lchild);  // 递归遍历左子树
        PreOrderTraverse(T -> rchild);  // 递归遍历右子树
    }
}
```

递归过程解释：

![](D:./imgs/tree41.png)

### 5.5.2 中序遍历

![](D:./imgs/tree42.png)

```C
Status InOrderTraverse(BiTree T){
    if (T == NULL) {
        return OK;
    }
    else{
        InOrderTraverse(T -> lchild);  // 递归遍历左子树
        visit(T);  // 访问根节点
        InOrderTraverse(T -> rchild);   // 递归遍历右子树
    }
}
```

### 5.5.3 后序遍历

![](D:./imgs/tree43.png)

```C
Status PostOrderTraverse(BiTree T){
    if (T == NULL) {
        return OK;
    }
    else{
        PostOrderTraverse(T -> lchild);  // 递归遍历左子树
        PostOrderTraverse(T -> rchild);   // 递归遍历右子树
        visit(T);  // 访问根节点
    }
}
```

### 5.5.5 遍历算法的分析

![](D:./imgs/tree44.png)

时间效率：O(n)——每个节点只访问一次

空间效率：O(n)——栈还占用的最大辅助空间

### 5.5.6 中序遍历非递归算法

二叉树中序遍历额非递归算法的关键：在中序遍历过某节点的整个左子树之后，如何找到该节点的跟及右子树。

基本思想：

- 1）建立一个栈
- 2）根节点进栈，遍历左子树
- 3）根节点出栈，输出根节点，遍历右子树

![](D:./imgs/tree45.png)

```C
Status InOrderTraverse(BiTree T){
    BiTree p;
    InitStack(S);
    p = T;
    while (p || !StackEmpty(S)) {
        if (p){
            Push(S, p);
            p = p -> lchild;
        }
        else{
            Pop(S, q);
            printf("%c", q -> data);
            p = q -> rchild;
        } 
    }
    return OK;
}
```

### 5.5.7 二叉树的层次遍历算法

 层次遍历：对于一颗二叉树，从根节点开始，按照从上到下、从左到右的顺序访问每一个节点，每个节点仅仅访问一次。

![](D:./imgs/tree46.png)

![](D:./imgs/tree47.png)

二叉树层次遍历算法：

```C
void LevelOrder(BTNode *b){
    BTNode *p;
    SqQueue *qu;
    InitQueue(qu);  // 初始化队列
    enQueue(qu, b);  // 根节点指针进入队列
    while (!QueueEmpty(qu)){
        deQueue(qu, p);  // 节点出队
        printf("%c", p -> data);  // 访问节点
        if (p -> lchild != NULL) {
            enQueue(qu, p -> lchild);  // 有左孩子时将其进队
        }
        if (p -> rchild != NULL) {
            enQueue(qu, p -> rchild);  // 有右孩子时将其进队
        }
    }
}
```

### 5.5.8 建立二叉树算法

按先序遍历序列建立二叉树的二叉链表。

![](D:./imgs/tree48.png)

![](D:./imgs/tree49.png)

### 5.5.9 复制二叉树

![](D:./imgs/tree50.png)

### 5.5.10 计算二叉树的深度

![](D:./imgs/tree51.png)

### 5.5.11 计算二叉树结点总数

![](D:./imgs/tree52.png)

![](D:./imgs/tree53.png)

### 5.5.13 线索二叉树 

为什么要研究线索二叉树？

当二叉链表作为二叉树的存储结构时，可以很方便的找到某个节点的左右孩子。但是一般情况下，无法直接找到该结点在某种遍历序列中的前驱和后继结点。

如何寻找特定遍历序列中二叉树结点的前驱和后继？

解决的方法：

1. 遍历寻找——费时间
2. 再增设前驱、后继指针域——增加了存储负担
3. 利用二叉链表中的空指针域

![](D:./imgs/tree54.png)

利用二叉链表中的空指针域：

如果某个结点的左孩子为空，则将空的左孩子指针域改为指向其前驱；如果某节点的右孩子为空，则将空的右孩子指针域改为指向其后继。这种改变指向的指针称为“线索”。加上了线索的二叉树称为线索二叉树（Threaded Binary Tree）。对二叉树按某种遍历次序使其变为线索二叉树的过程叫做线索化。

![](D:./imgs/tree55.png)

![](D:./imgs/tree56.png)

![](D:./imgs/tree57.png)

![](D:./imgs/tree58.png)

![](D:./imgs/tree59.png)

![](D:./imgs/tree60.png)

![](D:./imgs/tree61.png)



---

参考资料：

1. 严蔚敏《数据结构(C语言描述)》
2. 数据结构与算法基础：[bilibili](https://www.bilibili.com/video/BV1nJ411V7bd?p=5&spm_id_from=pageDriver)