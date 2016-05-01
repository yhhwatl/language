//
//  LinkStack.h
//  dataStructure
//
//  Created by funnyhux on 16/1/2.
//  Copyright © 2016年 funnyhux. All rights reserved.
//
/**
 * 栈：先进后出的线性表；链式储存结构实现。
 */
#ifndef LinkStack_h
#define LinkStack_h
#include "AStack.h"
#include "LNode.h"
template <class T>
class LinkStack:public AStack<T> {
    
public:
    LinkStack()
    {
        p_top = p_base = nullptr;
        ui_length = 0;
    }
    virtual ~LinkStack()
    {
        LNode<T> *t = p_top;
        while (t) {
            delete t;
            t = t->next;
        }

        ui_length = 0;
    }
    //向栈顶插入新元素
    bool push(T e)
    {
        LNode<T> *t = new LNode<T>();
        if (!t) {
            return false;
        }
        t->data = e;
        if (p_top == nullptr) {
            p_base = p_top = t;
        }
        t->next = p_top;
        p_top = t;
        ui_length++;
        p_base->next = nullptr;
        return true;
        
    };
    //栈不为空则删除栈顶用e返回其值
    bool pop(T &e)
    {
        if (p_top==nullptr) {
            return false;
        }else{
            e = p_top->data;
            p_top = p_top->next;
            ui_length--;
            return true;
        }
    };
    //栈不为空则用e返回栈顶元素
    bool top(T &e)const
    {
        if (p_top==nullptr) {
            return false;
        }else{
            e = p_top->data;
            return true;
        }
    };
    void clear()
    {
        p_top = p_base = nullptr;
        ui_length = 0;
    };
    bool empty()const
    {
        return p_top==nullptr;
    };
    int length()const
    {
        return ui_length;
    };
    //遍历栈内元素调用visit
    void traverse(void(*visit)(T*))const
    {
        LNode<T> *t = p_top;
        while (t) {
            visit(&(t->data));
            t = t->next;
        }
    };
private:
    LNode<T>  *p_base;
    LNode<T>  *p_top;
    unsigned int ui_length;
};

#endif /* LinkStack_h */
