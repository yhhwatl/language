//Main4-4.cpp ��֤��������ṹ�Ķ���������BSTree<T>��ĳ�Ա����
#include "C.h"
#include "BiTNode.h"
#include "Func4-2.cpp"
#include "C4-1.h"
#include "BSTree.h"
void main()
{
	BSTree<T> t;
	BiTNode<T> *p;
	KeyType j;
	T r;
	bool k;
	int n;
	ifstream fin("F4-5.txt");
	fin>>n;
	for(int i=0; i<n; i++)
	{
		InputFromFile(fin, r);
		k=t.Insert(r);
		if(!k)
		{
			cout<<"����������t���Ѵ��ڹؼ���Ϊ"<<r.key<<"�����ݣ���("<<r.key;
			cout<<", "<<r.others<<")�޷����뵽t�С�"<<endl;
		}
	}
	fin.close();
	cout<<"�����������������t��"<<endl;
	t.OrderTraverse(t.Root(), In, Visit);
	cout<<endl<<"�����������������t��"<<endl;
	t.OrderTraverse(t.Root(), Pre, Visit);
	cout<<endl<<"�������ɾ�����Ĺؼ��ֵ�ֵ��";
	InputKey(j);
	p=t.SearchBST(t.Root(), j);
	if(p)
	{
		cout<<"t�д��ڹؼ���Ϊ"<<j<<"�Ľ�㡣";
		t.BSDTree<T>::Delete(j);
		cout<<"ɾ���˽��������������������t��"<<endl;
		t.OrderTraverse(t.Root(), In, Visit);
		cout<<endl<<"�����������������t��"<<endl;
		t.OrderTraverse(t.Root(), Pre, Visit);
		cout<<endl;
	}
	else
		cout<<"t�в����ڹؼ���Ϊ"<<j<<"�Ľ�㡣"<<endl;
}

