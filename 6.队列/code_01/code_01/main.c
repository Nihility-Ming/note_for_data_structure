//
//  main.c
//  code_01
//
//  Created by 伟明 毕 on 1/18/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 定义队列的长度
static const int kQueue_len = 6;

// 定义队列的结构体
typedef struct Queue {
    int *pBase;
    int front;
    int rear;
} Queue;

// 初始化
void init(Queue *, int);

// 入队
int en_queue(Queue *, int);

// 出队
int out_queue(Queue *, int *);

// 遍历
void traverse_queue(Queue *);

// 判断队列是否已满
int is_full(Queue *);

// 判断队列是否为空
int is_empty_queue(Queue *q);

int main(void)
{
    Queue q = {0};
    init(&q, kQueue_len);
    en_queue(&q, 1);
    en_queue(&q, 2);
    en_queue(&q, 3);
    en_queue(&q, 4);
    en_queue(&q, 5);
    en_queue(&q, 6);
    en_queue(&q, 7);
    en_queue(&q, 8);
    traverse_queue(&q);
    
    int pVal;
    
    if (out_queue(&q, &pVal)) {
        printf("出队成功，队列出队元素是%d\n", pVal);
    } else {
        printf("出队失败！\n");
    }
    
    traverse_queue(&q);
    
    return 0;
}

void init(Queue *q, int len)
{
    q->pBase = (int *)malloc(sizeof(int) * len);
    q->front = 0;
    q->rear = 0;
}

int en_queue(Queue *q, int val)
{
    if (is_full(q)) {
        return 0;
    } else {
        q->pBase[q->rear] = val;
        
        // 入队，rear加1
        q->rear = (q->rear + 1) % kQueue_len;
        
        return 1;
    }
}

int out_queue(Queue *q, int *pVal)
{
    if (is_empty_queue(q)) {
        return 0;
    }
    
    *pVal = q->pBase[q->front];
    
    // 出队，front加1
    q->front = (q->front + 1)  % kQueue_len;
    
    return 1;
}

int is_full(Queue *q)
{
    // rear紧挨着front一个元素的之间距的时候，队列就满了
    if (((q->rear + 1) % kQueue_len) == q->front) {
        return 1;
    }
    
    return 0;
}

int is_empty_queue(Queue *q)
{
    // 只要front等于rear，队列就为空
    if (q->front == q->rear) {
        return 1;
    }
    return 0;
}

void traverse_queue(Queue *q)
{
    int i = q->front;
    
    while (i != q->rear) {
        printf("%d\t", q->pBase[i]);
        
        // front位置不断加1取余链表长度，等于rear的时候，遍历完毕
        i = (i+1) % kQueue_len;
    }
    
    printf("\n");
}
