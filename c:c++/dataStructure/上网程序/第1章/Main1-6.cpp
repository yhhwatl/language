//Main1-6.cpp ��֤����ͷ��㵥����LinkListNH<T>��ĳ�Ա����
#include "C.h"
#include "LinkListNH.h"
typedef int T;
#include "Func1-1.cpp"
void main()
{
	LinkListNH<T> L;
	bool i;
	int j, k;
	for(j=1; j<=5; j++)
		L.ListInsert(j, j);
	cout<<"��L�ı�β���β���1��5��L=";
	L.ListTraverse(print);
	cout<<"��="<<L.ListLength()<<endl;
	for(j=6; j>=5; j--)
	{
		k=L.LocateElem(j, equal);
		if(k)
			cout<<"ֵΪ"<<j<<"��Ԫ���Ǳ�L�ĵ�"<<k<<"��Ԫ�أ�";
		else
			cout<<"û��ֵΪ"<<j<<"��Ԫ�أ�";
		i=L.ListDelete(j, equal);
		if(i==false)
			cout<<"ɾ��Ԫ��"<<j<<"ʧ�ܣ������ڴ�Ԫ�أ�"<<endl;
		else
			cout<<"�ɹ�ɾ��Ԫ��"<<j<<endl;
	}
	cout<<"ɾ��Ԫ�غ�L=";
	L.ListTraverse(print);
	L.ClearList();
	cout<<"��ձ�L�󣬱�L�ĳ���="<<L.ListLength()<<endl;
}

