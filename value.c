//
// Created by Bochao An on 2022/12/20.
//

#include <stdio.h>
#include "memory.h"
#include "value.h"

void initValueArray(ValueArray* array) {
    array->values = NULL;
    array->capacity = 0;
    array->count = 0;
}

void writeValueArray(ValueArray* array, Value value) {
    if (array->capacity < array->count + 1) {
        int old = array->capacity;
        array->capacity = GROW_CAPACITY(old);
        array->values = GROW_ARRAY(Value, array->values,
                                   old, array->capacity);
    }
    array->values[array->count++] = value;
}

void freeValueArray(ValueArray* array) {
    FREE_ARRAY(Value, array->values, array->capacity);
    initValueArray(array);
}

void printValue(Value value) {
    printf("%g", value);
}