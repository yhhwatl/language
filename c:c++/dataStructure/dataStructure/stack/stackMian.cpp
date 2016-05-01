//
//  stackMian.cpp
//  dataStructure
//
//  Created by funnyhux on 16/1/2.
//  Copyright © 2016年 funnyhux. All rights reserved.
//

#include "c.h"
#include "Function.h"
#include "SqStack.h"
#include "LinkStack.h"
#include "Evaluate.h"
#include "Hanoi.h"
#include "Point.h"
//进制转换
void conversion(int m,int n)
{
    LinkStack<int> ssi;
    while (m/n) {
        ssi.push(m%n);
        m = m/n;
    }
    ssi.push(m%n);
    ssi.traverse(print);
}


int main()
{
    printf("hello stack\n");
//    LinkStack<int> ssi;
//    ssi.push(2);
//    ssi.push(3);
//    ssi.push(4);
//    ssi.push(1);
//    int g = 0;
//    ssi.pop(g);
//    if (!ssi.empty()) {
//        ssi.top(g);
//        int len = ssi.length();
//        cout<<len<<endl;
//        ssi.clear();
//        ssi.traverse(print);
//    }
//    conversion(8,2);
    Hanoi h;
    int n = 64;
    int p[3] = {1,2,3};
    //递归求解
    h.fhanoi(n,p[0],p[1],p[2]);
    //非递归求解
    h.fhanoi(n,p[0],p[2]);
    return 0;
}