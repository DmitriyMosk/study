#pragma once
#ifndef _UTILS_RB_TREE 
#define _UTILS_RB_TREE 

#include <iostream>

enum rb_colors { RED, BLACK };

typedef struct rbnode_t rbnode_t;

struct rbnode_t {
    int key;

    rbnode_t *parent = nullptr, *left = nullptr, *right = nullptr;
    rb_colors color;

    char* value;
};

typedef struct rbtree_t rbtree_t; 

/**
*   ��������� ������� � ������
*
*   rbnode_t *root - ��������� �� ��������� ������
*   int key - ���� ��������
*   char *value - �������� ��������
*
*   @return rbnode_t *root;
*/
rbnode_t *rbtree_insert(rbnode_t** root, int key, char* value);

/**
*   ������ ����� �������� �� �����
*
*   rbnode_t *root - ������ ������
*   int key - ���� ��������
* 
*   @return rbnode_t *node;
*/
rbnode_t** rbtree_search(rbnode_t** root, int key); 

/**
*   ������� ������� �� �����
*   int key; - ���� ��������
*
*   @return bool
*/
bool rbtree_delete(rbnode_t** root, int key);

struct rbtree_t {
    rbnode_t *root = nullptr;
    size_t count = 0;

    void Insert(int key, char *value)
    {
        root = rbtree_insert(&root, key, value); 

        if (root != nullptr)
            count++;
    }

    rbnode_t* Search(int key)
    {
        return *rbtree_search(&root, key);
    }

    bool Delete(int key)
    {
        bool result = rbtree_delete(&root, key);

        std::cout << root << std::endl;

        return result;
    }
};

// funcs tree

/**
*   ������ ������. 
* 
*   @return *rbtree_t
*/
rbtree_t *rbtree_alloc();

// funcs node  

/**
*   ������ ����
* 
*   @return *rbnode_t
*/
rbnode_t* rbnode_alloc(); 

#endif // !_UTILS_RB_TREE 

