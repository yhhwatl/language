//Main2-1.cpp ��֤˳��ջSqStack<T>��ĳ�Ա����
#include "C.h"
#include "SqStack.h"
typedef int T;
#include "Func1-1.cpp"
void main()
{
	int j;
	SqStack<T> S(3);
	T e;
	for(j=1; j<=5; j++)
		S.Push(j);
	cout<<"ջ��Ԫ����ջ�׵�ջ������Ϊ";
	S.StackTraverse(print);
	S.Pop(e);
	cout<<"������ջ��Ԫ��e="<<e;
	cout<<"��ջ�շ�"<<boolalpha<<S.StackEmpty()<<endl;
	S.GetTop(e);
	cout<<"�µ�ջ��Ԫ��e="<<e<<"��ջ�ĳ���Ϊ"<<S.StackLength()<<endl;
	S.ClearStack();
	cout<<"���ջ��ջ�շ�"<<boolalpha<<S.StackEmpty()<<endl;
}

