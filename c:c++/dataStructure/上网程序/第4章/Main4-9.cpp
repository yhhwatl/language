//Main4-9.cpp ��CSTree<T>�๹��ɭ��
#include "C.h"
#include "CSTree.h"
#define BiTNode CSNode
typedef char T;
#include "Func4-1.cpp"
void main()
{
	CSTree<T>t;
	t.CreateTreeFromFile("F4-9.txt");
	cout<<"���ļ�F4-9.txt����ɭ��t��ɭ�ֵ���ȣ����������������������ȣ�Ϊ";
	cout<<t.TreeDepth()<<endl<<"�������ɭ��t��";
	t.LevelOrderTraverse(Visit);
	cout<<endl<<"�ȸ�����ɭ��t��";
	t.PreOrderTraverse(Visit);
	cout<<endl<<"�������ɭ��t��";
	t.PostOrderTraverse(Visit);
	cout<<endl;
}

