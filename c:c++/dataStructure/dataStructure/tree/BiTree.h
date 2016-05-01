//
//  BiTree.h
//  dataStructure
//
//  Created by 杨 on 16/4/19.
//  Copyright © 2016年 funnyhux. All rights reserved.
//

#ifndef BiTree_h
#define BiTree_h
#include "BiTNode.h"
enum Tags {Left,Right};
enum style {Pre,In,Post};
template <typename T>
struct StackElem {
    BiTNode<T> *p;
    Tags flag;
};
template <typename D> class SOSTree;
template <typename T>
class BiTree{
    friend SOSTree<struct S>;
protected:
    BiTNode<T> *root;
private:
    void DestroyBiTree(BiTNode<T>* &t)
    {
        
    }
public:
    BiTree()
    {
        root = nullptr;
    }
    ~BiTree()
    {
        DestroyBiTree(root);
    }
//    void CreateBiTreeFromFile(ifstream &f)
//    {
//        
//    }
};
#endif /* BiTree_h */
