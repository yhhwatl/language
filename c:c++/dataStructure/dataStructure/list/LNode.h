//
//  LNode.h
//  dataStructure
//
//  Created by funnyhux on 15/12/27.
//  Copyright © 2015年 funnyhux. All rights reserved.
//
/**
 * 链表节点
 */
#ifndef LNode_h
#define LNode_h
template <class T>
struct LNode {
    T data;
    LNode<T> *next;
    LNode()
    {
        next = nullptr;
    }
};
template <class T>
struct LDNode{
    T data;
    LDNode<T> *next;
    LDNode<T> *pre;
    LDNode()
    {
        next = nullptr;
        pre = nullptr;
    }
};

#endif /* LNode_h */
