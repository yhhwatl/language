//Algo6-5.cpp ��֤BTree��ĳ�Ա����
#include "C.h"
#include "C4-1.h"
const int EMPTY=0;
const int m=3;
const int N=12;
typedef int KeyType;
#include "BTree.h"
#include "Func6-4.cpp"
void main()
{
	Record<Ot> r;
	BTree<Ot> t;
	Result<Ot> u[4];
	int n, i;
	KeyType k;
	bool f;
	ifstream fin("F6-5.txt");
	fin>>n;
	for(i=0; i<n; i++)
	{
		InputFromFile(fin, r);
		f=t.InsertRecord(r);
		if(!f)
			cout<<"record[]�����йؼ���Ϊ"<<r.key
			<<"�����ݣ���record[]��û�п�λ���޷����롣"<<endl;
	}
	fin.close();
	t.Print();
	cout<<endl<<"���ؼ��ֵ�˳�����B��t��"<<endl;
	t.TraverseBTree(t.Root(), Visit);
	for(i=0; i<4; i++)
	{
		cout<<endl<<"��������������ݵĹؼ��֣�";
		InputKey(k);
		u[i]=t.SearchBTree(k);
		cout<<"u["<<i<<"].i="<<u[i].i<<" u["<<i<<"].tag="<<u[i].tag<<' ';
		if(u[i].tag)
			Visit(*(u[i].pt->recptr[u[i].i]));
		else
			cout<<"δ�ҵ��ؼ���Ϊ"<<k<<"�����ݡ�";
	}
	cout<<endl<<"�������ɾ�����ݵĹؼ��֣�";
	InputKey(k);
	f=t.DeleteBTree(r, k);
	if(f)
		Visit(r);
	cout<<endl<<"���ؼ��ֵ�˳�����ɾ�����B��t��"<<endl;
	t.TraverseBTree(t.Root(), Visit);
	cout<<endl;
	t.Print();
	cout<<endl;
}

