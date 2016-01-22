//
//  main.c
//  冒泡排序
//
//  Created by 伟明 毕 on 1/22/16.
//  Copyright © 2016 伟明 毕. All rights reserved.
//

#include <stdio.h>

// 最原始的写法
void example_01(int *nums, int length)
{
    for (int i = 0; i<length-1; i++)
    {
        for (int j=i+1; j<length; j++)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

// 优化了一点
void example_02(int *nums, int length)
{
    for (int i=0; i<length-1; i++)
    {
        for (int j=length-2; j>=i; j--)
        {
            if (nums[j]>nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

// 最终版
void example_03(int *nums, int length)
{
    int flag = 1;
    
    for (int i=0; (i<length-1) && flag; i++)
    {
        flag = 0;
        for (int j=length-2; j>=i; j--)
        {
            if (nums[j]>nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
            
            flag = 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int nums[] = {9, 1, 5, 8, 3, 7, 4, 6, 2};
    int length = sizeof(nums)/sizeof(nums[0]);
//    example_01(nums, length);
//    example_02(nums, length);
    example_03(nums, length);
    
    for (int i = 0; i<length; i++) {
        printf("%d\t", nums[i]);
    }
    
    printf("\n");
    
    return 0;
}
