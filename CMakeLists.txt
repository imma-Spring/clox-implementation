cmake_minimum_required(VERSION 3.14)

# Use `ccache` if it is installed in system's PATH
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()
# Export compilation database in JSON format.
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

project(CLox C)

add_executable(
  clox
  src/main.c
  src/memory.c
  src/chunks.c
  src/debug.c
  src/value.c
  src/vm.c
  src/compiler.c
  src/scanner.c
  src/object.c
  src/table.c
)
