//
//  main.c
//  code_01
//
//  Created by 伟明 毕 on 1/19/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include <stdio.h>
#include "example_01.h"
#include "example_03.h"

int main(int argc, const char * argv[]) {
    int _100 = plus(100000);
    printf("1加到100之和是：%d\n", _100);
    
    int _5 = factorial(5);
    printf("1加到5的阶乘：%d\n", _5);
    
    hannuota_main();
    
    return 0;
}
