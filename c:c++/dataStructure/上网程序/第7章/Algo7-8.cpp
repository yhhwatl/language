//Algo7-8.cpp ��֤��̬�������������
#include "C.h"
#include "C4-1.h"
typedef int KeyType;
#include "SLinkSort.h"
#include "Func7-2.cpp"
void main()
{
	SLinkSort<SL> sls[2];
	for(int i=0; i<2; i++)
	{
		sls[i].Creat_SeqFromFile("F7-1.txt");
		if(i==0)
		{
			cout<<"����ǰ��"<<endl;
			sls[i].Traverse(Visit);
		}
		sls[i].MakeTableSorted();
		if(i==0)
		{
			cout<<endl<<"��ʽ�����"<<endl;
			sls[i].Traverse(Visitn);
		}
		if(i==0)
		{
			sls[i].Arrange();
			cout<<endl<<"Arrange�����"<<endl;
		}
		else
		{
			sls[i].Rearrange();
			cout<<endl<<"Rearrange�����"<<endl;
		}
		sls[i].Traverse(Visit);
	}
	cout<<endl;
}

