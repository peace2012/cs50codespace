#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CheckIfRepeated(char *key);
string ToUpper(char *str);
string Cipher(char *plain_text, char *key);

int main(int argc, string argv[])
{
    string key = argv[1];

    // if > 1 command line argument return error
    if (argc != 2)
    {
        printf("Error - enter 1 key of 26 characters\n");
        return 1;
    }

    // loop through array confirm all 26 characters alphabetical
    int length = strlen(key);
    for (int i = 0; i < length; i++)
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

int CheckIfRepeated(char *key)
{
    int count;
    int length = strlen(key);

    for (int i = 0; i < length; i++)
    {
        count = 0;

        for (int j = 0; j < length; j++)
        {
            if (key[i] == key[j])
            {
                count++;

                if (count > 1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

string ToUpper(char *str)
{
    char *output = malloc((strlen(str) + 1) * sizeof(char));

    int length = strlen(str);
    for (int i = 0; i < length; i++)
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

string Cipher(char *plain_text, char *key)
{
    string all_caps_key = ToUpper(key);

    char *cipher = malloc((strlen(plain_text) + 1) * sizeof(char));

    int length = strlen(plain_text);
    for (int i = 0; i < length; i++)
    {
        if ((plain_text[i] >= 65 && plain_text[i] <= 90) ||
            (plain_text[i] >= 97 && plain_text[i] <= 122))
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
