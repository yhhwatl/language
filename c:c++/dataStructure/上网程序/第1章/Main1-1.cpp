//Main1-1.cpp ��֤˳���SqList<T>��ĳ�Ա����
#include "C.h"
#include "SqList.h"
//�������пɸ�����Ҫѡ��һ����ֻ��ѡ��һ����������ı�SqList.h
typedef int T;
//typedef double T;//�������µ���������TΪ˫�����ͣ�print()��Ҫ����6��
#include "Func1-1.cpp"
void main()
{
	bool i;
	int j, k;
	T e, e0;
	SqList<T> L;
	for(j=1; j<=5; j++)
		L.ListInsert(1, j);
	cout<<"��L�ı�ͷ���β���1��5��L=";
	L.ListTraverse(print);
	cout<<"L�Ƿ�գ�"<<boolalpha<<L.ListEmpty()<<"����="<<L.ListLength()<<endl;
	L.GetElem(4, e);
	cout<<"��4��Ԫ�ص�ֵΪ"<<e<<endl;
	for(j=L.ListLength(); j<=L.ListLength()+1; j++)
	{
		k=L.LocateElem(j, equal);
		if(k)
			cout<<"ֵΪ"<<j<<"��Ԫ���Ǳ�L�ĵ�"<<k<<"��Ԫ�أ�";
		else
			cout<<"û��ֵΪ"<<j<<"��Ԫ��\n";
	}
	for(j=1; j<=2; j++)
	{
		L.GetElem(j, e);
		i=L.PriorElem(e, equal, e0);
		if(i)
			cout<<"Ԫ��"<<e<<"��ǰ��Ϊ"<<e0<<endl;
		else
			cout<<"Ԫ��"<<e<<"��ǰ����";
	}
	for(j=L.ListLength()-1; j<=L.ListLength(); j++)
	{
		L.GetElem(j, e);
		i=L.NextElem(e, equal, e0);
		if(i)
			cout<<"Ԫ��"<<e<<"�ĺ��Ϊ"<<e0;
		else
			cout<<"��Ԫ��"<<e<<"�޺��"<<endl;
	}
	k=L.ListLength();
	for(j=k+1; j>=k; j--)
	{
		i=L.ListDelete(j, e);
		if(i)
			cout<<"ɾ����"<<j<<"��Ԫ�سɹ�����ֵΪ"<<e;
		else
			cout<<"ɾ����"<<j<<"��Ԫ��ʧ�ܡ�";
	}
	L.ClearList();
	cout<<endl<<"���L��L�Ƿ�գ�"<<boolalpha<<L.ListEmpty();
	cout<<"����="<<L.ListLength()<<endl;
}

