#include "../includes/main.h"

int main(void)
{
    srand(time(0));
    printf("Choose your difficulty:\n1. Easy\n2. Medium\n3. Hard\n> ");
    int diff = 0;
    int size = 4;
    scanf("%d", &diff);
    switch (diff) {
        case 2:
            size = 6;
            break;
        case 3:
            size = 8;
            break;
        case 1:
        default:
            size = 4;
            break;
    }
    char* result = calloc(size+1, sizeof(char));
    uint8_t num_guess = 0;
    int* code = MakeCode(size);
    int* guess = calloc(size, sizeof(int));

    printf("Answer is ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", code[i]);
    }

    while (strcmp(result, "OOOO"))
    {
        printf("\nEnter your guess (%d numbers)\n", size);
        for (size_t i = 0; i < size; ++i)
        {
            scanf("%d", &guess[i]);
        }

        free(result);
        result = CheckCode(guess, code, size);
        printf("%s\n", result);
        ++num_guess;
    }

    printf("It took you %d guesses\n", num_guess);
    
    free(code);
    code = NULL;

    free(guess);
    guess = NULL;
    
    free(result);
    result = NULL;
    return 0;
}