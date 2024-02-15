#include "Header.h"

struct node_trie* create_node(char data)
{
	struct node_trie* node = (node_trie*)calloc(1, sizeof(node_trie));

	for (int i = 0; i < alph_size; i++)
	{
		node->children[i] = NULL;
	}
	node->value = data;
	node->leaf = false;
	return node;
}

struct node_trie* insert(struct node_trie* root, char* key)
{
	struct node_trie* _root = root;

	for (int i = 0; key[i] != '\0'; i++)
	{
		int index = (int)key[i] - 'a';
		if (_root->children[index] == NULL)
		{
			_root->children[index] = create_node(key[i]);
		}
		else
		{
		}
		_root = _root->children[index];
	}
	_root->leaf = true;

	return root;
}

void free_trie(struct node_trie* root)
{
	for (int i = 0; i < alph_size; i++)
	{
		if (root->children[i] != NULL)
		{
			free_trie(root->children[i]);
		}
		else
		{
			continue;
		}
	}
	free(root);
}

int search(struct node_trie* root, char* key)
{
	struct node_trie* _root = root;

	for (int i = 0; key[i] != '\0'; i++)
	{
		int pos = key[i] - 'a';
		if (_root->children[pos] == NULL)
		{
			return 0;
		}
		_root = _root->children[pos];
	}
	if (_root != NULL && _root->leaf == 1)
	{
		return 1;
	}
	return 0;
}

void print_trie(struct node_trie* root)
{
	if (!root)
	{
		return;
	}
	struct node_trie* _root = root;
	printf("%c -> ", _root->value);
	for (int i = 0; i < alph_size; i++)
	{
		print_trie(_root->children[i]);
	}
}

void print_search(struct node_trie* root, char* key)
{
	cout << "Searching : " << key;
	if (search(root, key) == false)
	{
		cout << " Not found " << endl;
	}
	else
	{
		cout << " Found " << endl;
	}
}
