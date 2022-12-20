//
// Created by Bochao An on 2022/12/20.
//

#ifndef C_LOX_VALUE_H
#define C_LOX_VALUE_H

// 存储字面量 literal
#include "common.h"

// 一般大
typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif //C_LOX_VALUE_H
