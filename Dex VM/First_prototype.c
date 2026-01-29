#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1024

// Instruction opcodes
#define PUSH  1
#define ADD   2
#define MUL   3
#define PRINT 4
#define CALL  5
#define RET   6
#define HLT   7

typedef struct {
    int pc;
    int sp;
    int stack[STACK_SIZE];
    int running;
} VM;

void push(VM *vm, int value) {
    if (vm->sp >= STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    vm->stack[++vm->sp] = value;  // Increment first, then store
}

int pop(VM *vm) {
    if (vm->sp < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return vm->stack[vm->sp--];  // Return current, then decrement
}

void run(VM *vm, int *code) {
    while (vm->running) {
        int instr = code[vm->pc++];
        switch (instr) {
            case PRINT: {
                printf("Output: %d\n", pop(vm));
                break;
            }
                
            case PUSH: {
                push(vm, code[vm->pc++]);
                break;
            }
                
            case ADD: {
                int b = pop(vm);  // Note: pop in reverse order
                int a = pop(vm);
                int result = a + b;
                push(vm, result);
                break;
            }
                
            case MUL: {
                int b = pop(vm);
                int a = pop(vm);
                int result = a * b;
                push(vm, result);
                break;
            }
                
            case CALL: {
                int target = code[vm->pc++];
                push(vm, vm->pc);
                vm->pc = target;
                break;
            }
                
            case RET: {
                vm->pc = pop(vm);
                break;
            }
                
            case HLT: {
                vm->running = 0;
                break;
            }
                
            default: {
                printf("Unknown instruction: %d\n", instr);
                vm->running = 0;
                break;
            }
        }
    }
}

int main() {
    VM vm;
    vm.running = 1;
    vm.sp = -1;  // Stack pointer starts at -1 (empty)
    vm.pc = 0;
    
    int program[] = {
        PUSH, 3,
        PUSH, 2,
        ADD,
        PUSH, 4,
        MUL,
        PRINT,
        HLT
    };
    
    run(&vm, program);
    
    return 0;
}
