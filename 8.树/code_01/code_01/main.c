//
//  main.c
//  code_01
//
//  Created by 伟明 毕 on 1/21/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
    char data;
    struct BTNode *pLChild;
    struct BTNode *pRChild;
} BTNode;

// 根据上图创建一个二叉树
BTNode *CreateBTree(void);

// 先序输出二叉树
void preTraverseBTree(BTNode *);

// 中序输出二叉树
void midTraverseBTree(BTNode *);

// 后序输出二叉树
void afterTraverseBTree(BTNode *);

int main(int argc, const char * argv[]) {
    
    BTNode *pT = CreateBTree();
    
    // 调试
    preTraverseBTree(pT);
    midTraverseBTree(pT);
    afterTraverseBTree(pT);
    
    return 0;
}

BTNode *CreateBTree(void)
{
    BTNode *pA = (BTNode *)malloc(sizeof(BTNode));
    BTNode *pB = (BTNode *)malloc(sizeof(BTNode));
    BTNode *pC = (BTNode *)malloc(sizeof(BTNode));
    BTNode *pD = (BTNode *)malloc(sizeof(BTNode));
    BTNode *pE = (BTNode *)malloc(sizeof(BTNode));
    
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    
    pA->pLChild = pB;
    pA->pRChild = pC;
    pB->pLChild = pB->pRChild = NULL;
    pC->pLChild = pD;
    pC->pRChild = NULL;
    pD->pLChild = NULL;
    pD->pRChild = pE;
    pE->pLChild = pE->pRChild = NULL;
    
    return pA;
}

// 先序输出二叉树
void preTraverseBTree(BTNode *pT)
{
    /*
    1. 先访问根节点
    2. 再先序访问左子树
    3. 再先序访问右子树
     */
    if (pT) {
        printf("%c\n", pT->data);
        if (pT->pLChild) {
            preTraverseBTree(pT->pLChild);
        }
        
        if (pT->pRChild) {
            preTraverseBTree(pT->pRChild);
        }
    }
}

// 中序输出二叉树
void midTraverseBTree(BTNode *pT)
{
    /*
     1. 中序遍历左子树
     2. 再访问根节点
     3. 再中序遍历右子树
     */
    if (pT) {
        if (pT->pLChild) {
            midTraverseBTree(pT->pLChild);
        }
        
        printf("%c\n", pT->data);
        
        if (pT->pRChild) {
            midTraverseBTree(pT->pRChild);
        }
    }
}

// 后序输出二叉树
void afterTraverseBTree(BTNode *pT)
{
    /*
     1. 中序遍历左子树
     2. 中序遍历右子树
     3. 再访问根节点
     */
    if (pT) {
        if (pT->pLChild) {
            midTraverseBTree(pT->pLChild);
        }
        
        if (pT->pRChild) {
            midTraverseBTree(pT->pRChild);
        }
        
        printf("%c\n", pT->data);
    }
}

