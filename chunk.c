//
// Created by Bochao An on 2022/12/20.
//

#include <stdlib.h>
#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk){
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk* chunk, uint8_t byte, int line){
    if (chunk->capacity < chunk->count+1) {
        int oldCap = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCap);
        chunk->lines = GROW_ARRAY(int, chunk->lines,
                                  oldCap, chunk->capacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,
                                 oldCap, chunk->capacity);
    }

    chunk->lines[chunk->count] = line;
    chunk->code[chunk->count] = byte;
    chunk->count++;
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    initChunk(chunk);
    freeValueArray(&chunk->constants);
}

int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}