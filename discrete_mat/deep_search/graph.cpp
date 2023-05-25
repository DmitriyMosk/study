#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> Stack;
    int mas[7][7] = 
    { 
        { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
        { 1, 0, 1, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 1, 0 } 
    };
  int nodes[7]; // вершины графа
  for (int i = 0; i < 7; i++) // помечаем вершины, как не посещённые 
    nodes[i] = 0;
  Stack.push(0); // помещаем в очередь первую вершину
  while (!Stack.empty())
  { // пока стек не пуст
    int node = Stack.top(); // извлекаем вершину
    Stack.pop();
    if (nodes[node] == 2) continue;
    nodes[node] = 2; // отмечаем ее как посещенную
    for (int j = 6; j >= 0; j--)
    { // проверяем для нее все смежные вершины
      if (mas[node][j] == 1 && nodes[j] != 2)
      { // если вершина смежная и не обнаружена
        Stack.push(j); // добавляем ее в cтек
        nodes[j] = 1; // отмечаем вершину как обнаруженную
      }
    }
    cout << node + 1 << endl; // выводим номер вершины
  }
  cin.get();
  return 0;
}
