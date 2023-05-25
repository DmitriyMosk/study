#ifndef LIB_GRAPH 
#define LIB_GRAPH 

typedef struct node
{
    int vertex;
    struct node* next;
} NODE;
 
NODE* createNode(int v);
 
typedef struct Graph // Структура самого графа
{
    int numVertices;
    int* visited;
    NODE** adjLists; 
} GRAPH;
 
GRAPH* createGraph(int);
void addEdge(GRAPH*, int, int);
void printGraph(GRAPH*);
void DeepSearch(GRAPH*, int);
 
#endif 