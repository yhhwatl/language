//Main2-2.cpp ��֤��ջDLinkStack<T>��ĳ�Ա����
#include "C.h"
#include "DLinkStack.h"
typedef int T;
#include "Func1-1.cpp"
void main()
{
	int j;
	DLinkStack<T> S;
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

