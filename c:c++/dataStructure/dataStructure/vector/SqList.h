//
//  sqlistTest.h
//  dataStructure
//
//  Created by funnyhux on 15/12/27.
//  Copyright © 2015年 funnyhux. All rights reserved.
//

#ifndef sqlistTest_h
#define sqlistTest_h
#include "AList.h"
template <class T>
class SqList:public AList<T> {
    //声明普通函数mergeList为SqList类的友元
    friend void mergeList(const SqList<T>&,const SqList<T>&,SqList<T>&);
    friend void addElem(SqList<T>&,const SqList<T>&);
private:
    T* elem;//首地址
    int length;//表有效长度
    int listSize;//表容量
public:
    //构造容量为k的顺序表
    SqList(int k=1)
    {
        elem = new T[k];
        assert(elem!=nullptr);
        length = 0;
        listSize = k;
    };
    virtual ~SqList()
    {
        delete []elem;
    };
    //清空线性表
    void clearList()
    {
        length = 0;
    };
    //线性表是否为空
    bool listEmpty()const
    {
        return length>0;
    };
    //返回第一个与e满足关系eq()的数据元素的位序,若不存在返回0
    int locateElem(T e,bool(*eq)(T,T))const
    {
        for (int i=0; i<length; ++i) {
            if (eq(e,elem[i])) {
                return i;
            }
        }
        return 0;
    };
    // 若e与表中某数据元素满足eq()的关系，用pre_e保存其前驱值
    bool priorElem(T e,bool(*eq)(T,T),T &pre_e)const
    {
        
        for (int i=1; i<length-1; ++i) {
            if (eq(e,elem[i])) {
                pre_e = elem[i-1];
                return true;
            }
        }
        return false;
    };
    // 若e与表中某数据元素满足eq()的关系，用next_e保存其后继值
    bool nextElem(T e,bool(*eq)(T,T),T &next_e)const
    {
        
        for (int i=0; i<length-1; ++i) {
            if (eq(e,elem[i])) {
                next_e = elem[i+1];
                return true;
            }
        }
        return false;
    };
    //删除第i位元素值，用e保存它的值
    bool listDelete(int i,T &e)
    {
        if (i>=0 && i<length) {
            e = elem[i];
            delete elem[i];
            for (int index = i; index<length-1; ++index) {
                elem[index] = elem[index+1];
            }
            length--;
            return true;
        }
        return false;
    };
    //遍历T表中元素依次访问visit
    void listTraverse(void(*visit)(T*))const
    {
        for (int i=0; i<length; i++) {
            visit(elem+i);
        }
        return;
    };
    //用e返回第i个数据元素值
    virtual bool getElem(int i,T &e)const
    {
        if (i>=0 && i<length) {
            e = elem[i];
            return true;
        }
        return false;

    };
    //在第i个元素之前插入元素e
    virtual bool listInsert(int i,T e)
    {
        if (length == listSize) {
            listSize = listSize*2;
            T *newbase = new T[listSize];
            for (int i = 0; i<length; i++) {
                newbase[i] = elem[i];
            }
            delete []elem;
            elem = newbase;
        }
        if (i>=0) {
            for (int index=length; index>i;--index) {
                elem[index] = elem[index-1];
            }
            elem[i] = e;
            length++;
            return true;
        }
        return false;

    };
    //返回线性表长度
    virtual int listLength()const
    {
        return length;
    };
    
};
#endif /* sqlistTest_h */
