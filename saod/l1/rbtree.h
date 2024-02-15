#ifndef _UTILS_RBTREE
#define _UTILS_RBTREE 

enum node_color { RED, BLACK };

typedef struct rbnode rbnode_t; 

struct rbnode {
	rbnode_t *parent = nullptr, *right = nullptr, *left = nullptr;

	node_color color = RED;
	int key;
	char* value;
};

struct rbtree {
	rbnode_t* root = nullptr;
};

struct rbnode* rbtree_add(struct rbnode* root, int key, char* value, struct rbnode* current = nullptr);
struct rbnode* rbtree_lookup(struct rbnode *root, int key);
struct rbnode* rbtree_delete(struct rbnode *root, int key);
struct rbnode* rbtree_min(struct rbnode *root);
struct rbnode* rbtree_max(struct rbnode *root);
void rbtree_free(struct rbnode *root);
void rbtree_print_dfs(struct rbnode* root, int level, int pos = -1); 


// my

bool rbtree_isRoot(struct rbnode* node);

#endif 
#pragma once
