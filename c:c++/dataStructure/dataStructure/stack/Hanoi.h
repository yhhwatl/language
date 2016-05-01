//
//  HANOI.h
//  dataStructure
//
//  Created by funnyhux on 16/1/2.
//  Copyright © 2016年 funnyhux. All rights reserved.
//
/**
 * 汉诺塔问题 递归实现
 * 递归：直接或间接调用自身的函数称为递归
 * 特点：降阶 有出口
 * 说明：任何递归都可以利用 循环和栈 转换为非递归调用
 * 思路：
 * 如果只有一个金片，则把该金片从源移动到目标棒，结束。
 * 如果有n个金片，则把前n-1个金片移动到辅助的棒，然后把自己移动到目标棒，最后再把前n-1个移动到目标棒。
 * 对于汉诺塔问题的求解，可以通过以下三个步骤实现：
 * 将塔A上的n-1个碟子借助塔C先移到塔B上。
 * 把塔A上剩下的一个碟子移到塔C上。
 * 将n-1个碟子从塔B借助塔A移到塔C上。
 */
#ifndef HANOI_h
#define HANOI_h
#include "c.h"
#include "SqStack.h"
//栈元素数据(非递归用到)
struct HanoiData
{
    int x;//盘子最初所在的塔柱的编号(1-3)
    int y;//盘子最后所在塔柱的编号(1-3)与x不相同
    int n;//盘子数量
};
class Hanoi
{
public:
     Hanoi()
    {
        count = 0;
        
    }
    //将塔座x上的编号为1-n的n个圆盘按规则移到塔座z上
    //y用做辅助塔座(递归求解)
    void fhanoi(int n,int x,int y,int z)const
    {
         //hanoi(n-1,one,three,two);n-1块，从1到2，只看第2个和第4个参数，one，two就是从1到2.
         //move(one,three);
         //hanoi(n-1,two,one,three);n-1块，从2到3，只看第2个和第4个参数，two，three就是从2到3.
        if(n == 1)
            move(x, z, 1);
        else
        {
            fhanoi(n-1, x, z, y);
            move(x, z, n);
            fhanoi(n-1, y, x, z);
        }
    }
    //将塔座x上的编号1-n的n个圆盘借助于辅助塔座按规则移到塔座y上（非递归求解）
    void fhanoi(int n,int x,int y)
    {
        assert(n>0 && x>0 && x<4 && y>0 && y<4 && x!=y);
        hd.n = n;
        hd.x = x;
        hd.y = y;
        count = 0;
        while (hd.n!=0 || !stacks.empty())
        {
            while (hd.n!=0)
            {
                hd.n--;
                stacks.push(hd);
                hd.y ^= hd.x;
            }
            if (!stacks.empty())
            {
                hd = stacks.top();
                stacks.pop();
                move(hd.x, hd.y, hd.n+1);
                hd.x ^= hd.y;
            }
        }
    }
private:
    void move(int x,int z,int n)const
    {
        cout<<"第"<<(++count)<<"步：将"<<n<<"号盘从"<<x<<"座移到"<<z<<"座"<<endl;
    }
    
    HanoiData hd;//栈结构(非递归用到)
    static int count;//移动次数
//    SqStack<HanoiData> *stacks;
    stack<HanoiData> stacks;
};
int Hanoi::count = 0;
#endif /* HANOI_h */
