//
// Created by Bochao An on 2022/12/20.
//

#ifndef C_LOX_CHUCK_H
#define C_LOX_CHUCK_H

// chuck -> sequences of bytecode
#include "common.h"
#include "value.h"

typedef enum {
    OP_RETURN,
    OP_CONSTANT,

    OP_NEGATE,

    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
} OpCode;

// 存储字节码序列
// 实现为动态数组
typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void freeChunk(Chunk* chunk);
int addConstant(Chunk* chunk, Value value);

#endif //C_LOX_CHUCK_H
