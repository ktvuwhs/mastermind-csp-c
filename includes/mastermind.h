#ifndef _MASTERMIND_H_
#define _MASTERMIND_H_

#include "main.h"

uint8_t* MakeCode(size_t size);
uint8_t CheckCode(uint8_t* guess, uint8_t* code, char* result, const size_t kSize);

#endif