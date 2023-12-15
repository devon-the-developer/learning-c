#include <stdio.h>
#include <ctype.h>

int counttheletters(char *text);

int main(void)
{
    char *grade1string = "One fish. Two fish. Red fish. Blue fish.";
    //printf("%s", grade1string);
    int lettersinstring = counttheletters(grade1string);
    printf("\n %i \n", lettersinstring);
    return 0;
}

int counttheletters(char *text)
{
    int count = 0;
    for (int currentindex = 0; text[currentindex] != '\0'; ++currentindex)
    {
        printf("%c", text[currentindex]);
        if(isalpha(text[currentindex]))
        {
            ++count;
        }
    }
    return count;
}

