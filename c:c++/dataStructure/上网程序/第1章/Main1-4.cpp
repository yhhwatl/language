//Main1-4.cpp ��֤��ѭ������LinkListCy<T>��ĳ�Ա����
#include "C.h"
#include "LinkListCy.h"
typedef int T;
#include "Func1-1.cpp"
void main()
{
	LinkListCy<T> L;
	T e, e0;
	bool i;
	int j, k;
	for(j=1; j<=5; j++)
		i=L.ListInsert(1, j);
	cout<<"��L�ı�ͷ���β���1��5��L=";
	L.ListTraverse(print);
	cout<<"L�Ƿ�գ�"<<boolalpha<<L.ListEmpty()<<"����L�ĳ���=";
	cout<<L.ListLength()<<endl;
	for(j=0; j<=1; j++)
	{
		k=L.LocateElem(j, equal);
		if(k)
			cout<<"ֵΪ"<<j<<"��Ԫ���ǵ�"<<k<<"��Ԫ��"<<endl;
		else
			cout<<"û��ֵΪ"<<j<<"��Ԫ�أ�";
	}
	for(j=1; j<=2; j++)
	{
		L.GetElem(j, e0);
		i=L.PriorElem(e0, equal, e);
		if(i)
			cout<<"Ԫ��"<<e0<<"��ǰ��Ϊ"<<e<<endl;
		else
			cout<<"Ԫ��"<<e0<<"��ǰ����";
	}
	for(j=L.ListLength(); j>=L.ListLength()-1; j--)
	{
		L.GetElem(j, e0);
		i=L.NextElem(e0, equal, e);
		if(i)
			cout<<"Ԫ��"<<e0<<"�ĺ��Ϊ"<<e<<endl;
		else
			cout<<"Ԫ��"<<e0<<"�޺�̣�";
	}
	k=L.ListLength();
	for(j=k+1; j>=k; j--)
	{
		i=L.ListDelete(j, e);
		if(i)
			cout<<"ɾ����"<<j<<"��Ԫ�سɹ�����ֵΪ"<<e<<endl;
		else
			cout<<"ɾ����"<<j<<"��Ԫ��ʧ�ܣ������ڴ�Ԫ�أ���";
	}
	cout<<"�������L��Ԫ�أ�";
	L.ListTraverse(print);
	L.ClearList();
	cout<<"���L��L�Ƿ�գ�"<<boolalpha<<L.ListEmpty()<<"����L�ĳ���=";
	cout<<L.ListLength()<<endl;
}

