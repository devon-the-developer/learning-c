#include <stdio.h>
#include <ctype.h>

int countStringValues(char *text, int *letterCount, int *sentenceCount);

int main(void)
{
    int letterCount = 0;
    int sentenceCount = 0;
    char *grade1String = "One fish. Two fish. Red fish. Blue fish.";
    //printf("%s", grade1string);
    countStringValues(grade1String, &letterCount, &sentenceCount);
    printf("\n %i %i \n", letterCount, sentenceCount);
    return 0;
}

int countStringValues(char *text, int *letterCount, int *sentenceCount)
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
        }
    }

    return 0;

}