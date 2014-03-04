//
//  main.cpp
//  sort.cpp
//
//  Created by WILLIAM on 3/3/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.

//  原形：
//  #include <algorithm>
//  sort(Start, End);
//  e.g: sort(array, array + sizeof(array)/sizeof(int) );

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[])
{
    int array[10] = {9, 10, 1, 7, 8, 3, 2, 6, 5, 4};
/*    cout << "Enter 10 numbers";
    for (int i = 0; i < 10; i++){
        cin >> array[i];
    }
*/
    cout << "=======Sort======="<< endl;
    sort(array, array+sizeof(array)/sizeof(int));
    for (int i = 0; i < 10; i++){
        cout << array[i] << endl;
    }
    cout << endl << "=======Reverse======"<< endl;
    reverse(array, array+sizeof(array)/sizeof(int));
    for (int i = 0; i < 10; i++){
        cout << array[i] << endl;
    }
    
    
    return 0;
}

