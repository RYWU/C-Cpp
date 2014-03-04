//
//  main.cpp
//  GCD of BigInt
//
//  Created by WILLIAM on 3/4/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc, const char * argv[])
{
    char ch = 1;
    int *array1 = new int;
    int *array2 = new int;
    
    while ((ch = getchar())) {
        int i = 0;
        if (ch == ' ') {
            break;
        }
        int *array1 = (int *)malloc(sizeof(int));
        array1[i] = atoi(&ch);
        i++;
    }
    while ((ch = getchar())) {
        int i = 0;
        if (ch == ' ') {
            break;
        }
        int *array2 = (int *)malloc(sizeof(int));
        array2[i] = atoi(&ch);
        i++;
    }
    
    cout << array1[0] << endl;
    cout << array2[0] << endl;
    
    return 0;
}
