//
//  BiTree.h
//  dataStructure
//
//  Created by 杨 on 16/4/19.
//  Copyright © 2016年 funnyhux. All rights reserved.
//

#ifndef BiTree_h
#define BiTree_h
#include <iosfwd>
#include "c.h"
#include "BiTNode.h"
enum Tags {Left,Right};
enum style {Pre,In,Post};
template <typename T>
void Visit(BiTNode<T> *c)
{
    cout<<c->data<<' ';
}
template <typename T>
void InputFromFile(ifstream &f, T &c)
{
    f>>c;
}
template <typename T>
void Input(T &c)
{
    cin>>c;
}

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
    // HIJL###K###
    void createBiTreeFromFile(std::ifstream &f)
    {
        T e;
        InputFromFile(f, e);
        if (e == '#') {
            return;
        }
        root = new BiTNode<T>();
        assert(root != nullptr);
        root->data = e;
        BiTree<T> lchild, rchild;
        lchild.createBiTreeFromFile(f);
        rchild.createBiTreeFromFile(f);
        root->lchild = lchild.root;
        lchild.root = nullptr;
        root->rchild = rchild.root;
        rchild.root = nullptr;
    }
    bool BiTreeEmpty() const
    {
        return  root == nullptr;
    }
    int BiTreeDepth(BiTNode<T>* t) const
    {
        
        if (nullptr == t) {
            return 0;
        }else{
            int i,j;
            i = BiTreeDepth(t->lchild);
            j = BiTreeDepth(t->rchihld);
            return i > j ? i+1 : j+1;
        }
        
    }
    // 前序非递归（利用栈）遍历
    void preOrderTraverse(void(*visit)(BiTNode<T>*))const
    {
        
    }
    // 中序非递归（利用栈）遍历
    void inOrderTraverse(void(*visit)(BiTNode<T>*))const
    {
        
    }
    // 后序非递归（利用栈）遍历
    void postOrderTraverse(void(*visit)(BiTNode<T>*))const
    {
        
    }
    // 层序遍历
    void levelOrderTraverse(void(*visit)(BiTNode<T>*))const
    {
        
    }
    // 递归遍历
    void orderTraverse(BiTNode<T>* t,style model,void(*visit)(BiTNode<T>*))const
    {
        
    }
    BiTNode<T>* getRoot() const
    {
        return root;
    }
    // 插入（p称为c的子节点）
    bool insertChild(BiTNode<T>*p,bool LR,BiTNode<T>*c)
    {
        
    }
    // 删除t的左或右子树
    bool deleteChild(BiTNode<T>* t,bool LR)
    {
        
    }
    T getValue(BiTNode<T>* t)const
    {
        return t->data;
    }
    void setValue(BiTNode<T>* t,T value)
    {
        t->data = value;
    }
    BiTNode<T>* getParent(BiTNode<T>* t)const
    {
        return nullptr;
    }
    // 返回t的左右子树
    void getChild(BiTNode<T>* t,BiTNode<T>* &lchild,BiTNode<T>* &rchild)const
    {
        
    }
    // 返回t的左右兄弟节点
    bool getSibling(BiTNode<T>* t,BiTNode<T>* &sib,bool LR)const
    {
        return true;
    }
    
    
};
#endif /* BiTree_h */
