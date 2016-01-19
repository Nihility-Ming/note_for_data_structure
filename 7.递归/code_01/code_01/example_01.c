//
//  example_01.c
//  code_01
//
//  Created by 伟明 毕 on 1/19/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include "example_01.h"

int plus(int n)
{
    if (n == 1) {
        return 1;
    }
    
    return n+plus(n-1);
}

int _plus(int n)
{
    int val = 0;
    for (int i = 1; i<=100; i++) {
        val = val + i;
    }
    
    return val;
}

int factorial(int n)
{
    if (n == 1) {
        return 1;
    }
    
    return n * factorial(n-1);
}

int _factorial(int n)
{
    int val = 1;
    for (int i = 1; i<=n; i++) {
        val *= i;
    }
    return val;
}
