//
// Created by Bochao An on 2022/12/20.
//
#include "stdio.h"
#include "common.h"
#include "vm.h"

#ifdef DEBUG_TRACE_EXECUTION
#include "debug.h"
#endif

// 如果希望嵌入到其他语言中, 一个虚拟机的假设是不够的
VM vm;

static InterpretResult run() {
#define READ_BYTE()(*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op) \
    do{               \
    /* ensure in same scope*/ \
    /* trick 保证macro在一个作用域且不担心后面加分号*/                  \
    double b = pop(); \
    double a = pop(); \
    push(a op b);\
    }while(false)


    for(;;){
#ifdef DEBUG_TRACE_EXECUTION

        disassembleInstruction(vm.chunk,
                               (int)(vm.ip - vm.chunk->code));

        printf("          ");
        for (Value* slot = vm.stack; slot < vm.stackTop; slot++) {
            printf("[ ");
            printValue(*slot);
            printf(" ]");
        }
        printf("\n");
#endif
        uint8_t instruction;

        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_RETURN:{
                printValue(pop());
                printf("\n");
                return INTERPRET_Ok;
            }
            case OP_NEGATE:{
                push(-pop());
                break;
            }
            case OP_ADD:
                BINARY_OP(+);
                break;
            case OP_SUBTRACT:
                BINARY_OP(-);
                break;
            case OP_MULTIPLY:
                BINARY_OP(*);
                break;
            case OP_DIVIDE:
                BINARY_OP(/);
                break;
        }
    }

#undef BINARY_OP
#undef READ_CONSTANT
#undef READ_BYTE
}


static void resetStack() {
    vm.stackTop = vm.stack;
}

void initVM() {
    resetStack();
}
void freeVM() {

}

InterpretResult interpret(Chunk *chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}