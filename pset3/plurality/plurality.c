#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 20

int get_num_voters(int *amount_of_voters, int *max_voters);
int ask_for_votes(int *amount_of_voters, char ***votes);

int main(int argc, char *argv[])
{
    int max_voters = 10;
    int amount_of_voters;
    char **votes;

    if(argc < 2) 
    {
        printf("Usage: %s <candidate1> <candidate2> <candidate3> ... \n", argv[0]);
        return 1;
    }

    int num_candidates = argc - 1;

    char **candidates = (char **)malloc(num_candidates * sizeof(char *));

    // Checks if the pointer is Null, indicating an failure in memory allocation.
    if (candidates == NULL)
    {
        printf("Memory allocation failed. \n");
        return 1;
    }

    for(int current_index = 0; current_index < num_candidates; current_index++)
    {
        //copy argument to candidates 
        candidates[current_index] = strdup(argv[current_index + 1]);

        //check candidate isn't NULL --> failure in memory allocation
        if(candidates[current_index] == NULL)
        {
            printf("Memory allocation failed for string %d. \n", current_index + 1);

            //Clean up: Free previously allocated Memory
            for (int index_to_clean = 0; index_to_clean < current_index; index_to_clean++)
            {
                free(candidates[index_to_clean]);
            }

            free(candidates);
            return 1;
        }

        printf("Candidate %i: %s \n", current_index + 1, candidates[current_index]);
    }
    
    get_num_voters(&amount_of_voters, &max_voters);
    ask_for_votes(&amount_of_voters, &votes);

    free(votes);
    free(candidates);
    return 0;
}

int get_num_voters(int *amount_of_voters, int *max_voters)
{
    // Get number of voters, check not more than max.
    printf("Number of voters: ");
    scanf("%i", amount_of_voters);
    if(*amount_of_voters > *max_voters)
    {
        printf("Max amount of voters is %i \n", *max_voters);
        return 1;
    }
    return 0;
}

int ask_for_votes(int *amount_of_voters, char ***votes)
{
    // Allocate memory for votes
    *votes = (char **)malloc(*amount_of_voters * sizeof(char *));
    if (*votes == NULL)
    {
        printf("Memory allocation failed. \n");
        return 1;
    }

    // Consume newline character left in the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Assign each vote to votes[]
    for(int current_index = 0; current_index < *amount_of_voters; current_index++)
    {
        (*votes)[current_index] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        if ((*votes)[current_index] == NULL)
        {
            printf("Memory allocation failed for vote %d. \n", current_index + 1);

            // Clean up: Free previously allocated Memory
            for (int index_to_clean = 0; index_to_clean < current_index; index_to_clean++)
            {
                if((*votes)[index_to_clean] != NULL)
                {
                    free((*votes)[index_to_clean]);
                }
            }
            return 1;
        } 
        else 
        {
            printf("Vote: ");
            if (fgets((*votes)[current_index], MAX_STRING_LENGTH, stdin) != NULL)
            {
                // Remove the newline character if it exists
                size_t len = strlen((*votes)[current_index]);
                if (len > 0 && (*votes)[current_index][len - 1] == '\n')
                {
                    (*votes)[current_index][len - 1] = '\0';
                }
                printf("Stored Vote: %s\n", (*votes)[current_index]);
            }
            else 
            {
                printf("Error reading input. \n");
            }
        }

    }
    return 0;
}