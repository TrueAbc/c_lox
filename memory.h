//
// Created by Bochao An on 2022/12/20.
//

#ifndef C_LOX_MEMORY_H
#define C_LOX_MEMORY_H
#include "common.h"

// 计算新的动态数组长度
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity)*2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

// oldSize  newSize     Operation
// 0        Non-zero    Allocate new block
// Non-zero 0           Free allocation
// Non-zero < old       Shrink existing allocation
// Non-zero > old       Grow existing allocation
void *reallocate(void* pointer, size_t oldSize, size_t neSize);

#endif //C_LOX_MEMORY_H
