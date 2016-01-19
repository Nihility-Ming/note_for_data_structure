//
//  example_03.c
//  code_01
//
//  Created by 伟明 毕 on 1/19/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include "example_03.h"

// 汉诺塔

void hannuota(int n, char A, char B, char C)
{
    if(1 == n) {
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
    } else {
        hannuota(n-1, A, C, B);
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
        hannuota(n-1, B, A, C);
    }
}

void hannuota_main(void)
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';
    int n;
    
    printf("请输入要移动盘子的个数：\n");
    scanf("%d", &n);
    hannuota(n, ch1, ch2, ch3);
}

