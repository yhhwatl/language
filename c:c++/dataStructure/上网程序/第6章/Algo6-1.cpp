//Algo6-1.cpp ��֤SqTable��ĳ�Ա����
#include "C.h"
#include "C4-1.h"
typedef long KeyType;
#include "SqTable.h"
#include "Func6-1.cpp"
void main()
{
	int i, j;
	SqTable<Sc> st[2];
	Sc e;
	KeyType key;
	char s[9]="F6-1.txt";
	for(i=0; i<2; i++)
	{
		s[3]=i+'1';
		st[i].Creat_SeqFromFile(s);
		cout<<"׼��֤��  ����  ���� ���� ��ѧ ���� �ܷ�"<<endl;
		st[i].Traverse(Total);
		st[i].Traverse(Visit);
		cout<<"������������˵Ŀ��ţ�";
		InputKey(key);
		if(i==0)
			j=st[i].Search_Seq(key);
		else
			j=st[i].Search_Bin(key);
		if(j>0)
		{
			st[i].GetElem(j, e);
			Visit(&e);
		}
	}
}

