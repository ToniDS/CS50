#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    string text = get_string("Text: ");
    float words = 1;
    float letters = 0;
    float sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // calculate average number of letters
        if ((text[i] >= 'a' && text[i] <= 'z') ||
            (text[i] >= 'A' && text[i] <= 'Z'))
            {
                letters ++;
            }
        if ((text[i] == '.') || (text[i] == '!') || (
                text[i] == '?')) 
            {
                sentences ++;
            }  
        if (text[i] == ' ')
        {
            words ++;
        }
    }
    /*printf("Letters:");
    printf("%f\n", letters);
    printf("Words: ");
    printf("%f\n", words);
    printf("Sentences: ");
    printf("%f\n", sentences);
    */
    float L = (letters/words)*100;
    float S;
    S = (sentences/words)*100;
    float readability;
    readability = 0.0588 * L - 0.296 * S - 15.8;
    printf("%f", readability);
    if (readability < 1) {
        printf("Before Grade 1");
    }
    else if (readability >= 16) {
        printf("Grade 16+");
    }
    else {
        int grade = round(readability);
        printf("Grade %i", grade);
    }
}