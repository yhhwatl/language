//Main4-3.cpp ��֤������������ṹ�Ķ�����BiThrTree<T>��ĳ�Ա����
#include "C.h"
#include "BiThrTree.h"
#define BiTNode BiThrNode
typedef char T;
T Nil='#';
#include "Func4-1.cpp"
void main()
{
	BiThrTree<T> t;
	t.CreateBiThrTreeFromFile("F4-1.txt");
	t.PreOrderThreading();
	cout<<"�����������������t��";
	t.PreOrderTraverse(Visit);
	t.InOrderThreading();
	cout<<endl<<"�����������������t��";
	t.InOrderTraverse(Visit);
	t.PostOrderThreading();
	cout<<endl;
}

