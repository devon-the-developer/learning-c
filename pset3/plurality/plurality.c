#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 20
#define MAX_VOTERS 9
// Max Number of Candidates
#define MAX_CANS 9

// Candidates have name and vote count
typedef struct
{
    char *name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANS];

// Number of candidates - set in main
int num_candidates;

int get_num_voters(int *amount_of_voters);
int ask_for_votes(int *amount_of_voters, char ***votes);
int check_valid_vote(char *vote_to_check);

int main(int argc, char *argv[])
{
    int amount_of_voters;
    char **votes;

    if(argc < 2) 
    {
        printf("Usage: %s <candidate1> <candidate2> <candidate3> ... \n", argv[0]);
        return 1;
    }

    num_candidates = argc - 1;

    for(int current_index = 0; current_index < num_candidates; current_index++)
    {
        //copy argument to candidates 
        candidates[current_index].name = strdup(argv[current_index + 1]);

        printf("Candidate %i: %s \n", current_index + 1, candidates[current_index].name);
    }
    
    if (get_num_voters(&amount_of_voters) == 1)
    {
        return 1;
    }
    ask_for_votes(&amount_of_voters, &votes);

    free(votes);
    return 0;
}

int get_num_voters(int *amount_of_voters)
{
    // Get number of voters, check not more than max.
    printf("Number of voters: ");
    scanf("%i", amount_of_voters);
    if(*amount_of_voters > MAX_VOTERS)
    {
        printf("Max amount of voters is %i \n", MAX_VOTERS);
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
            do
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
            } while (check_valid_vote((*votes)[current_index]) != 0);
        }

    }
    return 0;
}

int check_valid_vote(char *vote_to_check)
{
    int current_index = 0;
    int valid_vote = 0;
    while (valid_vote != 1 && current_index < num_candidates)
    {
        // check if current_index of candidates is == to vote_to_check
        // if is return 0 else return 1 and message not valid vote
        printf("vote_to_check: %s, current_candidate: %s \n", vote_to_check, candidates[current_index].name);
        if (strcmp(vote_to_check, candidates[current_index].name) == 0)
        {
            valid_vote = 1;
            printf("Match \n");
            break;
        }
        ++current_index;
    }
    if (valid_vote == 1)
    {
        return 0;
    }
    else
    {
        printf("Invalid Vote \n");
        return 1;
    }
}