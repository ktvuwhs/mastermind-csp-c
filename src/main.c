#include "../includes/main.h"

int main(void)
{
    char* result = calloc(SIZE+1, sizeof(char));
    uint8_t num_guess = 0;
    uint8_t* code = MakeCode(SIZE);
    uint8_t* guess = (uint8_t*) malloc(SIZE);

    printf("Answer is 1 7 4 0\n");

    while (strcmp(result, "OOOO"))
    {
        printf("Enter your guess\n");
        for (size_t i = 0; i < SIZE; ++i)
        {
            scanf("%d", &guess[i]);
        }

        free(result);
        result = CheckCode(guess, code, SIZE);
        printf("%s\n", result);
        ++num_guess;
    }

    printf("It took you %d guesses\n", num_guess);
    
    free(code);
    free(guess);
    free(result);
    code = NULL;
    guess = NULL;
    result = NULL;
    return 0;
}