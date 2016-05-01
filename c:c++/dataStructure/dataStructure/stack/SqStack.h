//
//  SqStack.h
//  dataStructure
//
//  Created by funnyhux on 16/1/2.
//  Copyright © 2016年 funnyhux. All rights reserved.
//
/**
 * 栈：先进后出的线性表；顺序储存结构实现。
 */
#ifndef SqStack_h
#define SqStack_h
#include "AStack.h"
template <class T>
class SqStack:public AStack<T> {
    
public:
    SqStack(int l)
    {
        p_base = new T[l]();
        memset(p_base, 0, l);
        p_top = nullptr;
        ui_size = l;
    }
    virtual ~SqStack()
    {
        ui_size = 0;
        delete []p_base;
        p_base = p_top = nullptr;
    }
    //向栈顶插入新元素
    bool push(T e)
    {
        if (p_top==nullptr) {
            p_top = p_base;
        }else{
            if (ui_size == p_top - p_base + 1) {
                T* p_newbase = new T[ui_size*2]();
                if (nullptr == p_newbase) {
                    return false;
                }
                for (int i=0; i<ui_size; i++) {
                    p_newbase[i] = p_base[i];
                }
                delete p_base;
                p_base = p_newbase;
                //重新开辟内存时地址变了，需要重置栈顶地址
                p_top = p_base + ui_size - 1;
                ui_size = ui_size*2;
            }
            p_top++;
        }
        *p_top = e;
        return true;
    };
    //栈不为空则删除栈顶用e返回其值
    bool pop(T &e)
    {
        if (length() > 0) {
            e = *p_top;
//            *p_top = 0;
            p_top--;
            return true;
        }else{
            return false;
        }
    };
    //栈不为空则用e返回栈顶元素
    bool top(T &e)const
    {
        if (length()>0) {
            e = *p_top;
            return true;
        }else{
            return false;
        }
    };
    void clear()
    {
        while (length()>0) {
            T *rp = p_top;
            p_top--;
            *rp = 0;
            rp = nullptr;
        }
    };
    bool empty()const
    {
        return p_top == nullptr;
    };
    int length()const
    {
        if (p_top!=nullptr) {
            return (int)(p_top - p_base + 1);
        }else{
            return 0;
        }
    };
    //遍历栈内元素调用visit
    void traverse(void(*visit)(T*))const
    {
        for (T *tp = p_top; tp != p_base - 1; tp--) {
            visit(tp);
        }
    };
    
private:
    T *p_base;
    T *p_top;
    unsigned int ui_size;
};

#endif /* SqStack_h */
