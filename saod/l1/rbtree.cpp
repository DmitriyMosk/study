#include "rbtree.h"
#include <iostream>

/*
	c "__" помечаются internal функции, которые не описываются в .h
*/

/* 
	---------------CASES---------------

	c[1] : Корень дерева всегда чёрный. check @__node_fix_case_1(struct rbnode *node)


*/

void __rbtree_rotate_right(struct rbnode* n)
{
	struct rbnode* pivot = n->left;

	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
	if (n->parent != nullptr) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->left = pivot->right;
	if (pivot->right != nullptr)
		pivot->right->parent = n;

	n->parent = pivot;
	pivot->right = n;
}
void __rbtree_rotate_left(struct rbnode* n)
{
	struct rbnode* pivot = n->right;

	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
	if (n->parent != NULL) {
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}

	n->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = n;

	n->parent = pivot;
	pivot->left = n;
}
void __rbtree_debug_node(struct rbnode* node, int pos)
{
	if (node == nullptr)
	{
		std::cout 
			<< "null node" 
			<< std::endl;
		return; 
	}
	else
	{
		std::cout
			<< "key: " << node->key
			<< "\t"
			<< "color: " << ((node->color == RED) ? "RED" : "BLACK")
			<< "\t"
			<< ((node->parent != nullptr) ? "parent: " : "") << ((node->parent != nullptr) ? node->parent->key : 0)
			<< "\t"
			<< "pos: " << ((pos == 0) ? "left" : (pos == -1) ? "root" : "right")
			<< std::endl;
	}
}
struct rbnode* __rbtree_create(int key, char* value)
{
	struct rbnode* obj = new struct rbnode;

	obj->key = key;
	obj->value = value;

	return obj;
}
struct rbnode* __node_grandparent(struct rbnode* node)
{
	if (!rbtree_isRoot(node) && node->parent->parent != nullptr)
		return node->parent->parent;
	else
		return nullptr;
}
struct rbnode* __node_uncle(struct rbnode* node) 
{
	struct rbnode* grandparent = __node_grandparent(node); 

	if (grandparent == nullptr) return nullptr; 
	
	if (node->parent == grandparent->left && grandparent->right != nullptr)
	{
		return grandparent->right; 
	}
	if (node->parent == grandparent->right && grandparent->left != nullptr)
	{
		return grandparent->left; 
	}

	return nullptr; 
}

bool rbtree_isRoot(struct rbnode* node)
{
	std::cout << ( node == nullptr ) << std::endl;
	if (node == nullptr)
		return false; 
	else if (node->parent == nullptr)
		return (node->parent == nullptr);
}

/*
* bnode - узел, который нужно балансировать
*/
struct rbnode* __rbtree_fix(struct rbnode* bnode)
{
	if (rbtree_isRoot(bnode)) // c[1]
	{
		bnode->color = BLACK; 

		return bnode; 
	}

	struct rbnode* uncle = __node_uncle(bnode);
	struct rbnode* grandparent = __node_grandparent(bnode);

	if (uncle != nullptr && uncle->color == RED) //c[2]
	{
		uncle->color = BLACK;
		bnode->parent->color = BLACK;
	}
	else // c[3]
	{
		if (grandparent != nullptr)
		{
			if
			(
				bnode->parent->right == bnode &&
				bnode->parent == grandparent->left
			)
			{
				__rbtree_rotate_left(bnode->parent); 
				__rbtree_fix(bnode->left); 
			}
			else if
			(
				bnode == bnode->parent->left && 
				bnode->parent == grandparent->right 
			)
			{
				__rbtree_rotate_left(bnode->parent);
				__rbtree_fix(bnode->left);
			}
		}
	}

	if (grandparent != nullptr)
	{
		bnode->parent->color = BLACK;
		grandparent->color = RED; 

		if (bnode == bnode->parent->left && bnode->parent == grandparent->left)
		{
			__rbtree_rotate_right(grandparent); 
		}
		else
		{
			__rbtree_rotate_left(grandparent);
		}
	}

	__rbtree_fix(bnode->parent);
}

// @return struct rbnode *root - возвращает корень узла
struct rbnode *rbtree_add(struct rbnode* root, int key, char* value, struct rbnode* current) //
{
	if (current == nullptr)
		current = root;

	if ( (root != nullptr && root->key == key) || (current != nullptr && current->key == key)) // попытка добавить уже существующий узел
		return root;

	if (root == nullptr || current->left == nullptr || current->right == nullptr)
	{
		struct rbnode* newnode = __rbtree_create(key, value); // создаём узел

		if (root == nullptr)
			root = newnode;

		if (current != nullptr)
		{
			newnode->parent = current;

			if (key > current->key)
				current->right = newnode;

			if (key < current->key)
				current->left = newnode;
		}

		return __rbtree_fix(newnode);;
	}

	if (key > current->key)
		rbtree_add(root, key, value, current->right);

	if (key < current->key)
		rbtree_add(root, key, value, current->left);
}

struct rbnode *rbtree_lookup(struct rbnode* root, int key)
{
	if (root != nullptr)
	{
		if (root->key == key)
			return root; 

		if (root->left != nullptr && root->key > key)
			rbtree_lookup(root->left, key);

		if (root->right != nullptr && root->key < key)
			rbtree_lookup(root->right, key);
	}
	else
		return nullptr; 
}

struct rbnode* rbtree_delete(struct rbnode* root, int key)
{
	return nullptr; 
}

struct rbnode* rbtree_min(struct rbnode* root)
{
	if (root->left != nullptr)
		rbtree_min(root->left);
	else
		return root; 
}

struct rbnode* rbtree_max(struct rbnode* root)
{
	if (root->right != nullptr)
		rbtree_max(root->right);
	else
		return root; 
}

void rbtree_free(struct rbnode* root)
{
	if (root != nullptr)
	{
		if (root->left != nullptr)
			rbtree_free(root->left);

		if (root->right != nullptr)
			rbtree_free(root->right);

		delete(root);  
	}
	else
		return; 
}

void rbtree_print_dfs(struct rbnode* root, int level, int pos)
{
	if(level <= 0 || root == nullptr)
		return; 

	__rbtree_debug_node(root, pos);

	if (root->left != nullptr)
		rbtree_print_dfs(root->left, level - 1, 0);

	if (root->right != nullptr)
		rbtree_print_dfs(root->right, level - 1, 1);
}