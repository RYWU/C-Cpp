//
//  main.c
//  Clock
//
//  Created by WILLIAM on 3/31/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int main(int argc, const char * argv[])
{
    clock_t start_time, end_time; // 記得#include <time.h>
    float total_time = 0;
    start_time = clock(); // Start
    
    /*  TARGET FUNCTION  */
    for (int i = 0; i < 10000; i++){
        printf("%d\n", i);
    }
    /*  TARGET FUNCTION  */
    
    end_time = clock(); // End
    total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC;
    printf("Time : %f sec \n", total_time);
    
    
    return 0;
}

