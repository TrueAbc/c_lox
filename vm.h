//
// Created by Bochao An on 2022/12/20.
//

#ifndef C_LOX_VM_H
#define C_LOX_VM_H

#include "chunk.h"
#include "value.h"
#define STACK_MAX 256

typedef struct {
   Chunk* chunk;
   uint8_t* ip; // instruction pointer

   Value  stack[STACK_MAX];
   Value* stackTop;
}VM;

typedef enum {
    INTERPRET_Ok,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk* chunk);

void push(Value value);
Value pop();

#endif //C_LOX_VM_H
