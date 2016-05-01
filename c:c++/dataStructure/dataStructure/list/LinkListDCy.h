//
//  LinkListDCy.h
//  dataStructure
//
//  Created by funnyhux on 15/12/30.
//  Copyright © 2015年 funnyhux. All rights reserved.
//
/**
 * 双向循环链表
 */
#ifndef LinkListDCy_h
#define LinkListDCy_h
#include "AList.h"
template <class T>
class LinkListDCy:public AList<T> {
    LDNode<T> *head;
    LDNode<T> *tail;
    int length;
public:
    LinkListDCy()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    };
    virtual ~LinkListDCy()
    {
        clearList();
    };
    //清空线性表
    void clearList()
    {
        LDNode<T> *t = head;
        while (t!=tail) {
            delete t;
            t = t->next;
        }
        delete tail;
        tail = nullptr;
        length = 0;
    };
    //线性表是否为空
    bool listEmpty()const
    {
        return head!=nullptr;
    };
    //返回第一个与e满足关系eq()的数据元素的位序,若不存在返回0
    int locateElem(T e,bool(*eq)(T,T))const
    {
        LDNode<T> *t = head;
        int index = 1;
        while (t!=tail) {
            if (eq(e,t->data)) {
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
        LDNode<T> *t = head;
        if (t==nullptr || tail==nullptr) {
            return false;
        }
        while (t!=tail) {
            if (eq(e,t->data)) {
                pre_e = t->pre->data;
                return true;
            }
            t = t->next;
        }
        return false;
    };
    // 若e与表中某数据元素满足eq()的关系，用next_e保存其后继值
    bool nextElem(T e,bool(*eq)(T,T),T &next_e)const
    {
        LDNode<T> *t = head;
        if (t==nullptr || tail==nullptr) {
            return false;
        }
        while (t!=tail) {
            if (eq(e,t->data)) {
                next_e = t->next->data;
                return true;
            }
            t = t->next;
        }
        return false;

    };
    //删除第i位元素值，用e保存它的值
    bool listDelete(int i,T &e)
    {
        if (i<0||i>length) {
            return false;
        }else if(i == 0)
        {
            if (length==1) {
                delete head;
                head = tail = nullptr;
                length--;
                return true;
            }else if(length == 2){
                delete head;
                head = tail;
                tail->next = tail;
                tail->pre = tail;
                length--;
                return true;
            }else{
                LDNode<T> *t = head;
                int index = 0;
                while (t!=tail) {
                    if (index == i) {
                        LDNode<T> *pt = t->pre;
                        LDNode<T> *nt = t->next;
                        delete t;
                        t = nullptr;
                        pt->next = nt;
                        nt->pre = pt;
                        length--;
                        return true;
                    }
                    index++;
                    t = t->next;
                }
            }
        }else{
            
            LDNode<T> *t = head;
            int index = 0;
            while (t!=tail) {
                if (index == i) {
                    LDNode<T> *pt = t->pre;
                    LDNode<T> *nt = t->next;
                    delete t;
                    t = nullptr;
                    pt->next = nt;
                    nt->pre = pt;
                    length--;
                    return true;
                }
                index++;
                t = t->next;
            }
        }
        return false;
    };
    //遍历T表中元素依次访问visit
    void listTraverse(void(*visit)(T*))const
    {
        LDNode<T> *t = head;
        while (t!=tail) {
            visit(&(t->data));
            t = t->next;
        }
        visit(&(tail->data));
    };
    //用e返回第i个数据元素值
    virtual bool getElem(int i,T &e)const
    {
        LDNode<T> *t = head;
        int index = 0;
        while (t!=tail) {
            if (index ==i) {
                e = t->data;
                return true;
            }
            t = t->next;
        }
        return false;
    };
    //在第i个元素之前插入元素e
    virtual bool listInsert(int i,T e)
    {
        if (i<0||i>length) {
            return false;
        }else if(i == 0){
            push_font(e);
            return true;
        }else{
            if (length==0) {
                push_font(e);
                return true;
            }
            LDNode<T> *t = head;
            int index = 0;
            while (t!=tail) {
                if (index == i) {
                    LDNode<T> *pt = t->pre;
                    LDNode<T> *nw = new LDNode<T>();
                    nw->data = e;
                    nw->pre = pt;
                    pt->next = nw;
                    nw->next = t;
                    t->pre = nw;
                    length++;
                    return true;
                }
                index++;
                t = t->next;
            }
        }
        return false;
    };
    bool push_back(T e)
    {
        if (head == nullptr) {
            head = tail = new LDNode<T>();
            if (head==nullptr) {
                return false;
            }
            head->data = tail->data = e;
            head->next = tail;
            head->pre = tail;
            tail->pre = head;
            tail->next = head;
            length++;
            return true;
        }else
        {
            LDNode<T> *t = new LDNode<T>();
            if (t==nullptr) {
                return false;
            }
            t->data = e;
            tail->next = t;
            t->pre = tail;
            tail = t;
            tail->next = head;
            head->pre = tail;
            length++;
        }
        return false;
    }
    bool push_font(T e)
    {
        if (head == nullptr) {
            head = tail = new LDNode<T>();
            if (head==nullptr) {
                return false;
            }
            head->data = tail->data = e;
            head->next = tail;
            head->pre = tail;
            tail->pre = head;
            tail->next = head;
            length++;
            return true;
        }else
        {
            LDNode<T> *t = new LDNode<T>();
            t->data = e;
            head->pre = t;
            t->next = head;
            head = t;
            head->pre = tail;
            tail->next = head;
            length++;
            return true;
        }
        return false;
    }
    //返回线性表长度
    virtual int listLength()const
    {
        return length;
    };
};

#endif /* LinkListDCy_h */
