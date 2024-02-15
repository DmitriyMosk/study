#include "rb_core.h"

/**
*   Выделяем память для наших структур
*/
rbtree_t* rbtree_alloc()
{
    return new rbtree_t;
}
rbnode_t* rbnode_alloc()
{
    return new rbnode_t;
}

/**
*   Создаёт элемент дерева
*/
rbnode_t* rbnode_create(int key, char *value)
{
    rbnode_t* node = rbnode_alloc(); 

    node->key = key; 
    node->value = value; 

    return node; 
}

/**
*   Добавляем элемент в дерево
*   
*   @return rbnode_t *root;
*/
rbnode_t *rbtree_insert(rbnode_t **root, int key, char *value)
{
    rbnode_t* node = rbnode_create(key, value); 
    rbnode_t* leaf = *root; 

    do {
        if (leaf == nullptr)
        {
            *root = node;
            break; 
        }
        
        if (leaf->key == key)
        {
            delete(node); 
            break; 
        }

        if (key > (*root)->key && leaf->right == nullptr)
            leaf->right = node;
        else if (key > (*root)->key)
            leaf = (*root)->right;

        if (key < (*root)->key && leaf->left == nullptr)
            leaf->left = node;
        else if (key < (*root)->key)
            leaf = (*root)->left;
    } while (leaf != nullptr);

    return (*root);
}

/**
*   Находит элемент по ключу
*   int key; - ключ элемента
* 
*   @return *rbnode_t
*/
rbnode_t** rbtree_search(rbnode_t** root, int key)
{
    if (*root == nullptr)
        return nullptr; 

    rbnode_t** node = root; 

    do
    {
        if ((*node)->key == key)
            break;
      
        if ((*node)->left != nullptr && key < (*root)->key)
            *node = (*node)->left;
    
        if ((*node)->right != nullptr && key > (*root)->key)
            *node = (*node)->right;
        
        if ((*node)->left == nullptr && (*node)->right == nullptr)
            break;
 
    } while (node != nullptr); 

    if ((*node)->key == (*root)->key && key != (*root)->key)
        (*node) = nullptr;

    return node; 
}

/**
*   Удаляет элемент по ключу
*   int key; - ключ элемента
*
*   @return bool
*/
bool rbtree_delete(rbnode_t** root, int key)
{
    rbnode_t** node = rbtree_search(root, key);

    if (node == nullptr)
        return false;

    delete node;

    node = nullptr; 

    std::cout << node << std::endl;

    return true;
}
