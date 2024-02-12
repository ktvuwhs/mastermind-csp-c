#include "../includes/main.h"

int main(void)
{
    const size_t kSize = 4;
    uint8_t num_guess = 0;
    bool isWin = false;
    char result[] = "XXXX";
    uint8_t* code = MakeCode(kSize);
    uint8_t* guess = (uint8_t*) malloc(kSize);

    while (!isWin)
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