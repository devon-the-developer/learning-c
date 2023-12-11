#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scoreword(char *word);
void decidewinner(int player1score, int player2score);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    int word_maxsize = 10;
    char *player1_word = malloc((word_maxsize * sizeof(char)) + 1);
    char *player2_word = malloc((word_maxsize * sizeof(char)) + 1);
    if (player1_word == NULL || player2_word == NULL)
    {
        return 1;
    }

    printf("Player 1: ");
    scanf("%s", player1_word);
    printf("Player 2: ");
    scanf("%s", player2_word);

    decidewinner(scoreword(player1_word), scoreword(player2_word));    

    free(player1_word);
    free(player2_word);
    return 0;
}

int scoreword(char *word)
{
    int wordscore = 0;
    for (int placeinword = 0; word[placeinword] != '\0'; ++placeinword)
    {
        char lettertocheck = toupper(word[placeinword]);
        wordscore = wordscore + POINTS[lettertocheck - 'A'];
    }
    return wordscore;
}

void decidewinner(int player1_score, int player2_score)
{

    if (player1_score > player2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1_score < player2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}