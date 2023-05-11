#include <iostream>
#include "array_lib.h"

void array_print(int *arr, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int *array_create(size_t len)
{
    int *arr = new int[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % (100 - 10 + 1) + 10;
    }
    return arr;
}

int array_max_number(int *arr, size_t len)
{
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        max = (arr[i] > max) ? arr[i] : max;
    }

    return max;
}

void array_rebuild(int *arr, size_t len, int max_number)
{
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if ( arr[i] % 2 == 0)
        {
            count++;
        }
    }

    int len_z = len + count;

    int index_z = 0;

    int *arr_z = new int[len_z];

    for(int i = 0; i < len; i++)
    {
       arr_z[index_z] = arr[i];

       if ( arr[i] % 2 == 0 )
       {
          index_z++;
          arr_z[index_z] = max_number;
       }

       index_z++;
    }

    array_print(arr_z, len_z);
    delete [] arr_z;
}
