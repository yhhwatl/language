//
//  main.cpp
//  dataStructure
//
//  Created by funnyhux on 15/12/27.
//  Copyright © 2015年 funnyhux. All rights reserved.
//


#include "c.h"
#include "SqList.h"
#include "Function.h"
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
void mergeList(const SqList<student>&s1,const SqList<student>&s2,SqList<student>&s3)
{
    int len1 = s1.listLength();
    int len2 = s2.listLength();
    int minLen = len1;
    if (len2<len1) {
        minLen = len2;
    }
    SqList<student> ms1 = s1;
    SqList<student> ms2 = s2;
    int index1 = 0,index2 = 0,index = 0;
    for (int i=0; i<len2+len1; i++) {
        if (ms1.elem[index1].score > ms2.elem[index2].score) {
            s3.listInsert(index++, ms1.elem[index1]);
            index1++;
        }else
        {
            s3.listInsert(index++, ms2.elem[index2]);
            index2++;
        }
    }
    if (minLen < len2) {
        for (int i = minLen; i<len2; i++) {
            s3.listInsert(index++, ms2.elem[index2]);
            index2++;
        }
    }else
    {
        for (int i=minLen; i<len1; i++) {
            s3.listInsert(index++, ms1.elem[index1]);
            index1++;
        }
    }
}
void addElem(SqList<student>&s1,const SqList<student>&s2)
{
    int len1 = s1.length;
    int len2 = s2.length;
    int index1 = 0,index2 = 0,index = len1;
    for (int i=0; index1<len1 && index2<len2; i++) {
        if (s2.elem[index2].score != s1.elem[index1].score) {
            s1.listInsert(index++, s2.elem[index2]);
            index1++;index2++;
        }else{
            index2++;
        }
    }
    if (index2>len1) {
        for (int i=len1;index2<len2; i++) {
            s1.listInsert(index, s2.elem[index2]);
            index++;index2++;
        }
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "sqListMain!\n";
//    typedef int T;
//    int j;
//    SqList L;
//    for (j=0; j<5; j++) {
//        L.listInsert(0, j);//表头插入新元素
//    }
//    L.listTraverse(print);//打印
//    cout<<"\n";
//    int tmp;
//    L.getElem(2, tmp);//下标2上的value＝tmp;
//    int n = 0;
//    int index = L.locateElem(n, equal);//0下标4
//    log(tmp);
//    log(index);
//    L.priorElem(3, equal, tmp);
//    log(tmp);//3的前驱是4
//    L.nextElem(1, equal,tmp);
//    log(tmp);//1的后继是0
    
//    bool b;
    SqList<student> s(5);
    student s1[5];
    s1[0].name = "李1";s1[0].score = 90;
//    s1[2].name = "张2";s1[2].score = 80;
    s1[1].name = "王3";s1[1].score = 87;
//    s1[3].name = "钱4";s1[3].score = 60;
//    s1[4].name = "杨5";s1[4].score = 40;
    for (int i=0; i<2;i++) {
        s.listInsert(i,s1[i]);
    }
    s.listTraverse(printStr);
//    student tmp;
//    s.getElem(2, tmp);
//    printName(&tmp);
//    
//    s.priorElem(s1[2], equal, tmp);
//    printName(&tmp);
    SqList<student> l(3);
    student s2[3];
    s2[0].name = "李11";s2[0].score = 90;
    s2[2].name = "张22";s2[2].score = 58;
    s2[1].name = "王32";s2[1].score = 62;
    for (int i=0; i<3;i++) {
        l.listInsert(i,s2[i]);
    }
    l.listTraverse(printStr);
    SqList<student> c(9);
//    mergeList(s,l,c);
//    cout<<endl<<"merge after:"<<endl;
//    c.listTraverse(printStr);
    addElem(s, l);
    cout<<endl<<"add after:"<<endl;
    s.listTraverse(printStr);
    
    
    return 0;
}
