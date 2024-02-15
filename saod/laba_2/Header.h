#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>

#define alph_size 26

using namespace std;

struct node_trie
{
	node_trie* children[alph_size];

	char value;

	bool leaf;
};

struct node_trie* create_node(char data);
struct node_trie* insert(struct node_trie* root, char* key);
void free_trie(struct node_trie* root);
int search(struct node_trie* root, char* key);
void print_trie(struct node_trie* root);
void print_search(struct node_trie* root, char* key);