# My C Lib
This is basically the things that I have made in C and might use later (as a library or just for reference). Everything should be documented in its header file (except when its not, because I'm lazy like that sometimes)

## Things
The things that I have made

### > DLL.c - Doubly Linked List
This is my implementation of a Doubly Linked List. Its probably a bit of a naive or possibly wrong way to implement this. But, that is because I did basically no research for this and made it based on the my own knowledge that a Doubly Linked List is made up of an object that has a pointer to the previous object and also the next object. There is also 2 example code, one is a demo (DLLDemo.C) and a benchmark (DLLBench.c). Oh and it also only works for integers, but that is easily modifyable in the code, though I have no idea how to make it work with mixed data types or easily change the data type without modifying the library code itself.

### aaand thats it..
The plan is to add more things here as I make more things, so I can use it in the future for reference.

## Usage
Basically, just `#define` what implementation you want to include and then include the library.

For example, this will include the Doubly Linked List implementation:
```
#define DLL_IMPL
#include "../MyCLib.h"
```
