# 数据结构的概述

> 定义：我们如何把现实中大量而**复杂的问题**以特定的**数据类型**和特定的**储存结构**保存到主储存器（内存）中。

狭义：

- 数据结构是专门研究数据存储的问题。
- 数据的存储包含两个方面：个体的存储 ＋ 个体关系的储存

广义：

- 数据结构既包含数据的存储也包含数据的操作
- 对存储数据的操作就是算法


*数据结构 ＝ 个体 ＋ 个体的关系*

*程序 ＝ 数据的存储（数据结构） ＋ 数据的操作（算法） ＋ 可以被计算机执行的语言*

#### 线性结构

> 把所有的结点用一根直线穿起来
>
> 例如：数组［连续储存］／ 链表［离散存储］
>
> 应用：栈和队列

***数组［连续储存］***

- 优点：存取速度很快

- 缺点：
    1. 插入／删除操作很慢
    1. 必须知道数组的长度
    1. 需要大块连续的内存块
    1. 空间通常有限制

***链表［离散存储］***

- 优点：
    1. 空间没有限制
    1. 插入／删除元素很快

- 缺点：存取速度很慢

# 算法的概述

> 定义：在数据结构基础上为实现某个功能（比如查找某个元素，删除某个元素，对所有元素进行排序）而执行的相应操作，这个相应的操作也叫算法。

*算法 ＝ 对存储数据的操作（解题的方法和步骤）*

狭义：
- 是与数据的存储方式密切相关的。

广义：
- 算法是与数据的存储方式无关的。

**泛型**：同一种逻辑结构，无论该逻辑结构物理存储是什么样子的，我们都可以对它执行相同操作。

例如：
队列，无论是链表写的队列或数组写的队列，都应该能执行相同的操作。

## 衡量算法的标准

1. **时间复杂度**：大概程序要执行的次数，而非执行的时间。*（因为每台计算机配置不同，不能用执行时间来衡量时间复杂度）*
1. **空间复杂度**：算法执行过程中大概所占用的*最大内存*
1. **难易程度**：能够被多数人理解的算法，才算是好的算法
1. **健壮性**

---

**数据结构和算法的区别**

- 数据结构是专门研究数据存储的问题。
- 数据的存储包含两个方面：个体的存储 ＋ 个体关系的储存
- 算法是对存储数据的操作

