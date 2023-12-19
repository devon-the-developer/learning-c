#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_num_voters(int *amount_of_voters, int *max_voters);

int main(int argc, char *argv[])
{
    int max_voters = 10;
    int amount_of_voters;

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
            printf("Memory allocation failed for sttring %d. \n", current_index + 1);

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
    free(candidates);
    return 0;
}

int get_num_voters(int *amount_of_voters, int *max_voters)
{
    printf("Number of voters: ");
    scanf("%i", amount_of_voters);
    if(*amount_of_voters > *max_voters)
    {
        printf("Max amount of voters is %i \n", *max_voters);
        return 1;
    }
    return 0;
}