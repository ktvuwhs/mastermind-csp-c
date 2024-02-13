#include "../includes/main.h"

int main(void)
{
    const size_t kSize = 4;
    uint8_t num_guess = 0;
    int isWin = 0;
    char result[] = "XXXX";
    uint8_t* code = MakeCode(kSize);
    uint8_t* guess = (uint8_t*) malloc(kSize);

    printf("Answer is 1 7 4 0\n");

    while (isWin != 1)
    {
        printf("Enter your guess\n");
        for (size_t i = 0; i < kSize; ++i)
        {
            scanf("%d", &guess[i]);
        }

        isWin = CheckCode(guess, code, result, kSize);
        printf("%s\n", result);
        ++num_guess;
    }

    printf("It took you %d guesses\n", num_guess);
    
    free(code);
    free(guess);
    code = NULL;
    guess = NULL;
    return 0;
}