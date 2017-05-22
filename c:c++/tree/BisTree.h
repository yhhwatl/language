#ifndef BISTREE_H_
#define BISTREE_H_ 
#include "BiTree.h"
#define AVL_LFT_HEAVY 1
#define AVL_BALANCED 0
#define AVL_RGT_HEAVY -1
typedef struct AvlNode_
{
	void *data;
	int hidden;
	int factor;
}AvlNode;

#endif