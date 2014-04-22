//
//  main.c
//  Count from data
//
//  Created by WILLIAM on 3/13/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(int argc, const char * argv[])
{
    int count = 0;
    FILE *fp;
    fp = fopen("balance.txt", "r");
    assert(fp != NULL);
    
    long temp = 0;
    while (fscanf(fp, "%ld", &temp) != EOF) {
        if (temp < 100000000000){
            count++;
        }
    }
    fclose(fp);
    printf("%d", count);
    
    return 0;
}

