#include "chunks.h"
#include "common.h"
#include "debug.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Chunk chunk;
  init_chunk(&chunk);
  write_chunk(&chunk, OP_RETURN);
  disassemble_chunk(&chunk, "test chunk");
  free_chunk(&chunk);
  return EXIT_SUCCESS;
}
