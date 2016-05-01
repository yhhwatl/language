//
//  AList.h
//  dataStructure
//
//  Created by funnyhux on 15/12/27.
//  Copyright © 2015年 funnyhux. All rights reserved.
//
/**
 *线性表是一种抽象的数据结构，
 *根据储存结构可分为：顺序，链式和静态链式
 *无论储存结构如何，逻辑结构都有以下性质:
 *除第一个元素外,其他元素都有一个前驱；
 *除最后一个元素外,其他元素都有一个后继；
 */
#ifndef AList_h
#define AList_h

template <class T>
class AList
{
public:
    virtual ~AList(){};
    //清空线性表
    void clearList();
    //线性表是否为空
    bool listEmpty()const;
    //返回第一个与e满足关系eq()的数据元素的位序,若不存在返回0
    int locateElem(T e,bool(*eq)(T,T))const;
    // 若e与表中某数据元素满足eq()的关系，用pre_e保存其前驱值
    bool priorElem(T e,bool(*eq)(T,T),T &pre_e)const;
    // 若e与表中某数据元素满足eq()的关系，用next_e保存其后继值
    bool nextElem(T e,bool(*eq)(T,T),T &next_e)const;
    //删除第i位元素值，用e保存它的值
    bool listDelete(int i,T &e);
    //遍历T表中元素依次访问visit
    void listTraverse(void(*visit)(T*))const;
    //用e返回第i个数据元素值
    virtual bool getElem(int i,T &e)const = 0;
    //在第i个元素之前插入元素e
    virtual bool listInsert(int i,T e) = 0;
    //返回线性表长度
    virtual int listLength()const = 0;
};

#endif /* AList_h */
