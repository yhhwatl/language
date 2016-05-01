//
//  cyListMain.cpp
//  dataStructure
//
//  Created by funnyhux on 15/12/30.
//  Copyright © 2015年 funnyhux. All rights reserved.
//
#include "c.h"
#include "LNode.h"
#include "Function.h"
#include "LinkListCy.h"
#include "LinkListDCy.h"
#include "StLinkList.h"
//约瑟夫环问题
list<int> ysfh(int m,int n)
{
    list<int> ll;
    LinkListCy<int> lin;
    for (int i=0; i<n; i++) {
        lin.listInsert(0, i);
    }
    
    LNode<int> *tail = lin.getTail();
    LNode<int> *t = tail->next;
    int index = 1,a = 0;
    do {
        if (a>=n-1) {
            break;
        }
        if (index == m) {
            int ind = lin.locateElem(t->data, equal);
            ll.push_back(t->data);
            int tmp = 0;
            lin.listDelete(ind, tmp);
            index = 0;
            a++;
        }
        t = t->next;
        index++;
    } while (1);
    return ll;
}
void printInt(int* f)
{
    cout<<*f<<endl;
}
int main()
{
    printf("HELLO\n");
//    list<int> ll = ysfh(15,8);
//    LinkListDCy<int> lldcy;
//    lldcy.push_back(1);
//    lldcy.push_back(2);
//    lldcy.push_font(0);
//    lldcy.listInsert(0, 1);
//    lldcy.listInsert(0, 2);
//    int tmp = 0;
//    lldcy.listDelete(2, tmp);
    int i = 1;
    StLinkList<int> sl;
//    sl.push_back(i);
    sl.push_back(i+1);
    sl.push_back(i+2);
//    sl.push_front(i);
//    sl.push_front(i+1);
//    sl.push_front(i+3);
//    sl.listInsert(0, i+1);
//    sl.listInsert(0, i+2);
    sl.listInsert(1, i+3);
//    sl.getElem(1, i);
    int f;
    sl.nextElem(1,equal,f);
    sl.listTraverse(printInt);
    return 0;
}
