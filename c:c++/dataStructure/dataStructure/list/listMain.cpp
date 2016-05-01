//
//  listMain.cpp
//  dataStructure
//
//  Created by funnyhux on 15/12/27.
//  Copyright © 2015年 funnyhux. All rights reserved.
//

#include "c.h"
#include "Function.h"
#include "LinkList.h"
#include "LinkListCy.h"
struct student
{
    string name;
    int score;
};
inline void printStr(student *s)
{
    cout<<endl<<setw(6)<<s->name<<": "<<s->score;
}
inline void printName(student *s)
{
    cout<<s->name;
}
inline bool equal(student s1,student s2)
{
    return s1.name == s2.name;
}
void mergeList(const LinkList<student>&s1,const LinkList<student>&s2,LinkList<student>&s3)
{
    LNode<student> *tmp_s1 = s1.root,*tmp_s2 = s2.root;
    while (tmp_s1 && tmp_s2) {
        if (tmp_s1->data.score < tmp_s2->data.score) {
            
            s3.listInsert(0, (tmp_s1->data));
            tmp_s1 = tmp_s1->next;
        }else
        {
            s3.listInsert(0, (tmp_s2->data));
            tmp_s2 = tmp_s2->next;
        }
    }
    while (tmp_s2) {
        s3.listInsert(0, (tmp_s2->data));
        tmp_s2 = tmp_s2->next;
    }
    
    while (tmp_s1) {
        s3.listInsert(0, (tmp_s1->data));
        tmp_s1 = tmp_s1->next;
    }
}
list<student> mergeList(list<student>s1,list<student>s2)
{
    list<student>::iterator it1 = s1.begin();
    list<student>::iterator it2 = s2.begin();
    list<student> s3;
    while (it1!=s1.end() && it2!=s2.end()) {
        if ((*it1).score > (*it2).score)
        {
            s3.push_back(*it1);
            it1++;
        }else
        {   s3.push_back(*it2);
            it2++;
        }
    }
    while (it1!=s1.end()) {
        s3.push_back(*it1);
        it1++;
    }
    while (it2!=s2.end()) {
        s3.push_back(*it2);
        it2++;
    }
    return s3;
}
//void mergeList(list<student> &s1,const list<student>s2)
//{
//    list<student>::iterator it1 = s1.begin();
//    list<student>::const_iterator it2 = s2.begin();
//    while (it1!=s1.end() && it2!=s2.end()) {
//        if ((*it1).score < (*it2).score) {
//            s1.insert(it1, *it2);
//            it2++;
//            it1++;
//        }else
//        {
//            it1++;
//        }
//    }
//    while (it2!=s2.end()) {
//        s1.push_back(*it2);
//        it2++;
//    }
//}
int main()
{
    std::cout << "listMain!\n";
    LinkList<student> st;
    student s1[5];
    s1[0].name = "李1";s1[0].score = 90;
    s1[1].name = "王3";s1[1].score = 87;
    s1[2].name = "张2";s1[2].score = 80;
    s1[3].name = "钱4";s1[3].score = 60;
    s1[4].name = "杨5";s1[4].score = 40;
//    for (int in=0; in<5; in++) {
//        st.listInsert(0, s1[in]);
//    }
//   
//    cout<<endl<<"st:"<<endl;
//    st.listTraverse(printStr);
    student tmp,pre_tmp,next_tmp;
    tmp.name = "张2";
//    st.listDelete(0, tmp);
//    int index = st.locateElem(tmp, equal);
//    st.priorElem(tmp, equal, pre_tmp);
//    st.nextElem(tmp, equal, next_tmp);
    
    LinkList<student> st2;
    student s2[5];
    s2[0].name = "李11";s2[0].score = 92;
    s2[1].name = "王33";s2[1].score = 89;
    s2[2].name = "张22";s2[2].score = 68;

//    for (int in=0; in<3; in++) {
//        st2.listInsert(0, s2[in]);
//    }
//    cout<<endl<<"st2:"<<endl;
//    st2.listTraverse(printStr);
//    
//    LinkList<student> s3;
//    mergeList(st, st2, s3);
//    cout<<endl<<"s3:"<<endl;
//    s3.listTraverse(printStr);
//    
//    list<student> ls1;
//    for (int i=0; i<5; i++) {
//        ls1.push_back(s1[i]);
//    }
//    list<student> ls2;
//    for (int i=0; i<3; i++) {
//        ls2.push_back(s2[i]);
//    }
//    list<student> ls3 = mergeList(ls1, ls2);
//    
//    LinkList<student> s4;
//    s4.push_back(s2[1]);
//    s4.push_back(s2[2]);
//    cout<<endl<<"s4:"<<endl;
//    s4.listTraverse(printStr);
//    
//    LinkList<student> s5;
//    s5.push_font(s2[1]);
//    s5.push_font(s2[2]);
//    cout<<endl<<"s5:"<<endl;
//    s5.listTraverse(printStr);
    LinkListCy<student> lcs;
    for (int i=0; i<5; i++) {
        lcs.listInsert(0, s1[i]);
    }
    cout<<endl<<"lcs:"<<endl;
    lcs.listTraverse(printStr);
    lcs.listDelete(1, tmp);
    cout<<endl<<"lcs1:"<<endl;
    lcs.listTraverse(printStr);
    return 0;
}
