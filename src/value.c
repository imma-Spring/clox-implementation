#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "memory.h"
#include "object.h"
#include "value.h"

bool values_equal(Value a, Value b) {
  if (a.type != b.type) {
    return false;
  }
  switch (a.type) {
  case VAL_BOOL:
    return AS_BOOL(a) == AS_BOOL(b);
  case VAL_NIL:
    return true;
  case VAL_NUMBER:
    return AS_NUMBER(a) == AS_NUMBER(b);
  case VAL_OBJ: {
    ObjString *a_string = AS_STRING(a);
    ObjString *b_string = AS_STRING(b);
    return a_string->length == b_string->length &&
           memcmp(a_string->chars, b_string->chars, a_string->length) == 0;
  }
  default:
    return false;
  }
}

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
  switch (value.type) {
  case VAL_BOOL:
    printf(AS_BOOL(value) ? "true" : "false");
    break;
  case VAL_NIL:
    printf("nil");
    break;
  case VAL_NUMBER:
    printf("%g", AS_NUMBER(value));
    break;
  case VAL_OBJ:
    print_object(value);
    break;
  }
}
