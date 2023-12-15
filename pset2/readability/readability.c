#include <stdio.h>
#include <ctype.h>

int countStringValues(char *text, int *letterCount, int *wordCount, int *sentenceCount);
float getAveragePer100(int numtoAveragePer100, int numofWords);

int main(void)
{
    int letterCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;
    char *grade1String = "One fish. Two fish. Red fish. Blue fish.";

    countStringValues(grade1String, &letterCount, &wordCount, &sentenceCount);
    printf("\n %i %i %i \n", letterCount, wordCount, sentenceCount);

    // L is average number of letters per 100 words
    float L = getAveragePer100(letterCount, wordCount);
    // S is average number of sentences per 100 words
    float S = getAveragePer100(sentenceCount, wordCount);
    printf("%.2f \n", L);
    printf("%.2f \n", S);
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

float getAveragePer100(int numtoAveragePer100, int numofWords)
{
    return ((float)numtoAveragePer100 / numofWords) * 100;
}
