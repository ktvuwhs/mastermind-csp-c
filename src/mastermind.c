#include "../includes/mastermind.h"

uint8_t* MakeCode(size_t size)
{
    uint8_t* p = (uint8_t*) malloc(size*sizeof(uint8_t));
    for (size_t i = 0; i < size; ++i)
    {
        p[i] = rand() % 10;
    }
    return p;
}


bool CheckCode(uint8_t* guess, uint8_t* code, char* result, const size_t kSize)
{
    size_t output = 0;
    for (size_t i = 0; i < kSize; ++i)
    {
        result[i] = 'X';
        if (guess[i] == code[i])
        {
            result[i] = 'O';
            ++output;
        }
    }
    return output == kSize;
}