#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int word_maxsize = 10;
    char *player1_word = malloc((word_maxsize * sizeof(char)) + 1);
    char *player2_word = malloc((word_maxsize * sizeof(char)) + 1);
    if (player1_word == NULL || player2_word == NULL) {
        return 1;
    }

    printf("Player 1: ");
    scanf("%s", player1_word);
    printf("Player 2: ");
    scanf("%s", player2_word);

    //takeinput(*player1_word, *player2_word);
    printf("%s %s", player1_word, player2_word);

    free(player1_word);
    free(player2_word);
    return 0;
}