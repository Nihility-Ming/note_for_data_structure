//
//  main.c
//  code_01
//
//  Created by 伟明 毕 on 1/17/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *pNext;
} NODE, *PNODE;

// 栈
typedef struct Stack {
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void init(PSTACK); // 初始化
void push(PSTACK, int); // 压栈
int pop(PSTACK, int *); // 出栈, 成功返回1，否则返回0。pop的值返回形参中(int *)
void traverse(PSTACK);
int is_empty(PSTACK pS);
void clean(PSTACK); // 清空栈

int main(int argc, const char * argv[]) {
    
    STACK S; // STACK等价于struct Statck
    
    init(&S);
    
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    
    int val;
    pop(&S, &val);
    
    traverse(&S);
    printf("pop value: %d\n", val);
    
    clean(&S);
    traverse(&S);
    
    return 0;
}

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (NULL == pS->pTop) {
        printf("动态内存分配失败！\n");
        exit(-1);
    } else {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
}

void push(PSTACK pS, int val)
{
    // 新建一个链表元素
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    
    // 栈操作
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

void traverse(PSTACK pS)
{
    if (is_empty(pS)) {
        printf("此栈为空！\n");
        return;
    }
    
    PNODE p = pS->pTop;
    while (p != pS->pBottom) {
        printf("%d\t", p->data);
        p = p->pNext;
    }
    
    printf("\n");
    
    return;
}

int pop(PSTACK pS, int *val)
{
    if (!is_empty(pS)) {
        PNODE r = pS->pTop;
        
        if (NULL != val) {
            *val = r->data;
        }
        pS->pTop = r->pNext;
        
        free(r);
        r = NULL;
        
        return 1;
    }
    return 0;
}

int is_empty(PSTACK pS)
{
    if (pS->pTop == pS->pBottom) {
        return 1;
    }
    
    return 0;
}

void clean(PSTACK pS)
{
    if (is_empty(pS)) {
        printf("此栈为空！\n");
        return;
    }
    
    PNODE p = pS->pTop;
    PNODE q = NULL;
    
    while (p != pS->pBottom) {
        q = p->pNext;
        free(p);
        p = q;
    }
    
    pS->pTop = pS->pBottom;
}

