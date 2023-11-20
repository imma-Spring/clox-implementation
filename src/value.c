#include <stddef.h>
#include <stdio.h>

#include "memory.h"
#include "value.h"

void init_value_array(Value_Array *arr) {
  arr->value = NULL;
  arr->capacity = 0;
  arr->count = 0;
}

void write_value_array(Value_Array *arr, Value val) {
  if (arr->capacity < arr->count + 1) {
    size_t old_capacity = arr->capacity;
    arr->capacity = GROW_CAPACITY(old_capacity);
    arr->value = GROW_ARRAY(Value, arr->value, old_capacity, arr->capacity);
  }
  arr->value[arr->count] = val;
  arr->count++;
}

void free_value_array(Value_Array *arr) {
  FREE_ARRAY(Value, arr->value, arr->capacity);
  init_value_array(arr);
}

void print_value(Value value) {
  printf("%g", value);
}
