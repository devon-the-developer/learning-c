#include <stdio.h>

int main(int argc, char *argv[])
{
    // Declaring user input variable
    char *user_input = argv[1];
    
    // Checking for the correct number of arguments
    if (argc != 2)
    {
        printf("Not the right number of arguments\n");
        return 1;
    }

    // Checking the user input is of type string
    if (user_input != NULL && user_input[0] != '\0')
    {
        printf("user_input is a string\n");
    }
    else 
    {
        printf("user_input is not a string\n");
        return 1;
    }

    return 0;
}