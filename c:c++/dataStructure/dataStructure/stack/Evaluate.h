//
//  Evaluate.h
//  dataStructure
//
//  Created by funnyhux on 16/1/2.
//  Copyright © 2016年 funnyhux. All rights reserved.
//
/**
* 表达式求值
* 思路：
* 比较运算符的优先级
* > pop两个运算符 push运算结果
* <＝ 继续入栈
* ＃ 。。。＃ ＃碰见即运算结束
*/
#ifndef Evaluate_h
#define Evaluate_h
#include "c.h"
#include "SqStack.h"
template <class T>
class Evaluate:public SqList<T> {
    
public:
    T expression(string s)
    {
        SqStack<char> OPTR(10);//储存运算符
        SqStack<T> OPND(10);//储存运算数
        s = s + '#';//表达式尾加＃作为标记
        int a,b,d;
        int i = 0;
        char c,x;
        OPTR.push('#');//运算符栈底
        c = s[i++];
        OPTR.top(x);
        while (c!='#' || x!='#') {
            if (In(c))
            {
                switch (precede(x, c))
                {
                    case '<':
                        OPTR.push(c);
                        if(i<s.length())
                            c = s[i++];
                        break;
                    case '=':
                        OPTR.pop(x);
                        if(i<s.length())
                            c = s[i++];
                        break;
                    case '>':
                        OPTR.pop(x);
                        OPND.pop(b);
                        OPND.pop(a);
                        OPND.push(operate(a,x,b));
                        break;
                    default:
                        break;
                }
            }else
            {
                if (c>='0' && c<='9')//c是数字
                {
                    d = 0;
                    while (c>='0' && c<='9')//c是连续数字
                    {
                        d = d*10+c-'0';
                        if (i<s.length())
                        {
                            c = s[i++];
                        }
                    }
                    OPND.push(d);//数字d压栈
                }else//非法字符
                {
                    assert(0);
                }
            }
        }
        OPND.pop(a);
        if (!OPND.empty())
        {
            assert(0);
        }
        return a;
    }
private:
    char precede(char t1,char t2)
    {
        char cRet = '=';
        switch (t2) {
            case '+':
            case '-':
                if (t1 == '(' || t1 == '#')
                    cRet = '>';
                else
                    cRet = '<';
                break;
            case '*':
            case '/':
                if (t1 == '(' || t1 == '#' || t1 == '+' ||t1 == '-')
                    cRet = '<';
                else
                    cRet = '>';
                break;
            case '(':
                if (t1 == ')')
                   assert(0);
                else
                    cRet = '<';
                break;
            case ')':
                switch (t1) {
                    case '(':
                        cRet = '=';
                        break;
                    case '#':
                        assert(0);
                    default:
                        cRet = '>';
                        break;
                }
                break;
            case '#':
                if(t1 == '#')
                {
                    cRet = '=';
                    break;
                }else if(t1 == '(')
                {
                    assert(0);
                }else
                {
                    cRet = '>';
                }
                break;
            default:
                assert(0);
                break;
        }
        return cRet;
    }
    bool In(char c)
    {
        bool bRet = false;
        switch (c) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
            case '#':
                bRet = true;
                break;
            default:
                bRet = false;
                break;
        }
        return bRet;
    }
    T operate(T a,char thera,T b)
    {
        switch (thera) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                assert(0);
                break;
        }
    }
};

#endif /* Evaluate_h */
