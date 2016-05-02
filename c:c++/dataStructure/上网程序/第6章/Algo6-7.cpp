//Algo6-7.cpp ��֤TrieTree��ĳ�Ա����
const int MAX_KEY_LEN=16;
#include "C.h"
const int N=18;
const char Nil='$';
#include "TrieTree.h"
#include "Func6-5.cpp"
const int h=8;
void main()
{
	int i, n;
	bool f;
	K key;
	TrieTree<Ot> t;
	Record<Ot> r, *p;
	ifstream fin("F6-6.txt");
	fin>>n;
	for(i=0; i<n; i++)
	{
		InputFromFile(fin, r);
		f=t.InsertTrie(r);
		if(!f)
			cout<<"record[]�����йؼ���Ϊ"<<r.key.ch
			<<"�����ݣ���record[]��û�п�λ���޷����롣"<<endl;
	}
	t.TraverseTrie(t.Root(), Out);
	t.Print(Out);
	cout<<"����������ҵĹؼ��ַ�����";
	InputKey(key);
	p=t.SearchTrie(key);
	if(p!=NULL)
		Out(*p);
	else
		cout<<"�����ڹؼ���Ϊ"<<key.ch<<"������";
	for(i=0; i<3; i++)
	{
		cout<<endl<<"�������ɾ���Ĺؼ��ַ�����";
		InputKey(key);
		if(t.DeleteTrie(key, r))
		{
			cout<<"ɾ���ɹ�����ֵΪ";
			Out(r);
		}
		else
			cout<<"ɾ��ʧ�ܣ�";
	}
	cout<<endl<<"���ؼ��ַ�����˳�����ɾ�������t��"<<endl;
	j=0;
	t.TraverseTrie(t.Root(), Out);
	cout<<endl;
	t.Print(Out);
	cout<<endl;
}

