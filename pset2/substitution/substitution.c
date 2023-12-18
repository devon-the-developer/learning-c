#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verify_user_key(char *string);
int get_text_from_user(char *string);
int convert_text(char *key, char *plain_text, char *cipher_text);

int main(int argc, char *argv[])
{
    // Declaring user key variable
    char *user_key = argv[1];
    char plain_text[99];
    char cipher_text[99];

    // Checking for the correct number of arguments
    if (argc != 2)
    {
        printf("Not the right number of arguments\n");
        return 1;
    }

    verify_user_key(user_key);
    get_text_from_user(plain_text);
    convert_text(user_key, plain_text, cipher_text);

    printf("ciphertext: %s\n", cipher_text);
    return 0;
}

int verify_user_key(char *string)
{
    char *user_key = string;
    int current_index = 0;

    // Checking the user key is of type string
    if (user_key != NULL && user_key[0] != '\0')
    {
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Checking the length of the user key
    if (strlen(user_key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check the user key is only alphabetic characters
    while (user_key[current_index] != '\0')
    {
        if (isalpha(user_key[current_index]) == 0)
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

int get_text_from_user(char *string)
{
    // Get plain text from user input and store
    char *plain_text_pointer = string;
    printf("plaintext: ");
    fgets(plain_text_pointer, 99, stdin);
    return 0;
}

int convert_text(char *key, char *plain_text, char *cipher_text)
{
    int current_index = 0;

    while(plain_text[current_index] != '\0')
    {
        char letter_to_convert = plain_text[current_index];

        // Check if current letter is in alphabet
        if (isalpha(letter_to_convert))
        {
            // Convert to upper case if necessary
            if (islower(letter_to_convert))
            {
                letter_to_convert = toupper(letter_to_convert);
            }
            // Find the index of the letter in alphabet
            int letter_index_in_key = letter_to_convert - 'A';
            // Find this index in the key and add it to the cipher text
            cipher_text[current_index] = key[letter_index_in_key];
        } else {
            // if not not in alphabet just leave as is.
            cipher_text[current_index] = letter_to_convert;
        }

        current_index++;
    }
    
    return 0;
}