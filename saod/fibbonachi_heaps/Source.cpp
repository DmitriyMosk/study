#include "Header.h"


struct fib_heap* make_heap()
{
	struct fib_heap* h = (struct fib_heap*)malloc(sizeof(struct fib_heap));
	h->n = 0;
	h->min = NULL;
	h->phi = 0;
	h->degree;
	return h;
}

struct node* _Create_node(int key, char* value)
{
	node* _node = new node;

	_node->key = key;
	_node->value = value;

	_node->degree = 0;

	_node->mark = false;

	_node->left = _node;
	_node->right = _node;

	_node->parent = NULL;
	_node->children = NULL;

	return _node;
}


struct fib_heap* FibHeapInsert(struct fib_heap* heap, int key, char* value)
{
	struct node* node_insert = _Create_node(key, value);



	if (heap->min == NULL || (node_insert->key < heap->min->key))
	{
		heap->min = node_insert;
	}

	heap->n++;
	return heap;

}

void FibHeapAddNodeToRootList(struct fib_heap* heap, struct node* node)
{
	if (heap == NULL)
	{
		return;
	}
	if (heap->min->left == heap->min)
	{
		heap->min->left = node;
		heap->min->right = node;
		heap->min->right = heap->min;
		heap->min->left = heap->min;
	}
	else
	{
		struct node* lnode = heap->min->left;
		lnode = heap->min->left;
		heap->min->left = node;
		node->right = heap->min;
		node->left = lnode;
		lnode->right = node;
	}
}


struct fib_heap* FibHeapUnion(struct fib_heap* heap_1, struct fib_heap* heap_2)
{
	struct fib_heap* h = new fib_heap;

	h = make_heap();

	h->min = heap_1->min;

	struct node* temp1, * temp2;

	temp1 = h->min->right;
	temp2 = heap_2->min->left;

	h->min->right->left = heap_2->min->left;
	h->min->right = heap_2->min;
	heap_2->min->left = h->min;
	temp2->right = temp1;

	if ((heap_1->min == NULL) || (heap_2 != NULL && heap_2->min->key < heap_1->min->key))
	{
		h->min = heap_2->min;
	}
	h->n = heap_1->n + heap_2->n;

	return h;
}

int _cal_degree(int n)
{
	int count = 0;
	while (n > 0)
	{
		n = n / 2;
		count++;
	}
	return count;
}

void _FibHeapLink(struct fib_heap* heap, struct node* y, struct node* x)
{
	y->right->left = y->left;
	y->left->right = y->right;

	if (x->right == x)
	{
		heap->min = x;
	}
	y->left = y;
	y->right = y;
	y->parent = x;

	if (x->children == NULL)
	{
		x->children = y;
	}

	y->right = x->children;
	y->left = x->children->left;
	x->children->left->right = y;
	x->children->left = y;

	if ((y->key) < (x->children->key))
	{
		x->children = y;
	}

	x->degree++;
}

void FibHeapConsolidate(struct fib_heap* heap)
{
	struct node** _temp_array = (struct node**)calloc(heap->n, sizeof(struct node*));

	struct node* x, * y, * z;

	int degree, i, d;
	degree = _cal_degree(heap->n);

	for (int i = 0; i < degree; i++)
	{
		_temp_array[i] = NULL;
	}

	x = heap->min;

	do
	{
		d = x->degree;

		while (_temp_array[d] != NULL)
		{
			y = _temp_array[d];
			if (x->key > y->key)
			{
				struct node* temp_y = x;
				x = y;
				y = temp_y;
			}
			if (y == heap->min)
			{
				heap->min = x;
			}
			_FibHeapLink(heap, y, x);
			if (y->right == x)
			{
				heap->min = x;
			}
			_temp_array[d] = NULL;
			d++;
		}
		_temp_array[d] = x;
		x = x->right;
	} while (x != heap->min);

	heap->min = NULL;

	for (int i = 0; i < degree; i++)
	{
		if (_temp_array[i] != NULL)
		{
			_temp_array[i]->left = _temp_array[i];
			_temp_array[i]->right = _temp_array[i];
			if (heap->min == NULL)
			{
				heap->min = _temp_array[i];
			}
			else
			{
				heap->min->left->right = _temp_array[i];
				_temp_array[i]->right = heap->min;
				_temp_array[i]->left = heap->min->left;
				heap->min->left = _temp_array[i];
				if (_temp_array[i]->key < heap->min->key)
				{
					heap->min = _temp_array[i];
				}
			}
			if (heap->min == NULL)
			{
				heap->min = _temp_array[i];
			}
			else if (_temp_array[i]->key < heap->min->key)
			{
				heap->min = _temp_array[i];
			}
		}
	}
}

struct node* FibHeapDeleteMin(struct fib_heap* heap)
{
	struct node* z = heap->min;

	if (z == NULL)
	{
		return NULL;
	}
	else
	{
		struct node* temp = z;
		struct node* pntr;
		pntr = temp;
		struct node* x = NULL;
		if (temp->children != NULL)
		{
			x = temp->children;
			do
			{
				pntr = x->right;
				z->left->right = x;
				x->right = z;
				x->left = z->left;
				z->left = x;
				if (x->key < z->key)
				{
					z = x;
				}
				x->parent = NULL;
				x = pntr;
			} while (pntr != temp->children);
		}
		temp->left->right = temp->right;
		temp->right->left = temp->left;
		z = temp->right;

		if (temp == temp->right && temp->children == NULL)
		{
			z = NULL;
		}
		else
		{
			z = temp->right;
			FibHeapConsolidate(heap);
		}
		heap->n--;
		return temp;

	}
	return z;
}

void FibHeapCut(struct fib_heap* heap, struct node* x, struct node* y)
{
	struct node* temp_parent;

	if (x == x->right)
	{
		y->children = NULL;
	}

	x->left->right = x->right;
	x->right->left = x->left;

	if (x == y->children)
	{
		y->children = x->right;
	}
	y->degree--;

	x->left = x;
	x->right = x;
	heap->min->left->right = x;
	x->right = heap->min;
	x->left = heap->min->left;
	heap->min->left = x;

	x->parent = NULL;
	x->mark = false;
}

void FibHeapCascadingCut(struct fib_heap* heap, struct node* parent_node)
{
	struct node* temp_node = parent_node->parent;
	if (temp_node != NULL)
	{
		if (parent_node->mark == false)
		{
			parent_node->mark = true;
		}
		else
		{
			FibHeapCut(heap, parent_node, temp_node);
			FibHeapCascadingCut(heap, temp_node);
		}
	}
}

void FibHeapDecreaseKey(struct fib_heap* heap, struct node* x, int newkey)
{
	if (newkey > x->key)
	{
		return;
	}
	x->key = newkey;
	struct node* y = x->parent;

	if (y != NULL && x->key < y->key)
	{
		FibHeapCut(heap, x, y);
		FibHeapCascadingCut(heap, y);
	}
	if (x->key < heap->min->key)
	{
		heap->min = x;
	}

}


void FibHeapDelete(struct fib_heap* heap, struct node* x)
{
	FibHeapDecreaseKey(heap, x, -5000);
	FibHeapDeleteMin(heap);
}