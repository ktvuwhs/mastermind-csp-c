#ifndef _MASTERMIND_H_
#define _MASTERMIND_H_

#include "main.h"

uint8_t* MakeCode(size_t size);
char* CheckCode(uint8_t* guess, uint8_t* code, const size_t size);

#endif