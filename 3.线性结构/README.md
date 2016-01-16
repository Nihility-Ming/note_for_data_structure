# 线性结构

> 把所有的结点用一根直线穿起来

连续储存［数组］

```C
#include <stdio.h>
#include <stdlib.h>

// 定义一个数据类型（模拟数组）
struct Arr
{
    int *pBase; // 存储的是数组的第一个元素的地址
    int len; // 数组所能容纳的最大元素的个数
    int cnt; // 当前数组有效元素的个数
};

typedef enum {
    ArrSortDesc = 0,
    ArrSortASC = 1
} ArrSort;

void init_arr(struct Arr *pArr, int length); // 初始化
int append_arr(struct Arr *pArr, int val); // 追加
int insert_arr(struct Arr *pArr, int pos, int val); // 插入
int delete_arr(struct Arr *pArr, int pos); // 返回删除的值
int get(struct Arr *pArr, int pos); // 获取数组元素
int is_empty(struct Arr *pArr); // 数组是否为空
int is_full(struct Arr *pArr); // 数组是否已满
void sort_arr(struct Arr *pArr, ArrSort sortType); // 排序数组元素
void show_arr(struct Arr *pArr); // 打印数组
int inversion_arr(struct Arr *pArr); // 倒置数组

int main(void)
{
    struct Arr pArr;
    init_arr(&pArr, 6);
    append_arr(&pArr, 1);
    append_arr(&pArr, 2);
    append_arr(&pArr, 3);
    append_arr(&pArr, 4);
    append_arr(&pArr, 9);
    append_arr(&pArr, 33);
    show_arr(&pArr);
    inversion_arr(&pArr);
    show_arr(&pArr);
    sort_arr(&pArr, ArrSortDesc);
    show_arr(&pArr);
    sort_arr(&pArr, ArrSortASC);
    show_arr(&pArr);
}

void init_arr(struct Arr *pArr, int length)
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if(NULL == pArr->pBase)
    {
        exit(-1);
    }
    pArr->len = length;
    pArr->cnt = 0;
}

int is_empty(struct Arr *pArr)
{
    return (0 == pArr->cnt) ? 1 : 0;
}

void show_arr(struct Arr *pArr)
{
    if(is_empty(pArr))
    {
        printf("数组为空！\n");
    }
    else
    {
        for (int i = 0; i<pArr->cnt; i++) {
            printf("%d\t", pArr->pBase[i]);
        }
        printf("\n");
    }
}

int is_full(struct Arr *pArr)
{
    if(pArr->len == 0)
        exit(-1);
    return pArr->cnt == pArr->len ? 1 : 0;
}

int append_arr(struct Arr *pArr, int val)
{
    if(is_full(pArr))
    {
        printf("数组已经塞满了！\n");
        return 0;
    }
    else
    {
        int index = pArr->cnt;
        pArr->pBase[index] = val;
        pArr->cnt ++;
        return 1;
    }
}

int insert_arr(struct Arr *pArr, int pos, int val)
{
    if (is_empty(pArr))
    {
        printf("数组为空！\n");
        return 0;
    }
    
    if(pos < 0 || pos > pArr->cnt)
    {
        printf("超出数组元素索引\n");
        return 0;
    }
    
    // 移位
    for (int i = pArr->cnt; i > pos; i--)
    {
        pArr->pBase[i] = pArr->pBase[i-1];
    }
    
    pArr->pBase[pos] = val;
    pArr->cnt ++;
    
    return 1;
}

int delete_arr(struct Arr *pArr, int pos)
{
    if (is_empty(pArr)) {
        printf("数组为空!\n");
        exit(-1);
    }
    
    if (0 > pos || pos > (pArr->cnt-1)) {
        printf("pos不合法！\n");
        exit(-1);
    }
    
    int willDeleteValue = pArr->pBase[pos];
    
    for (int i = pos; i < (pArr->cnt - 1); i++) {
        pArr->pBase[i] = pArr->pBase[i+1];
    }
    
    
    pArr->cnt --;
    
    return willDeleteValue;
}

int get(struct Arr *pArr, int pos)
{
    if (is_empty(pArr))
    {
        printf("数组为空！\n");
        exit(-1);
    }
    
    if (0 > pos || pos > pArr->cnt-1) {
        printf("超出数组索引！\n");
        exit(-1);
    }
    
    return pArr->pBase[pos];
}

int inversion_arr(struct Arr *pArr)
{
    if (is_empty(pArr))
    {
        printf("数组为空！\n");
        return 0;
    }
    
    for (int i = 0; i < pArr->cnt/2; i++)
    {
        int current = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[pArr->cnt-1-i];
        pArr->pBase[pArr->cnt-1-i] = current;
    }
    
    return 1;
}

void sort_arr(struct Arr *pArr, ArrSort sortType)
{
    if (is_empty(pArr))
    {
        printf("数组为空！\n");
        exit(-1);
    }
    
    for (int i = 0; i < pArr->cnt; i++) {
        for (int j = i+1; j < pArr->cnt; j++) {
            if (sortType == ArrSortDesc) {
                if (pArr->pBase[i] < pArr->pBase[j]) {
                    int current = pArr->pBase[i];
                    pArr->pBase[i] = pArr->pBase[j];
                    pArr->pBase[j] = current;
                }
            } else {
                if (pArr->pBase[i] > pArr->pBase[j]) {
                    int current = pArr->pBase[i];
                    pArr->pBase[i] = pArr->pBase[j];
                    pArr->pBase[j] = current;
                }
            }
            
        }
    }
}
```

Demo在`code`文件夹内