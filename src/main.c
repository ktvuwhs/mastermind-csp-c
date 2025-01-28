#include "../includes/main.h"

int main(void)
{
    char* result = calloc(SIZE+1, sizeof(char));
    uint8_t num_guess = 0;
    int* code = MakeCode(SIZE);
    int* guess = calloc(SIZE, sizeof(int));

    printf("Answer is ");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d ", code[i]);
    }

    while (strcmp(result, "OOOO"))
    {
        printf("\nEnter your guess\n");
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
    code = NULL;

    free(guess);
    guess = NULL;
    
    free(result);
    result = NULL;
    return 0;
}