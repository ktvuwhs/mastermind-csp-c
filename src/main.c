#include "../includes/main.h"

int main(void)
{
    srand(time(0));
    printf("Welcome to Number Wordle!\nChoose your difficulty:\n1. Easy\n2. Medium\n3. Hard\n> ");
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
    char* win_con = calloc(size+1, sizeof(char));
    uint8_t num_guess = 0;
    int* code = MakeCode(size);
    int* guess = calloc(size, sizeof(int));

    // printf("Answer is ");
    // for (int i = 0; i < size; ++i)
    // {
    //     printf("%d ", code[i]);
    // }

    for (int i = 0; i < size; ++i)
    {
        win_con[i] = 'O';
    }
    win_con[size] = '\0';

    printf("Try and guess the secret code.  An \"O\" means your number is correct, and an \"X\" means it is incorrect.\n");
    while (strcmp(result, win_con))
    {
        printf("\nEnter your guess (%d numbers) with spaces in between each number\n", size);
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