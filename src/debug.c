#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "chunks.h"
#include "debug.h"

void disassemble_chunk(Chunk *chunk, const char *name) {
  printf("== %s ==\n", name);
  for (size_t offset = 0; offset < chunk->count;) {
    offset = disassemble_instruction(chunk, offset);
  }
}

static size_t simple_instruction(const char *name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

static size_t constant_instruction(const char *name, Chunk *chunk, size_t offset) {
  uint8_t constant = chunk->code[offset + 1];
  printf("%-16s %4d '", name, constant);
  print_value(chunk->constants.value[constant]);
  printf("'\n");
  return offset + 2;
}

size_t disassemble_instruction(Chunk *chunk, size_t offset) {
  printf("%04zu ", offset);

  switch (chunk->code[offset]) {
    case OP_CONSTANT:
      return constant_instruction("OP_CONSTANT", chunk, offset);
    case OP_RETURN:
      return simple_instruction("OP_RETURN", offset);
    default:
      printf("Unkown opcode %d\n", chunk->code[offset]);
      return offset - 1;
  }
}
