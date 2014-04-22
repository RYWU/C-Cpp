//
//  main.c
//  fgets
//
//  Created by WILLIAM on 2/15/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, const char * argv[])
{
    char str[128] = "\0";
    FILE *fp;
    
    fp = fopen("out", "w");
    assert(fp != NULL);
    
    fgets(str, 10, stdin); //Read '10' char from 'stdin', and save in 'str';
    fputs(str, fp);
    
//    printf("%s", str);
    
    return 0;
}

