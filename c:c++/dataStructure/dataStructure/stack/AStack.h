//
//  AStack.h
//  dataStructure
//
//  Created by funnyhux on 16/1/2.
//  Copyright © 2016年 funnyhux. All rights reserved.
//
/**
 * 栈：先进后出的线性表；可用顺序储存结构，也可用链式储存结构。
 */
#ifndef AStack_h
#define AStack_h
//接口
template <class T>
class AStack
{
public:
   
    //向栈顶插入新元素
    bool push(T e)const;
    //栈不为空则删除栈顶用e返回其值
    bool pop(T &e)const;
    //栈不为空则用e返回栈顶元素
    bool top(T &e)const;
    void clear();
    bool empty()const;
    int length()const;
    //遍历栈内元素调用visit
    void traverse(void(*visit)(T*))const;
};

#endif /* AStack_h */
