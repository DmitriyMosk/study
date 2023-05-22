#include "graph.h"
#include "stdio.h"
#include "stdlib.h"

void DeepSearch(GRAPH* graph, int vertex) {
    NODE* adjList = graph->adjLists[vertex];
    NODE* temp = adjList;
 
    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);
 
    while(temp!=NULL) {
        int connectedVertex = temp->vertex;
 
        if(graph->visited[connectedVertex] == 0) {
            DeepSearch(graph, connectedVertex);
        }
        temp = temp->next;
    }       
}
 
NODE* createNode(int v)
{
    NODE* newNode = malloc(sizeof(NODE));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
 
GRAPH* createGraph(int vertices)
{
    GRAPH* graph = malloc(sizeof(GRAPH));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(NODE*));
 
    graph->visited = malloc(vertices * sizeof(int));
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(GRAPH* graph, int src, int dest)
{
    NODE* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
 
void printGraph(GRAPH* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        NODE* temp = graph->adjLists[v];
        printf("\n Adjacency array of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}