#include "rb_core.h"

using namespace std; 

int main()
{
    char test[] = "test";

    rbtree_t* tree = rbtree_alloc(); 
    
    tree->Insert(1, test);

    rbnode_t* node = tree->Search(1); 

    cout << node->key << endl; 
    cout << tree->root->key << endl; 
    
    cout << tree->Delete(2) << endl;

    cout << tree->root << endl; 

    cout << "rb_start!" << endl;
}
