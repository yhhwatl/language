//TrieNode.h Trie�����Ĵ洢�ṹ
#include "Key.h"
#ifndef _TrieNODE_H_
#define _TrieNODE_H_
template<typename D>struct TrieNode
{
	Record<D> *rcptr;
	TrieNode<D> *ptr[LENGTH];
	
	int pnum;
};
#endif

