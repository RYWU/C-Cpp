//
//  main.c
//  GCD of BigInt.c
//
//  Created by WILLIAM on 3/4/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    char ch = 0;
    int array1[101] = {0};
    int array2[101] = {0};

    while ( (ch = getchar()) ) {
        int i = 0;
        if (ch == ' ') {
            break;
        }
        array1[i] = atoi(&ch);
        i++;
    }
    while ((ch = getchar())) {
        int i = 0;
        if (ch == ' ') {
            break;
        }
        array2[i] = atoi(&ch);
        i++;
    }
    
    printf("%d\n", array1[1]);
    printf("%d\n", array2[1]);
    
    
    return 0;
}
