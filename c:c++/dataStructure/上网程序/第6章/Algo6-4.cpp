//Algo6-4.cpp ��֤HashTable��ĳ�Ա����
#include "C.h"
#include "C4-1.h"
const int EMPTY=0;
const int TOMB=-1;
typedef int KeyType;
#include "HashTable.h"
#include "Func6-3.cpp"
void main()
{
	HashTable<HD> h;
	int i, j, n, p=0;
	bool m;
	HD e;
	KeyType k;
	ifstream fin("F6-4.txt");
	fin>>n;
	for(i=0; i<n; i++)
	{
		InputFromFile(fin, e);
		j=h.InsertHash(e);
		if(j==DUPLICATE)
		{
			cout<<"��ϣ�������йؼ���Ϊ"<<e.key<<"�����ݣ��޷��ٲ�������";
			Visit(e);
			cout<<endl;
		}
		if(j==UNSUCCESS)
			j=h.InsertHash(e);
	}
	fin.close();
	cout<<"����ϣ��ַ��˳�������ϣ��"<<endl;
	h.TraverseHash(Visit);
	if(h.type==1)
	{
		cout<<"�������ɾ�����ݵĹؼ��֣�";
		InputKey(k);
		m=h.DeleteHash(k, e);
		if(m)
		{
			cout<<"�ɹ�ɾ������";
			Visit(e);
			cout<<endl;
		}
	}
	cout<<"��������������ݵĹؼ��֣�";
	InputKey(k);
	n=0;
	j=h.SearchHash(k, p, n);
	if(j==SUCCESS)
	{
		Visit(h.GetElem(p));
		cout<<endl;
	}
	else
		cout<<"δ�ҵ�"<<endl;
	if(h.type==1)
	{
		cout<<"�������ݣ���������������ݵĹؼ��֣�";
		InputKey(e.key);
		cout<<"��������������ݵ�order��";
		cin>>e.order;
		j=h.InsertHash(e);
		cout<<"����ϣ��ַ��˳�������ϣ��"<<endl;
		h.TraverseHash(Visit);
	}
}

