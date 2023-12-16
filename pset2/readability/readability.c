#include <stdio.h>
#include <ctype.h>

int countStringValues(char *text, int *letterCount, int *wordCount, int *sentenceCount);
float getAveragePer100Words(int numtoAveragePer100, int numofWords);
float calculateTextScore(float L, float S);
int gradeScore(float score);

int main(void)
{
    int letterCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;
    //char *grade1String = "One fish. Two fish. Red fish. Blue fish.";
    //char *grade2String = "Would you like them here or there? I would not like them here or there. I would not like them anywhere.";
    //char *grade3String = "Congratulations! Today is your day. You're off to Great Places! You're off and away!";
    char *stringToGrade = "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.";
        countStringValues(stringToGrade, &letterCount, &wordCount, &sentenceCount);
    printf("\n %i %i %i \n", letterCount, wordCount, sentenceCount);

    // L is average number of letters per 100 words
    float L = getAveragePer100Words(letterCount, wordCount);
    // S is average number of sentences per 100 words
    float S = getAveragePer100Words(sentenceCount, wordCount);
    printf("%.2f \n", L);
    printf("%.2f \n", S);
    printf("%f \n", calculateTextScore(L, S));
    gradeScore(calculateTextScore(L, S));
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
        } else if (text[currentIndex] == '.' || text[currentIndex] == '?' || text[currentIndex] == '!')
        {
            ++*sentenceCount;
            ++*wordCount;
        } else if (text[currentIndex] == ' ' && currentIndex != 0 && text[currentIndex - 1] != '.' && text[currentIndex -1] != '!' )
        {
            ++*wordCount;
        }
    }

    return 0;

}

float getAveragePer100Words(int numtoAveragePer100, int numofWords)
{
    return ((float)numtoAveragePer100 / numofWords) * 100;
}

float calculateTextScore(float L, float S)
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}

int gradeScore(float score)
{
    int roundedScore = (int)(score < 0 ? (score - 0.5) : (score + 0.5));
    if (roundedScore < 1)
    {
        printf("Grade 1 \n");
    }
    else if (roundedScore < 16)
    {
        printf("Grade %i \n", roundedScore);
    } else 
    {
        printf("Grade 16+ \n");
    }
    return 0;
}