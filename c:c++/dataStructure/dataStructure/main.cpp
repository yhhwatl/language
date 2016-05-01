//
//  main.cpp
//  dataStructure
//
//  Created by funnyhux on 15/12/29.
//  Copyright © 2015年 funnyhux. All rights reserved.
//

#include <stdio.h>
struct node
{
    node *next;
    int data;
    node(int d)
    {
        data = d;
        next = nullptr;
    }
};
class fList {
    int length;
    node* root;
public:
    fList()
    {
        root = nullptr;
        length = 0;
    }
    ~fList()
    {
        node *tmp = root;
        while (tmp) {
            delete tmp;
            tmp = tmp->next;
        }
    }
    bool insert(int index,int d)
    {
        if (index<0) {
            return false;
        }else if(index == 0) {
            if (root == nullptr) {
                node *n = new node(d);
                root = n;
            }else
            {
                node *n = new node(d);
                n->next = root;
                root = n;
            }
            length++;
            return true;
        }else{
            
        }
        
        return false;
    }
};
int main()
{
    fList *fl = new fList();
    
    for (int i=0; i<10; i++) {
        fl->insert(0, i);
    }
    printf("hello\n");
    
    return 0;
}