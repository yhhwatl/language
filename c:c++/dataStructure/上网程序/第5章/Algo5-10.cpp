//Algo5-10.cpp ���ø�����������������֮����̾���ĳ���
const int MAX_VERTEX_NUM=26;
#include "C5-1.h"
#include "Floyd.h"
#include "Func5-1.cpp"
#include "Func5-2.cpp"
void main()
{
	int i, j, q=1;
	MatrixGraph<V, A> g;
	g.CreateFromFile("Map.txt");
	Floyd<V, A> m(g);
	cout<<"���д��룺"<<endl;
	for(i=0; i<g.GetVexNumOrArcNum(0); i++)
	{
		cout<<setw(4)<<i<<g.GetVex(i).name<<' ';
		if(i%7==6)
			cout<<endl;
	}
	cout<<endl;
	while(q)
	{
		cout<<"��ѡ��1 ��ѯ�����м����̾���  0 ����"<<endl;
		cin>>q;
		if(q)
		{
			cout<<"������Ҫ��ѯ�������д��� �յ���д��룺";
			cin>>i>>j;
			m.Path(i, j);
		}
	}
}

