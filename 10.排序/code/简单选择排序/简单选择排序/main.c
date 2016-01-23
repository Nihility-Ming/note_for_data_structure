//
//  main.c
//  简单选择排序
//
//  Created by 伟明 毕 on 1/23/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include <stdio.h>

void example_01(int *nums, int length)
{
    int min = 0;
    for (int i = 0; i<length-1; i++) {
        min = i;
        for (int j = i+1; j<length; j++)
        {
            if (nums[min] > nums[j])
            {
                min = j;
            }
        }
        
        if (i != min) {
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int nums[] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    int length = sizeof(nums)/sizeof(nums[0]);

    example_01(nums, length);
    
    for (int i = 0; i<length; i++) {
        printf("%d\t", nums[i]);
    }
    
    printf("\n");
    
    return 0;
}
