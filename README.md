# clox
## clox is a dynamically typed, garbage collected language with support for OOP and has first class functions
This repository is for me to keep track of my progress with implementing clox following the guide in (crafting interpreters)[craftinginterpreters.com].
If you are reading this, I have finished implemening the compiler, the vm, as well as the optimizations layed out in the book.
## Use
### Dependencies
- cmake (verion *3.14* or up)
- a working c compiler (*this **does not** work with a c++ compiler as it uses c++ keywords as variables*)

## Build
1. Clone this repository onto your machine.
   ```bash
   git clone https://github.com/imma-Spring/clox-implementation.git
   ```
2. Customize the tags in `common.h` to your liking (*NaN boxing may not work on your machine so if you are getting errors when compiling, just replace NAN_BOXING with _NAN_BOXING*)
3. Run
   ```bash
   cmake -B bld & cmake --build bld
   ```
4. Run
   ```bash
   ./bld/clox
   ```
   to run the REPL
   or
   ```bash
   ./bld/clox your_file.lox
   ```
   to run a file
