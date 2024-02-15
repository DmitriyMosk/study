#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>


using namespace std;


struct node
{
	bool mark;

	char* value;

	int key;
	int degree;

	node* parent;
	node* children;
	node* left;
	node* right;
};

struct fib_heap
{
	int n;
	int phi;
	int degree;

	node* min;
};

struct fib_heap* make_heap();
struct fib_heap* FibHeapInsert(struct fib_heap* heap, int key, char* value);
//struct fib_heap* FibHeapUnion(struct fib_heap* heap_1, struct fib_heap* heap_2);
struct node* FibHeapDeleteMin(struct fib_heap* heap);

//void FibHeapDelete(struct fib_heap* heap, struct node* x);
//void FibHeapConsolidate(struct fib_heap* heap);
//void FibHeapAddNodeToRootList(struct fib_heap* heap, struct node* node);
//void FibHeapCut(struct fib_heap* heap, struct node* x, struct node* y);
//void FibHeapCascadingCut(struct fib_heap* heap, struct node* parent_node);
//void FibHeapDecreaseKey(struct fib_heap* heap, struct node* x, int newkey);


