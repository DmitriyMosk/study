#include "stdio.h"

typedef struct test {
    int *data; 
    int *data2; 
} data; 


void EditData(data *d)
{
    d->data = (int*)25; 
    d->data2 = (int*)50;
}

int main() 
{ 
    data *test; 
    test->data = (int*)5; 
    test->data2 = (int*)10; 

    EditData(test); 

    printf("%i | %i", test->data, test->data2); 
    return 0;
}