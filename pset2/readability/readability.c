#include <stdio.h>
#include <ctype.h>

int countStringValues(char *text, int *letterCount, int *wordCount, int *sentenceCount);
// int getAverage(int numToAverage);

int main(void)
{
    int letterCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;
    char *grade1String = "One fish. Two fish. Red fish. Blue fish.";
    //printf("%s", grade1string);
    countStringValues(grade1String, &letterCount, &wordCount, &sentenceCount);
    printf("\n %i %i %i \n", letterCount, wordCount, sentenceCount);
    return 0;
}

int countStringValues(char *text, int *letterCount, int *wordCount, int *sentenceCount)
{
   
    for (int currentIndex = 0; text[currentIndex] != '\0'; ++currentIndex)
    {
        printf("%c", text[currentIndex]);
        if(isalpha(text[currentIndex]))
        {
            ++*letterCount;
        } else if (text[currentIndex] == '.')
        {
            ++*sentenceCount;
            ++*wordCount;
        } else if (text[currentIndex] == ' ' && currentIndex != 0 && text[currentIndex - 1] != '.')
        {
            ++*wordCount;
        }
    }

    return 0;

}

// int getAverage(int numToAverage)
// {

// }
