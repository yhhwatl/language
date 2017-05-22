#include <stdio.h>
#include <stdlib.h>
// #include "BiTree.h"
void destroy(void* data)
{
	free(data);
};
bool fun(int n)
{
	return !(n&(n-1));
}
int main(int argc, char const *argv[])
{
	bool b = fun(8);
	printf("b = %u\n",b);
	// const char* path = argv[0];
	// printf("%s\n", path);
	// Bitree*tree = (Bitree*)malloc(sizeof(Bitree));
	// bitree_init(tree,destroy);
	// bitree_ins_left(tree,NULL,(void*)1);
	return 0;
}