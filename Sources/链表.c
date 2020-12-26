#include <array.h>

// typedef struct
// {
//     int *array;
//     int size;
// } Array;

Array array_create(int init_size){
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size )

    return 0;
}
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a,int more_size);