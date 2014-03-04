//
//  main.cpp
//  Run time test.cpp
//
//  Created by WILLIAM on 3/3/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <assert.h>
using namespace std;

#define ITEM_NUMBERS 1000000

int main(int argc, char *argv[])
{
    int array[ITEM_NUMBERS] = {0};
    for (int i = 0; i < ITEM_NUMBERS; i++){
        array[i] = ITEM_NUMBERS - i;
    }
    
    clock_t start, stop; // Start timer.
    double t = 0.0;
    assert( (start = clock()) != -1 );
    
    sort(array, array + sizeof(array)/sizeof(int));

    stop = clock(); // Stop timer.
    t = (double)(stop-start)/CLOCKS_PER_SEC;
    
    cout << "Run time: " << t << endl;
    
    return EXIT_SUCCESS;
}
