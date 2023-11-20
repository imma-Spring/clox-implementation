#pragma once
#include "common.h"
#include "value.h"

typedef enum Op_Code{
  OP_RETURN,
} Op_Code;

typedef struct Chunk {
  size_t count;
  size_t capacity;
  uint8_t *code;
  Value_Array constants;
} Chunk;

void init_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte);
void free_chunk(Chunk *chunk);
