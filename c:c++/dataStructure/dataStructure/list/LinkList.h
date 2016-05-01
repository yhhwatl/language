//
//  LinkList.h
//  dataStructure
//
//  Created by funnyhux on 15/12/27.
//  Copyright © 2015年 funnyhux. All rights reserved.
//
/**
 * 普通链表
 */
#ifndef LinkList_h
#define LinkList_h
#include "LNode.h"
#include "AList.h"
template <class T>
class LinkList:AList<T> {
    friend void mergeList(const LinkList<T>&s1,const LinkList<T>&s2,LinkList<T>&s3);
    LNode<T> *root;
    int length;
public:
    LinkList()
    {
        length = 0;
        root = nullptr;
        
    };
    virtual ~LinkList()
    {
        clearList();
    };
    
    //清空线性表
    void clearList()
    {
        LNode<T> *tmp = root;
        while (tmp) {
            delete tmp;
            tmp = tmp->next;
        }
    };
    //线性表是否为空
    bool listEmpty()const
    {
        return length>0;
    };
    //返回第一个与e满足关系eq()的数据元素的位序,若不存在返回0
    int locateElem(T e,bool(*eq)(T,T))const
    {
        LNode<T> *tmp = root;
        int i = 0;
        while (tmp) {
            if (eq(e,(tmp->data))) {
                return i;
            }
            tmp = tmp->next;
            i++;
        }
        return 0;
    };
    // 若e与表中某数据元素满足eq()的关系，用pre_e保存其前驱值
    bool priorElem(T e,bool(*eq)(T,T),T &pre_e)const
    {
        LNode<T> *tmp = root;
        if (!tmp) {
            return false;
        }
        if (!tmp->next) {
            return false;
        }
        LNode<T> *pre_tmp;
        while (tmp->next) {
            pre_tmp = tmp;
            if (eq(e,(tmp->next->data))) {
                pre_e = (pre_tmp->data);
                return true;
            }
            tmp = tmp->next;
        }
        return false;
        
    };
    // 若e与表中某数据元素满足eq()的关系，用next_e保存其后继值
    bool nextElem(T e,bool(*eq)(T,T),T &next_e)const
    {
        LNode<T> *tmp = root;
        if (!tmp) {
            return false;
        }
        if (!tmp->next) {
            return false;
        }
        LNode<T> *next_tmp;
        while (tmp->next) {
            next_tmp = tmp->next;
            if (eq(e,(tmp->data))) {
                next_e = (next_tmp->data);
                return true;
            }
            tmp = tmp->next;
            
        }
        return false;
    };
    //删除第i位元素值，用e保存它的值
    bool listDelete(int i,T &e)
    {
        LNode<T> *tmp = root;
        if (i<0 || i>length) {
            return false;
        }
        if (i==0) {
            e = (tmp->data);
            delete root;
            root = tmp->next;
            length--;
            return i;
        }
        int index = 0;
        while (tmp) {
            if (index+1 == i) {
                LNode<T> *next_tmp = tmp->next;
                e = (tmp->next->data);
                delete tmp->next;
                tmp->next = next_tmp->next;
                length--;
                return true;
            }
            tmp = tmp->next;
            index++;
        }
        return false;
    };
    //遍历T表中元素依次访问visit
    void listTraverse(void(*visit)(T*))const
    {
        LNode<T> *tmp = root;
        while (tmp) {
            visit(&(tmp->data));
            tmp = tmp->next;
        }
    };
    //用e返回第i个数据元素值
    virtual bool getElem(int i,T &e)const
    {
        LNode<T> *tmp = root;
        int index = 0;
        while (tmp) {
            if (index == i) {
                e = (tmp->data);
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
        
        if (i==0) {
            if (root==nullptr) {
                LNode<T> *t = new LNode<T>();
                t->data = e;
                root = t;
                length++;
                return true;
            }else
            {
                LNode<T> *t = new LNode<T>();
                t->data = e;
                t->next = root;
                root = t;
                length++;
                return true;
            }
        }else
        {
            int index = 0;
            LNode<T> *tmp = root;
            while (tmp) {
                if (index+1 == i) {
                    LNode<T> *t = new LNode<T>();
                    LNode<T> *next_tmp = tmp->next;
                    t->data = e;
                    tmp->next = t;
                    t->next = next_tmp;
                    length++;
                    return true;
                }else
                {
                    index++;
                    tmp = tmp->next;
                }
            }
        }
        return false;
    };
    //在尾部加一节点
    bool push_back(T e)
    {
        if (root==nullptr) {
            root = new LNode<T>();
            if (!root) {
                return false;
            }
            root->data = e;
            return true;
        }
        LNode<T> *tmp = root;
        while (tmp->next) {
            tmp = tmp->next;
        }
        LNode<T> *t = new LNode<T>();
        if (!t) {
            return false;
        }
        t->data = e;
        tmp->next = t;//钩子钩着下一个  tmp = t t赋值给tmp
        return true;
    };
    //在表头添加节点
    bool push_font(T e)
    {
        if (root == nullptr) {
            root = new LNode<T>();
            if (!root) {
                return false;
            }
            root->data = e;
        }else
        {
            LNode<T> *t = new LNode<T>();
            if (!t) {
                return false;
            }
            t->next = root;
            t->data = e;
            root = t;
        }
        return true;
    }
    
    //返回线性表长度
    virtual int listLength()const
    {
        return length;
    };
    
};
#endif /* LinkList_h */
