#include "common.h"
#include "compiler.h"
#include "scanner.h"
#include <stdio.h>

static void advance() {
  parser.previous = parser.current;
  for (;;) {
  }
}

bool compiler(const char *source, Chunk *chunk) {
  init_scanner(source);
  advance();
  consume(TOKEN_EOF, "Expect end of expression");
}
