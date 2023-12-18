#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verify_user_input(char *string);

int main(int argc, char *argv[])
{
    // Declaring user input variable
    char *user_string = argv[1];
    
    // Checking for the correct number of arguments
    if (argc != 2)
    {
        printf("Not the right number of arguments\n");
        return 1;
    }

    verify_user_input(user_string);

    return 0;
}

int verify_user_input(char *string)
{
    char *user_string = string;
    int current_index = 0;

    // Checking the user input is of type string
    if (user_string != NULL && user_string[0] != '\0')
    {
        printf("user_string is a string\n");
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Checking the length of the user input
    if (strlen(user_string) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check the user input is only alphabetic characters
    while (user_string[current_index] != '\0')
    {
        if (isalpha(user_string[current_index]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        else
        {
            current_index++;
        }
    }

    return 0;
}