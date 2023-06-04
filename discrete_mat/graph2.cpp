#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> Stack;

    int N, i ,j, val;
    cout<<"Enter size : ";
    cin>>N;

    int **mas = new int *[N];
    for (i = 0; i<N; i++) mas[i] = new int[N];
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
        cout << endl << "Item A[" << i << "," << j << "]=";
        while (!(cin >> val)) { 
        cin.clear();
        while (cin.get() != '\n') continue;
        cout << "Error! Please, type it again" << endl;
        }
        mas[i][j] = val; 
        }
    }

    int *nodes = new int[N]; // вершины графа
    for (int i = 0; i < N; i++) // помечаем вершины, как не посещённые 
        nodes[i] = 0;
    Stack.push(0); // помещаем в очередь первую вершину
    while (!Stack.empty())
    { // пока стек не пуст
        int node = Stack.top(); // извлекаем вершину
        Stack.pop();
        if (nodes[node] == 2) continue;
        nodes[node] = 2; // отмечаем ее как посещенную
        for (int j = N-1; j >= 0; j--)
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