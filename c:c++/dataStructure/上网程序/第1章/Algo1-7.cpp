//Algo1-7.cpp ���Լɪ������ĳ���
#include "C.h"
#include "DLinkListNH.h"
void Joseph(int n, int m)
{
	DLinkListNH<int> L;
	int i;
	int e;
	for(i=1; i<=n; i++)
		L.ListInsert(i, i); 
	do
	{
		for(i=1; i<m; i++)
		
			L.Head=L.Head->next;
		L.ListDelete(1, e);
		cout<<setw(3)<<e;
	}while(L.ListLength());
	cout<<endl;
}
void main()
{
	int n, m;
	cout<<"������С������n ���ӱ���m��";
	cin>>n>>m;
	Joseph(n, m);
}

