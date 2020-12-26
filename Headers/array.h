#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct
{
    int *array;
    int size;
} Array;

Array array_create(int init_ize);
void array_free(Array *a);
int array_size(const Array *a);
itn* array_at(Array *a, int index);
void array_inflate(Array *a,int more_size);

#end