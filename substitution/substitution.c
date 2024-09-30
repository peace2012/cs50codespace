#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int CheckIfRepeated (char* key);
string ToUpper (char* str);
string Cipher (char* plain_text, char* key);

int main (int argc, string argv[])
{
    string key = argv[1];

    if (argc <2 )
    {
        printf("Error - must enter 1 key of 26 characters\n");
        return 1;
    }

    // if > 1 command line argument return error
    if (argc > 2)
    {
        printf("Error - enter 1 key of 26 characters\n");
        return 1;
    }

    // loop through array confirm all 26 characters alphabetical
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Error - all 26 characters must be alphabetical\n");
            return 1;
        }
    }

    // if length of key is not 26 return error
    if (strlen(key) != 26)
    {
        printf("Error - key must be 26 characters\n");
        return 1;
    }

    // use function check if each character is unique
    if (CheckIfRepeated(key) == 1)
    {
        printf("Error - every character in key must be unique\n");
        return 1;
    }

// get string to cipher from user
string plain_text = get_string("plaintext: ");

// function to cipher plain text
string cipher_text = Cipher(plain_text, key);

printf("ciphertext: %s\n", cipher_text);

return 0;
}

// loop through each character in string
// compare target to each character in array

int CheckIfRepeated (char* key)
{
    int count;

    for (int i = 0; i < strlen(key); i++)
    {
        count = 0;

        for(int j = 0; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                count++;

                if (count > 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

string ToUpper (char* str)
{
    char *output = malloc(100 * sizeof(char));

    for (int i = 0; i < strlen(str); i++)
    {
        if (isupper(str[i]) == 0)
        {
            output[i] = toupper(str[i]);
        }
        else
        {
            output[i] = str[i];
        }
    }
    return output;
}

string Cipher (char* plain_text, char* key)
{
    string all_caps_key = ToUpper(key);

    char *cipher = malloc(100 * sizeof(char));

    for (int i = 0; i < strlen(plain_text); i++)
    {
        if ((plain_text[i] >= 65 && plain_text[i] <= 90) || (plain_text[i] >= 97 && plain_text[i] <= 122))
        {
            if (isupper(plain_text[i]) == 0)
            // not an uppercase letter
            {
                cipher[i] = tolower(all_caps_key[plain_text[i] - 97]);
            }
            else
            // is uppercase
            {
                cipher[i] = toupper(all_caps_key[plain_text[i] - 65]);
            }
        }
        else
        {
            cipher[i] = plain_text[i];
        }
    }
    return cipher;
}
