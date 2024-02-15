#include <stdio.h>
#include <stdlib.h>

typedef struct test { 
    int key; 
    int *value; 
} test; 

test *create(int key) 
{ 
    test *create = (test*)malloc(sizeof(test)); 

    return create; 
}

void edit(test *object, int *newvalue)
{ 
    test *object_copy = object; 

    object_copy->value = newvalue; 
}


int main() 
{ 

    test *object1 = create(1); 

    object1->value = (int*)5; 
    printf("%i\n", object1->value); 

    edit(object1, (int*)10); 

    printf("%i", object1->value); 

    return 0; 
}