#include "../includes/main.h"

int main(void)
{
    char* result = calloc(SIZE+1, sizeof(char));
    uint8_t num_guess = 0;
    uint8_t* code = MakeCode(SIZE);
    uint8_t* guess = calloc(SIZE, sizeof(uint8_t));

    printf("Answer is 1 7 4 0\n");

    while (strcmp(result, "OOOO"))
    {
        printf("Enter your guess\n");
        for (size_t i = 0; i < SIZE; ++i)
        {
            scanf_s("%d", &guess[i]);
        }

        free(result);
        result = CheckCode(guess, code, SIZE);
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