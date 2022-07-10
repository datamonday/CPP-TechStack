# 6. 图

## 6.1 图的基本概念

![g1](./imgs/g1.png)

![](./imgs/g2.png)

![](./imgs/g3.png)

![](./imgs/g4.png)

![](./imgs/g5.png)

![](./imgs/g6.png)

![](./imgs/g7.png)

![](./imgs/g8.png)

图中边或弧所具有的的相关数称为**权**，表明从一个顶点到另一个顶点的距离或耗费。带权的图称为**网**。

![](./imgs/g9.png)

![](./imgs/g10.png)

![](./imgs/g11.png)

![](./imgs/g12.png)

## 6.2 案例引入

六度空间理论

## 6.3 图的类型定义

![](./imgs/g13.png)

![](./imgs/g14.png)

## 6.4 图的存储结构

![](./imgs/g15.png)

### 6.4.1 邻接矩阵

![](./imgs/g16.png)

![](./imgs/g17.png)

- 无向图的邻接矩阵是对称的
- 顶点 i 的度 = 第 i 行（列）中 1 的个数
- 完全图的邻接矩阵中，对角元素为 0，其余为 1

![](./imgs/g18.png)

![](./imgs/g19.png)

邻接矩阵的存储表示：用两个数组分别存储顶点表和邻接矩阵。

```C
# define MaxInt 32767  // 表示极大值
# define MVNum 100  // 最大顶点数
typedef char VerTexType;  // 设顶点的数据类型维字符型
typedef int ArcType;  // 假设边的权值类型为整型

typedef struct{
    VerTexType vexs[MVNum];  // 顶点表
    ArcType arcs[MVNum][MVNum];  // 邻接矩阵
    int vexnum, arcnum;  // 图的当前点数和边数
}AMGraph;  // Adjacency Matrix Graph
```

![](./imgs/g20.png)

```c
Status CreatUDN(AMGraph &G){
    // 采用邻接矩阵表示法，创建无向网G
    cin >> G.vexnum >> G.arcnum;  // 依次输入总顶点数，总边数
    for(i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i];  // 依次输入点的信息
    for(i = 0; i < G.vexnum; ++i)  // 初始化邻接矩阵
        for(j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;  // 边的权值均置为极大值
    // 构造邻接矩阵
    for(k = 0; k < G.arcnum; ++k){
        cin >> v1 >> v2 >> w;  // 输入一条边所依附的顶点及边的权值
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);  // 确定 v1 和 v2 在G中的位置
        G.arcs[i][j] = w;  // 置<v1, v2>的权值为w
        G.arcs[j][i] = G.arcs[i][j];  // 置<v1, v2>的对称边<v2, v1> 的权值为w
    }
    return OK;
}

// 在图 G 中查找顶点u，存在则返回顶点表中的下标；否则返回-1
int LocateVex(AMGraph G, VerTexType u){
    int i;
    for (i=0; i<G.vexnum; ++i)
        if(u == G.vexs[i])
            return i;
   	return -1
}
```



![](./imgs/g21.png)

![](./imgs/g22.png)

### 6.4.2 邻接表

![](./imgs/g23.png)

注：

- 邻接表不唯一，顶点的位置可以互换，例如v1结点邻接的v2和v4可以互换。
- 若无向图中有 n 个顶点，e 条边，则其邻接表需要 n 个头结点和 2e 个表结点。适宜存储稀疏图。
- 无向图中顶点 vi 的度为：第 i 个单链表中的结点数。

![](./imgs/g24.png)

![](./imgs/g25.png)

![](./imgs/g26.png)

![](./imgs/g27.png)

![](./imgs/g28.png)

![](./imgs/g29.png)

![](./imgs/g30.png)

![](./imgs/g31.png)

![](./imgs/g32png)

![](./imgs/g33.png)

![](./imgs/g34.png)

### 6.4.3 十字链表

![](./imgs/g35.png)

![](./imgs/g36.png)

![](./imgs/g37.png)

![](./imgs/g38.png)

![](./imgs/g39.png)

![](./imgs/g40.png)

## 6.5 图的遍历

从已给的连通图中某一顶点出发，沿着一些边访遍图中所有的顶点，且使每个顶点仅被访问一次，就叫做图的遍历，它是图的基本运算。遍历的本质：找每个顶点的临界点的过程。

图的特点：图中可能存在回路，并且图的任一顶点都可能与其他顶点想通，在访问完某个顶点之后可能会沿着某些边又回到了曾经访问过的顶点。

怎样避免重复访问？

解决思路：设置辅助数组 visited[n]，用来标记每个被访问过的顶点。

- 初始状态：visited[i]=0
- 顶点i被访问过之后，设置visited[i]=1，防止被多次访问

图常用的遍历：

- 深度优先遍历（Depth-First Search，DFS）
- 广度优先遍历（Breadth-First Search，BFS）

![](./imgs/g41.png)

![](./imgs/g42.png)

![](./imgs/g43.png)

![](./imgs/g44.png)

![](./imgs/g45.png)

![](./imgs/g46.png)

![](./imgs/g47.png)

![](./imgs/g48.png)

**DFS 与 BFS 算法效率比较：**

- **空间复杂度相同，都是 O(n)，使用了堆栈或者队列；**
- **时间复杂度只与存储结构（邻接矩阵或邻接表）有关，而与搜索路径无关。**

## 6.6 图的应用

![](./imgs/g49.png)

- 包含 n 个顶点 n-1 条边的图不一定是生成树。

![](./imgs/g50.png)

### 6.6.1 最小生成树（MST）

![](./imgs/g51.png)

![](./imgs/g52.png)

![](./imgs/g53.png)

![](./imgs/g54.png)

### 6.6.2 MST构造方法——Prim算法

普里姆算法。

![](./imgs/g55.png)

### 6.6.3 MST构造方法——Kruskal算法

克鲁斯卡尔算法本质上是贪心算法。

![](./imgs/g56.png)

![](./imgs/g57.png)

### 6.6.4 最短路径求解

![](./imgs/g58.png)

![](./imgs/g59.png)

**Dijkstra（迪杰斯特拉）算法求解**

![](./imgs/g60.png)

**Floyd（弗洛伊德）算法求解**

### 6.6.5 Dijkstra 算法

“有效的程序员不应该浪费很多时间用于程序调试，他们应该一开始就不要把故障引入。”

![](./imgs/g61.png)

![](./imgs/g62.png)

![](./imgs/g63.png)

### 6.6.6 Floyd 算法

![](./imgs/g64.png)

### 6.6.7 拓扑排序

![](./imgs/g65.png)

![](./imgs/g67.png)

![](./imgs/g66.png)

![](./imgs/g68.png)

![](./imgs/g69.png)

![](./imgs/g70.png)

![](./imgs/g71.png)

### 6.6.8 关键路径

![](./imgs/g72.png)

![](./imgs/g73.png)

![](./imgs/g74.png)

![](./imgs/g75.png)

![](./imgs/g76.png)

![](./imgs/g77.png)

![](./imgs/g78.png)

![](./imgs/g79.png)

![](./imgs/g80.png)



参考资料：

1. 严蔚敏《数据结构(C语言描述)》
2. 数据结构与算法基础：[bilibili](https://www.bilibili.com/video/BV1nJ411V7bd?p=5&spm_id_from=pageDriver)