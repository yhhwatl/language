//BiThrNode.h �����������������ͽṹ��
#ifndef _BITHRNODE_H_
#define _BITHRNODE_H_
enum PointerTag	{Link, Thread};
template<typename T>struct BiThrNode
{ 
	T data;
	BiThrNode<T> *lchild, *rchild;
	PointerTag LTag:2, RTag:2;
};
#endif

