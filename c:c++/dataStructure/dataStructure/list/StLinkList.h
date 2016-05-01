//
//  StLinkList.h
//  dataStructure
//
//  Created by funnyhux on 15/12/30.
//  Copyright © 2015年 funnyhux. All rights reserved.
//
/**
 * 静态链表：事先开辟一块连续的内存，内部使用链式结构组织数据。
 * 应用：对象池，哈夫曼树，内部排序等。
 * 结构：使用链表和备用链表,备用链表表头的link＝0,使用链表表尾的link=0。
 */
#ifndef StLinkList_h
#define StLinkList_h
#include "AList.h"
const int MAX_SIZE = 10;
template<class T>
class StLinkList:public AList<T>  {
    struct component
    {
        T data;
        int link;//下一节点的index
    };
    component SL[MAX_SIZE];//静态数组
    void init()
    {
        int i = 0;
        SL[0].link = 0;//空链表的表头
        SL[MAX_SIZE-1].link = 1;//备用链表的第一个单元
        for (i=1; i<MAX_SIZE-2; i++) {
            SL[i].link = i + 1;//其余单元链成以SL[MAX_SIZE-1]为表头的备用链表
        }
        SL[MAX_SIZE-2].link = 0;//0:备用链表的表头 固定在静态数组末尾
    }
    int NEW()
    {
        int index = SL[MAX_SIZE-1].link;//备用链表第一个节点的index
        if (index!=0) {//备用链表非空
            SL[MAX_SIZE-1].link = SL[index].link;//备用链表的头节点指向备用链表的第二个节点
        }
        return index;//返回新开辟节点的坐标
    }
    void DELETE(int k)
    {// 将index＝k的空闲节点回收到备用链表中，成为备用链表的第一个节点。
        SL[k].link = SL[MAX_SIZE-1].link;//index＝k保存备用节点的头节点
        SL[MAX_SIZE-1].link = k;//新回收的节点作为备用链表头节点，原头节点放到index＝k处
    }
public:
    StLinkList()
    {
        init();
    }
    void clearList()
    {
        int j,i = SL[MAX_SIZE-1].link;
        while (i) {//遍历备用链表到尾部
            j = i;
            i = SL[i].link;
        }
        SL[j].link = SL[0].link;//使用的链表第一个节点接到备用链表尾部，整个数组都为备用链表。
        SL[0].link = 0;//链表空
    }
    //线性表是否为空
    bool listEmpty()const
    {
        return SL[0].link == 0;
    };
    //返回第一个与e满足关系eq()的数据元素的位序,若不存在返回0
    int locateElem(T e,bool(*eq)(T,T))const
    {
        int i = 1;
        int userHeadIndex = SL[0].link;
        while (userHeadIndex) {
            if (eq(e,SL[userHeadIndex].data)) {
                return i;
            }
            userHeadIndex = SL[userHeadIndex].link;
            i++;
        }
        return 0;

    };
    // 若e与表中某数据元素满足eq()的关系，用pre_e保存其前驱值
    bool priorElem(T e,bool(*eq)(T,T),T &pre_e)const
    {
        int userHeadIndex = SL[0].link;
        while (userHeadIndex) {
            int nextIndex = SL[userHeadIndex].link;
            if (nextIndex) {
                if (eq(e,SL[nextIndex].data)) {
                    pre_e = SL[userHeadIndex].data;
                    return true;
                }
            }
            userHeadIndex = SL[userHeadIndex].link;
        }
        return false;
    };
    // 若e与表中某数据元素满足eq()的关系，用next_e保存其后继值
    bool nextElem(T e,bool(*eq)(T,T),T &next_e)const
    {
        int nextIndex = SL[0].link;
        int index = 0;
        while (nextIndex) {
            if (eq(e,SL[index].data)) {
                next_e = SL[nextIndex].data;
                return true;
            }
            index = nextIndex;
            nextIndex = SL[nextIndex].link;
        }
        return false;
    };
    //删除第i位元素值，用e保存它的值
    bool listDelete(int i,T &e);
    //遍历T表中元素依次访问visit
    void listTraverse(void(*visit)(T*))
    {
        int i = SL[0].link;
        int j = 0;
        while (i!=0) {
            visit(&(SL[j].data));
            j = i;
            i = SL[i].link;
        }
    };
    //用e返回第i个数据元素值
    virtual bool getElem(int i,T &e)const
    {
        int index = 0;
        int nextIndex = SL[0].link;
        int j = 0;
        while (nextIndex) {
            if (index == i) {
                e = SL[j].data;
                return true;
            }
            j = nextIndex;
            nextIndex = SL[nextIndex].link;
            index++;
        }
        return true;
    };
    //在第i个元素之前插入元素e
    virtual bool listInsert(int i,T e)
    {
        int m,k = 0;
        for (m = 1; m<i; m++) {
            k = SL[k].link;
            if (k==0) {
                break;
            }
        }
        if (m<i) {
            return false;
        }else{
            m = NEW();
            if (m) {
                SL[m].data = e;
                SL[m].link = SL[k].link;
                SL[k].link = m;
                return true;
            }
            return false;
        }
        return false;
    };
    bool push_back(T e)
    {
        int nextIndex = SL[0].link;
        int index = 0;
        while (nextIndex) {
            index = nextIndex;
            nextIndex = SL[nextIndex].link;
        }
        
        int newIndex = NEW();
        if (newIndex == 0) {
            return false;
        }
        SL[index].link = newIndex;
        SL[index].data = e;
        SL[newIndex].link = 0;
        return true;
    }
    bool push_front(T e)
    {
        int newIndex = NEW();
        if (newIndex == 0) {
            return false;
        }
        SL[newIndex].link = SL[0].link;
        SL[newIndex].data = SL[0].data;
        SL[0].link = newIndex;
        SL[0].data = e;
        return true;
    }
    //返回线性表长度
    virtual int listLength()const
    {
        int len = 0;
        int userHeadIndex = SL[0].link;
        while (userHeadIndex) {
            userHeadIndex = SL[userHeadIndex].link;
            len++;
        }
        return len;
    };
    
    
};

#endif /* StLinkList_h */
