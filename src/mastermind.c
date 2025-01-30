#include "../includes/mastermind.h"

#include <stdlib.h>

int* MakeCode(size_t size)
{
    int* p = (int*) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i)
    {
        p[i] = rand() % 10;
    }
    return p;
}


char* CheckCode(int* guess, int* code, size_t const size)
{
    char* result = (char*) calloc((size+1), sizeof(char));
    for (size_t i = 0; i < size; ++i)
    {
        result[i] = 'X';
        if (guess[i] == code[i])
        {
            result[i] = 'O';
        }
    }
    result[size] = '\0';
    return result;
}

int DifficultySize(int const diff) {
    if (diff == 2) return 6;
    if (diff == 3) return 8;
    return 4;
}