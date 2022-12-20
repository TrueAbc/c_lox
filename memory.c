//
// Created by Bochao An on 2022/12/20.
//
#include <stdlib.h>
#include "memory.h"

void *reallocate(void* pointer, size_t oldSize, size_t newSize){
    if (newSize == 0) {
        free(pointer);
        return NULL;
    }
    // grow 会自动copy
    void *result = realloc(pointer, newSize);
    if (result == NULL) exit(1);
    return result;
}