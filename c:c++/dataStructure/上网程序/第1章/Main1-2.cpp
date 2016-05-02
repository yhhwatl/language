//Main1-2.cpp TΪ�û��Զ�������
#include "C.h"
#include "SqList.h"
struct Student
{
	string name;
	int score;
};
inline void printSt(Student* c)
{
	cout<<endl<<setw(6)<<c->name<<"��"<<c->score;
}
inline void printName(Student* c)
{
	cout<<c->name;
}
bool equal(Student c1, Student c2)
{
	return c1.name==c2.name;
}
void main()
{
	bool i;
	int j=1;
	SqList<Student>L(5);
	ifstream fin("F1-1.txt");
	Student e, e0;
	while(!fin.eof())
	{
		fin>>e.name>>e.score;
		L.ListInsert(j++, e);
	}
	fin.close();
	cout<<"��L�ı�β���β����ļ�F1-1.txt�е����ݺ󣬱�L=";
	L.ListTraverse(printSt);
	cout<<"L�Ƿ�գ�"<<boolalpha<<L.ListEmpty()<<"����=";
	cout<<L.ListLength()<<endl;
	L.GetElem(4, e);
	cout<<"��4��Ԫ�ص�ֵΪ";
	printSt(&e);
	cout<<endl;
	L.GetElem(j, e);
	i=L.PriorElem(e, equal, e0);
	if(i)
	{
		printName(&e);
		cout<<"��ǰ��Ϊ";
		printName(&e0);
		cout<<endl;
	}
	i=L.NextElem(e, equal, e0);
	if(i)
	{
		printName(&e);
		cout<<"�ĺ��Ϊ";
		printName(&e0);
		cout<<endl;
	}
	i=L.ListDelete(3, e);
	if(i)
	{
		cout<<"ɾ����3��Ԫ�سɹ�����ֵΪ";
		printSt(&e);
	}
	cout<<"\nĿǰ����L=";
	L.ListTraverse(printSt);
	L.ClearList();
	cout<<"���L��L�Ƿ�գ�"<<boolalpha<<L.ListEmpty();
	cout<<"����="	<<L.ListLength()<<endl;
}

