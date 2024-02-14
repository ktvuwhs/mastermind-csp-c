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


char* CheckCode(uint8_t* guess, uint8_t* code, const size_t size)
{
    char* result = (char*) calloc((size+1), sizeof(char));
    for (size_t i = 0; i < SIZE; ++i)
    {
        result[i] = 'X';
        if (guess[i] == code[i])
        {
            result[i] = 'O';
        }
    }
    return result;
}