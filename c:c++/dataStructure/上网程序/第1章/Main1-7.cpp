//Main1-7.cpp ��֤����ͷ���˫ѭ������DLinkListNH<T>��ĳ�Ա����
#include "C.h"
#include "DLinkListNH.h"
typedef int T;
#include "Func1-1.cpp"
void main()
{
	DLinkListNH<T> L;
	bool i;
	int j;
	T e;
	for(j=1; j<=5; j++)
		L.ListInsert(j, j);
	cout<<"��L�ı�β���β���1��5��L=";
	L.ListTraverse(print);
	cout<<"��="<<L.ListLength()<<endl;
	for(j=0; j<=3; j++)
	{
		i=L.ListDelete(j, e);
		if(i==false)
			cout<<"ɾ����"<<j<<"��Ԫ��ʧ�ܣ������ڴ�Ԫ�أ�"<<endl;
		else
			cout<<"�ɹ�ɾ����"<<j<<"��Ԫ��"<<endl;
	}
	cout<<"ɾ��3��Ԫ�غ�L=";
	L.ListTraverse(print);
	L.ClearList();
	cout<<"��ձ�L�󣬱�L�ĳ���="<<L.ListLength()<<endl;
}

