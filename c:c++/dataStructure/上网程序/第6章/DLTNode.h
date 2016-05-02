//DLTNode.h ˫���������Ĵ洢�ṹ
#include "Key.h"
#ifndef _DLTNODE_H_
#define _DLTNODE_H_
enum NodeKind {LEAF, BRANCH};
template<typename D>struct DLTNode
{
	char symbol;
	NodeKind kind;
	union
	{
		Record<D> *rcptr;
		DLTNode<D> *first;
	};
	DLTNode<D> *next;
};
#endif

