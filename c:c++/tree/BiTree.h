#ifndef BITREE_H_ 
#define BITREE_H_ 
#include <stdlib.h>
typedef struct BiTreeNode_
{
	void* data;
	struct BiTreeNode_* left;
	struct BiTreeNode_* right;
}BiTreeNode;
typedef struct Bitree_
{
	int size;
	int (*compare)(const void*key1, const void*key2);
	void (*destroy)(void *data);
	BiTreeNode* root;
}Bitree;

#define bitree_size(tree) ((tree)->size)
#define bitree_root(tree) ((tree)->root)
#define bitree_is_nob(node) ((node)==NULL)
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)
#define bitree_data(node) ((node)->data)
#define bitree_left(node) ((node)->left)
#define bitree_right(node) ((node)->right)

void bitree_init(Bitree* tree, void (*destroy)(void*data));
void destroy(Bitree* tree);
int bitree_ins_left(Bitree* tree, BiTreeNode* node, const void* data);
int bitree_ins_right(Bitree* tree, BiTreeNode* node, const void* data);
void bitree_rem_left(Bitree*tree, BiTreeNode* node);
void bitree_rem_right(Bitree*tree, BiTreeNode* node);
int bitree_merge(Bitree* merge, const Bitree* left,
	const Bitree* right, const void* data);

//------------------------------------------
void bitree_init(Bitree* tree, void (*destroy)(void*data))
{
	tree->size = 0;
	tree->destroy = destroy;
	tree->root = NULL;
};
void bitree_destroy(Bitree* tree)
{	
	bitree_rem_left(tree,NULL);
	bitree_rem_right(tree,NULL);
	// memset(tree,0,sizeof(Bitree));
};
int bitree_ins_left(Bitree* tree, BiTreeNode* node, const void* data)
{
	BiTreeNode *newNode,**position;
	if (node == NULL)
	{
		if (bitree_size(tree) > 0)
		{
			return -1;// 树不空 节点空
		}
		position = &(tree->root);
	}
	else
	{
		if (bitree_left(node)!=NULL)
		{
			return -1;// 已经有左节点了
		}
		position = &(node->left);
	}
	if ((newNode = (BiTreeNode*)malloc(sizeof(node))) == NULL)
	{
		return -1;
	}
	newNode->data = (void*)data;
	newNode->left = NULL;
	newNode->right = NULL;
	*position = newNode;// 等价于 node->left = newNode
	tree->size++; 
	return 0;
};
int bitree_ins_right(Bitree* tree, BiTreeNode* node, const void* data)
{
	BiTreeNode* newNode,**position;
	if (node == NULL)
	{
		if (bitree_size(tree) > 0)
		{
			return -1;
		}
		position = &(tree->root);
	}
	else
	{
		if (bitree_left(node)!=NULL)
		{
			return -1;
		}
		position = &(node->right);
	}
	newNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	newNode->data = (void*) data;
	newNode->left = NULL;
	newNode->right = NULL;
	*position = newNode;
	tree->size++;
	return 0;
};
void bitree_rem_left(Bitree*tree, BiTreeNode* node)
{
	if (bitree_size(tree) <= 0)
	 {
		return;
	 }
	BiTreeNode**position;
	if (node == NULL)
	 {
	 	position = &(tree->size);
	 }
	 else
	 {
	 	position = &(node->left);
	 }
	 if (*position != NULL)
	  {
	  	bitree_rem_left(tree,*position);
	  	bitree_rem_right(tree,*position);
	  	if (tree->destroy)
	  	{
	  		tree->destroy((*position)->data);
	  	}
	  	free(*position);
	  	*position = NULL;
	  	tree->size--;
	  } 
	
};
void bitree_rem_right(Bitree*tree, BiTreeNode* node)
{
	if (bitree_size(tree) == 0)
	{
		return;
	}
	BiTreeNode**position;
	if (node == NULL)
	{
		*position = &(tree->root);
	}
	else
	{
		*position = &(node->right);
	}
	if (*position != NULL)
	{
		bitree_rem_left(tree,*position);
		bitree_rem_right(tree,*position);
		if (tree->destroy)
		{
			tree->destroy((*position)->data);
		}
		free(*position);
		*position = NULL;
		tree->size--;
	}
};
int bitree_merge(Bitree* merge, Bitree* left,
	 Bitree* right, const void* data)
{
	bitree_init(merge,left->destroy);
	if (bitree_ins_left(merge,NULL,data) != 0)
	{
		bitree_destroy(merge);
		return -1;
	}
	bitree_root(merge)->left = left->root;
	bitree_root(merge)->right = right->root;
	merge->size = merge->size + left->size + right->size;
	left->root = NULL;
	left->size = 0;
	right->root = NULL;
	right->size = 0;
	return 0;
};

#endif