//Algo5-1.cpp MatrixGraph��������������Ⱥ͹���������������ĳ���
const int MAX_VERTEX_NUM=8;
#include "C5-1.h"
#include "MatrixGraph.h"
#include "Func5-1.cpp"
#include "Func5-2.cpp"
void main()
{
	MatrixGraph<V, A> g;
	char s[9]="F5-5.txt";
	for(int i=5; i<=6; i++)
	{
		s[3]=i+'0';
		g.CreateFromFile(s);
		cout<<"MatrixGraph�����������������ͼg�Ľ����";
		g.DFSTraverse(Visit);
		cout<<"MatrixGraph����������������ͼg�Ľ����";
		g.BFSTraverse(Visit);
	}
}

