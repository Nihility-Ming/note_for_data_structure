//
//  main.c
//  直接插入排序
//
//  Created by 伟明 毕 on 1/23/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include <stdio.h>

void example_01(int *nums, int length)
{
    for (int i=2; i<length; i++)
    {
        if (nums[i] < nums[i-1])
        {
            nums[0] = nums[i];
            int j;
            for (j = i-1; nums[j]>nums[0]; j--)
            {
                nums[j+1] = nums[j];
            }
            
            nums[j+1] = nums[0];
        }
    }
}

int main(int argc, const char * argv[]) {

    int nums[] = {0, 5, 3, 4, 6, 2};
    int length = sizeof(nums)/sizeof(nums[0]);
    
    example_01(nums, length);
    
    for (int i = 0; i<length; i++) {
        printf("%d\t", nums[i]);
    }
    
    printf("\n");

    return 0;
}
