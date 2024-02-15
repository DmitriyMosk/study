#include <iostream>
#include "rbtree.h"

using namespace std; 

const char* test_data = "Яблоко груша апельсин ананас гвоздь кеды барбоскины миша маша саша каша глаша кёрнер горнер ранер паркурщик\0";

typedef struct rbnode rbnode;

int main()
{
	char test[] = "test";  

	rbnode* root(nullptr); 
	rbnode* finded(nullptr);

	root = rbtree_add(root, 50, test);

	root = rbtree_add(root, 70, test);
	
	root = rbtree_add(root, 30, test);
	
	root = rbtree_add(root, 10, test);
	
	root = rbtree_add(root, 5, test);

	root = rbtree_add(root, 80, test);

	cout << (rbtree_isRoot(root) ? "isRoot(root)->yes" : "isRoot(root)->no") << endl;

	cout << "------------------" << endl; 

	rbtree_print_dfs(root, 3);

	rbtree_free(root); 

	return 0;
}

