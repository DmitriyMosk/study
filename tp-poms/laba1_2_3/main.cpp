#include <iostream>
#include <time.h>
#include "array_lib.h"

using namespace std;

int main()
{
    srand(time(0));

    size_t N;

    cout << "Input size array: " << endl;
    cin >> N;

    int *array = array_create(N);

    array_print(array, N);

    int max_number = array_max_number(array, N);

    cout << "Max value: " << max_number << endl;

    array_rebuild(array, N, max_number);

    delete [] array;

    return 0;
}
