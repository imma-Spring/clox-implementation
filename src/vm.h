#pragma once

#include "chunks.h"
#include "common.h"
#include "object.h"
#include "table.h"
#include <stdint.h>

#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct CallFrame {
  ObjClosure *closure;
  uint8_t *ip;
  Value *slots;
} CallFrame;

typedef struct VM {
  CallFrame frames[FRAMES_MAX];
  size_t frame_count;
  Value stack[STACK_MAX];
  Value *stack_top;
  Table globals;
  Table strings;
  ObjUpvalue *open_upvalues;
  Obj *objects;
} VM;

typedef enum InterpretResult {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR,
} InterpretResult;

extern VM vm;

void init_VM();
void free_VM();
InterpretResult interpret(const char *source);
void push(Value value);
Value pop();
