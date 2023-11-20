#pragma once

#include "common.h"

typedef double Value;

typedef struct Value_Array {
  size_t capacity;
  size_t count;
  Value *value;
} Value_Array;

void init_value_array(Value_Array *arr);
void write_value_array(Value_Array *arr, Value val);
void free_value_array(Value_Array *arr);
