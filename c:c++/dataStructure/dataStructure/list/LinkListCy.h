//
//  LinkListCy.h
//  dataStructure
//
//  Created by funnyhux on 15/12/29.
//  Copyright © 2015年 funnyhux. All rights reserved.
//
/**
 * 单向循环链表
 */

#ifndef LinkListCy_h
#define LinkListCy_h
#include "AList.h"
template <class T>
class LinkListCy:public AList<T> {
    
    LNode<T> *tail;//尾指针
   
public:
    LinkListCy()
    {
        tail = nullptr;
    };
    virtual ~LinkListCy()
    {
        clearList();
        delete tail;
        tail = nullptr;
    }
    LNode<T> * getTail()
    {
        return tail;
    }
    //清空线性表
    void clearList()
    {
        LNode<T> *p,*q;
        tail = tail->next;
        p = tail->next;
        while (p!=tail) {
            q = p->next;
            delete p;
            p = q;
        }
        tail->next = tail;
    };
    //线性表是否为空
    bool listEmpty()const
    {
        return tail->next == tail;
    };
    //返回第一个与e满足关系eq()的数据元素的位序,若不存在返回0
    int locateElem(T e,bool(*eq)(T,T))const
    {
        LNode<T> *t = tail->next;
        int index = 0;
        while (t) {
            if (eq(t->data,e)) {
                return index;
            }
            index++;
            t = t->next;
        }
        return 0;
    };
    // 若e与表中某数据元素满足eq()的关系，用pre_e保存其前驱值
    bool priorElem(T e,bool(*eq)(T,T),T &pre_e)const
    {
        LNode<T> *t = tail->next;
        LNode<T> *pre_t = tail;
        int index = 0;
        while (t!=tail) {
            if (eq(t->data,e)) {
                pre_e = t;
                return true;
            }
            index++;
            pre_e = t;
            t = t->next;
        }
        return false;
    };
    // 若e与表中某数据元素满足eq()的关系，用next_e保存其后继值
    bool nextElem(T e,bool(*eq)(T,T),T &next_e)const
    {
        LNode<T> *t = tail->next;
        while (t!=tail) {
            if (eq(t->data,e)) {
                next_e = t->next;
                return true;
            }
            t = t->next;
        }
        return false;
    };
    //删除第i位元素值，用e保存它的值
    bool listDelete(int i,T &e)
    {
        LNode<T> *tmp = tail->next;
        int index = 0;
        if (i==0) {
            if (tmp == tail) {
                delete tail;
                tail = nullptr;
                return true;
            }else{
                LNode<T> *t = tmp;
                tail->next = t->next;
                delete t;
                t = nullptr;
                return true;
            }
            
        }else
        {
            LNode<T> *pre_t = tail;
            while (tmp!=tail) {
                if (index== i) {
                    LNode<T> *t = tmp->next;
                    e = tmp->data;
                    pre_t->next = t;
                    delete tmp;
                    tmp = nullptr;
                    return true;
                }
                index++;
                pre_t = tmp;
                tmp = tmp->next;
            }
            
            delete tail;
            tail = tmp->next;
            pre_t->next = tail;
            return true;
        }
        
        return false;
    };
    //遍历T表中元素依次访问visit
    void listTraverse(void(*visit)(T*))const
    {
        LNode<T> *tmp = tail->next;
        while (tmp!=tail) {
            visit(&(tmp->data));
            tmp = tmp->next;
        }
        visit(&(tmp->data));
       
    };
    //用e返回第i个数据元素值
    virtual bool getElem(int i,T &e)const
    {
        LNode<T> *tmp = tail->next;
        int index = 0;
        while (tmp!=tail) {
            if (index == i) {
                e = tmp->data;
                return true;
            }
            tmp = tmp->next;
            index++;
        }
        return false;
    };
    //在第i个元素之前插入元素e
    virtual bool listInsert(int i,T e)
    {
        if (i<0) {
            return false;
        }else if(i == 0){
            LNode<T> *t = new LNode<T>();
            assert(t!=nullptr);
            t->data = e;
            if (tail==nullptr) {
                tail = t;
                t->next = tail;
                return true;
            }
            if (tail->next == tail) {
                tail->next = t;
                t->next = tail;
                return true;
            }
            LNode<T> *tmp = tail->next;
            tail->next = t;
            t->next = tmp;
            return true;
        }else
        {
            LNode<T> *t = new LNode<T>();
            assert(t!=nullptr);
            t->data = e;
            if (tail->next == tail) {
                tail->next = t;
                t->next = tail;
                return true;
            }
            LNode<T> *tmp = tail->next;
            int index = 0;
            while (tmp!=tail) {
                if (index+1 == i) {
                    LNode<T> *next_tmp = tmp->next;
                    tmp->next = t;
                    t->next = next_tmp;
                    return true;
                }
                index++;
                tmp = tmp->next;
            }
        }
        return false;
    };
    //返回线性表长度
    virtual int listLength()const
    {
        int i = 0;
        LNode<T> *p = tail->next;
        while (p!=tail) {
            i++;
            p = p->next;
        }
        return i;
    };
};

#endif /* LinkListCy_h */
