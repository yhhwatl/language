//Algo6-6.cpp ��֤DLTree��ĳ�Ա����
const int MAX_KEY_LEN=16;
#include "C.h"
const int N=18;
const char Nil='$';
enum style{Pre, In, Post};
#include "DLTree.h"
#include "Func6-5.cpp"
const int h=9;
void print(DLTNode<Ot>* c)
{
	cout<<c->symbol<<' ';
}
void main()
{
	int i, n;
	bool f;
	K key;
	DLTree<Ot> t;
	Record<Ot> r, *p;
	ifstream fin("F6-6.txt");
	fin>>n;
	for(i=0; i<n; i++)
	{
		InputFromFile(fin, r);
		f=t.InsertDSTable(r);
		if(!f)
			cout<<"record[]�����йؼ���Ϊ"<<r.key.ch
			<<"�����ݣ���record[]��û�п�λ���޷����롣"<<endl;
	}
	t.TraverseDSTable(t.Root(), Out);
	cout<<endl;
	t.Print(Out);
	cout<<"����������ҵĹؼ��ַ�����";
	InputKey(key);
	p=t.SearchDSTable(key);
	if(p!=NULL)
		Out(*p);
	for(i=0; i<3; i++)
	{
		cout<<endl<<"�������ɾ���Ĺؼ��ַ�����";
		InputKey(key);
		if(t.DeleteDSTable(key, r))
		{
			cout<<"ɾ���ɹ�����ֵΪ";
			Out(r);
		}
		else
			cout<<"ɾ��ʧ�ܣ�";
	}
	cout<<endl;
	j=0;
	t.TraverseDSTable(t.Root(), Out);
	cout<<endl;
	t.Print(Out);
}

