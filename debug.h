//
// Created by Bochao An on 2022/12/20.
//

#ifndef C_LOX_DEBUG_H
#define C_LOX_DEBUG_H
#include "chunk.h"

// const 在星号前修饰指针内容, 后修饰指针本身
void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif //C_LOX_DEBUG_H
