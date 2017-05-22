//
//  AStrTest.cpp
//  dataStructure
//
//  Created by watl on 2017/3/26.
//  Copyright © 2017年 funnyhux. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int maxSubLen(const string cs)
{
    int len = 0;
    for (int i = 0; i < cs.length(); i++) {
        for (int j = 0; j < i; j++) {
            
        }
    }
    return len;
}
int main()
{
    cout<<"hello str \n";
    string str = "abbcabcbcc";
    int n = maxSubLen(str);
    printf("n = %d\n",n);
    return 0;
}
