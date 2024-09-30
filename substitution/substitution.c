#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int CheckIfRepeated (char* key, int key_length);

int main (int argc, string argv[])
{
    string key = argv[1];
    int key_length = strlen(key);

    // if > 1 command line argument return error
    if (argc > 2)
    {
        printf("Error - enter 1 key of 26 characters\n");
        return 1;
    }

    // loop through array confirm all 26 characters alphabetical
    for (int i = 0; i < key_length; i++)
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

    if (CheckIfRepeated(key, key_length) == 1)
    {
        printf("Error - every character in key must be unique\n");
        return 1;
    }

// get string


}

// take first character in string
// look for character in array
// return found throw error

int CheckIfRepeated (char* key, int key_length)
{
    int count;

    for (int i = 0; i < key_length; i++)
    {
        count = 0;

        for(int j = 0; j < key_length; j++)
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


//     qsort(key, key_length, sizeof(key[0]), CompareInts);

//     for (int i = 0; i <= key_length; i++)
//     {
//         int res = bsearch(key[i], key, key_length, sizeof(key[0]), CompareInts);

//     }
// }

// int CompareInts (const void *p1, const void *p2)
// {
//     int i1 = *(const int *)p1;
//     int i2 = *(const int *)p2;

//     return (i1 - i2);
// }
