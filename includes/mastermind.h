#ifndef _MASTERMIND_H_
#define _MASTERMIND_H_

#include <stddef.h>

int* MakeCode(size_t size);
char* CheckCode(int* guess, int* code, size_t const size);
int DifficultySize(int const diff);
unsigned int Contains(int const * const code, int target, size_t const size);

#endif