#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    float words = argc;
    float letters = 0;
    float sentences = 0;
    for (int i = 1; i < argc; i++)
    {
        // calculate average number of letters
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') ||
            (argv[i][j] >= 'A' && argv[i][j] <= 'Z'))
            {
                letters ++;
            }
            if ((argv[i][j] == '.') || (argv[i][j] == '!') || (
                argv[i][j] == '?')) 
                {
                    sentences ++;
                }  
        }
    }
    float L = letters/argc*100;
    printf("%f", L);
    float S = sentences/argc*100;
    float readability;
    readability = 0.0588 * L - 0.296 * S - 15.8;
    printf("%f", readability);
}