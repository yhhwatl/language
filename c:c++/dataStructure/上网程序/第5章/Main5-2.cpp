//Main5-2.cpp ��һ�ֶ���ͻ��ṹ������ڽӾ�����ĳ�Ա����
const int MAX_VERTEX_NUM=3;
#include "C5-1.h"
#include "MatrixGraph.h"
#include "Func5-3.cpp"
#include "Func5-4.cpp"
void main()
{
	int i, j, k, n;
	char s[9]="F5-3.txt";
	MatrixGraph<V, A> g;
	V v1, v2;
	for(i=3; i<=4; i++)
	{
		s[3]=i+'0';
		g.CreateFromFile(s);
		g.Display();
		cout<<"�����¶��㣬�������¶����ֵ��";
		InputVertex(v1);
		g.InsertVex(v1);
		cout<<"�������¶����йصĻ��������뻡����";
		cin>>n;
		for(k=0; k<n; k++)
		{
			cout<<"�������"<<k+1<<"������һ��������ƣ�";
			cin>>v2.name;
			if(g.GetDirectedOrWeight(0))
			{
				cout<<"�������"<<k+1<<"������һ����ķ���0����ͷ 1����β����";
				cin>>j;
				if(j)
					g.InsertArc(v2, v1);
				else
					g.InsertArc(v1, v2);
			}
			else
				g.InsertArc(v1, v2);
		}
		g.Display();
		cout<<"ɾ�����㼰��صĻ����������ɾ����������ƣ�";
		cin>>v1.name;
		g.DeleteVex(v1);
		g.Display();
		if(i==4)
		{
			cout<<"�޸Ķ����ֵ����������޸Ķ������ƣ�";
			cin>>v1.name;
			cout<<"��������ֵ��";
			InputVertex(v2);
			g.PutVex(v1, v2);
			cout<<"ɾ��һ�������������ɾ�����Ļ�β ��ͷ��";
			cin>>v1.name>>v2.name;
			g.DeleteArc(v1, v2);
			g.Display();
		}
	}
}

