//
//  Function.h
//  dataStructure
//
//  Created by funnyhux on 15/12/27.
//  Copyright © 2015年 funnyhux. All rights reserved.
//

#ifndef Function_h
#define Function_h
#include "SqList.h"
bool equal(int c1,int c2)
{
    return c1 == c2;
}

bool equal(double d1,double d2)
{
    return abs(d1-d2)<1.0e-6;
}

inline void print(int c)
{
    cout<<c<<" ";
}
template <class T>
inline void print(T *c)
{
    cout<<*c<<" ";
}
inline void log(int c)
{
    cout<<c<<"\n";
}
//s1 s2非递减线性表，要求合并成成非递减线性表s3

//void mergeList(const SqList<T>&s1,const SqList<T>&s2,SqList<T>&s3)
//{
//    int len1  = s1.listLength();
//    log(len1);
//};
#endif /* Function_h */
