#include "stdio.h"
#include "stdlib.h"
#include "headers/graph.h"

 
int main()
{
 
    GRAPH* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
 
    // Тестовый граф
    // имеет 4 вершин (Граф ориентированный)
    // Матрица смежностей: 
    //   a    b    c    d 
    // a 0    1    1    0
    //
    // b 0    0    1    0 
    //
    // c 0    0    0    1 
    // 
    // d 0    0    0    0  
    printGraph(graph);

    DeepSearch(graph, 2); // С какой вершины начинаем обход
 
    return 0;
}