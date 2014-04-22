//
//  main.cpp
//  vector
//
//  Created by WILLIAM on 3/10/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
/*  Summary: 
    unsigned int .size 
    void .push_back
    bool .empty
    void .clear
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    string str = {"WILLIAMM "};
    cout  << str << endl;
    
    vector <int> array1;
    array1.push_back(1);
    array1.push_back(3);
    array1.push_back(5);
    for (int i = 0; i < array1.size(); i++){
        cout << array1[i] << "\n";
    }
    
    if (!array1.empty()){
        array1.clear();
    }
    
    vector <int> array2;
    array2.push_back(10);
    array1.push_back(10);
    
    if (array1 == array2){ //判斷兩個array內容是否全相等。
        array1.push_back(100);
    }
    cout << endl;
    for (int i = 0; i < array1.size(); i++){
        cout << array1[i] << "\n";
    }
    
    return 0;
}