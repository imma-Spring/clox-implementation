#include "debug.h"
#include "chunks.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

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

static size_t constant_instruction(const char *name, Chunk *chunk,
                                   size_t offset) {
  uint8_t constant = chunk->code[offset + 1];
  printf("%-16s %4d '", name, constant);
  print_value(chunk->constants.value[constant]);
  printf("'\n");
  return offset + 2;
}

size_t disassemble_instruction(Chunk *chunk, size_t offset) {
  printf("%04zu ", offset);
  if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
    printf("   | ");
  } else {
    printf("%4zu ", chunk->lines[offset]);
  }

  switch (chunk->code[offset]) {
  case OP_CONSTANT:
    return constant_instruction("OP_CONSTANT", chunk, offset);
  case OP_ADD:
    return simple_instruction("OP_ADD", offset);
  case OP_SUBTRACT:
    return simple_instruction("OP_SUBTRACT", offset);
  case OP_MULTIPLY:
    return simple_instruction("OP_MULTIPLY", offset);
  case OP_DIVIDE:
    return simple_instruction("OP_DIVIDE", offset);
  case OP_NEGATE:
    return simple_instruction("OP_NEGATE", offset);
  case OP_RETURN:
    return simple_instruction("OP_RETURN", offset);
  default:
    printf("Unkown opcode %d\n", chunk->code[offset]);
    return offset - 1;
  }
}
