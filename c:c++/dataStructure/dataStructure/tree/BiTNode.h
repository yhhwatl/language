//
//  BiTNode.h
//  dataStructure
//
//  Created by 杨 on 16/4/17.
//  Copyright © 2016年 funnyhux. All rights reserved.
//

#ifndef BiTNode_h
#define BiTNode_h

template <typename T> struct BiTNode
{
    T data;
    BiTNode<T> *lchild,*rchild;
};
#endif /* BiTNode_h */
