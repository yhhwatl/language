//
//  mainTree.cpp
//  dataStructure
//
//  Created by 杨 on 16/4/19.
//  Copyright © 2016年 funnyhux. All rights reserved.
//

#include <stdio.h>
#include "BiTNode.h"
#include "BiTree.h"
#include<iostream>
typedef char T;
using namespace std;
int main(int args,char**argv)
{
    cout<<args<<endl;
    cout<<argv[0]<<endl;
    BiTree<T> t;
    ifstream fin("res/F4-1.txt");
    if (!fin.is_open()) {
        cout<<"error opening file"<<endl;
        exit(1);
    }
    t.createBiTreeFromFile(fin);
    fin.close();
    return 0;
}