#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int CheckIfRepeated (char* key, int key_length);

int main (int argc, string argv[])
{
    // if > 1 command line argument return error
    if (argc >= 3)
    {
        printf("Error - enter 1 key of 26 characters\n");
        return 1;
    }

    else
    {
        string key = argv[1];

        // get length of key entered
        int key_length = strlen(key);

        // if length of key is not 26 return error
        if (key_length != 26)
        {
            printf("Error - key must be 26 characters\n");
            return 1;
        }

        else
        {
            // loop through array confirm key has 26 characters all alpha
            for (int i = 0; i <= key_length ; i++)
            {
                if (isalpha(key[i]) == 0)
                {
                    printf("Error - all 26 characters must be alphabetical\n");
                    return 1;
                }

                else
                {
                    if (CheckIfRepeated(key, key_length) == 0)
                    {
                        printf("Error - every character in key must be unique\n");
                        return 1;
                    }

                }
            }
        }

// get string

}
}

// take first character in string
// look for character in array
// return found throw error

int CheckIfRepeated (char* key, int key_length)
{
    for (int i = 0; i < key_length; i++)
    {
        for(int j = 0; j < key_length; j++)
        {
            if (key[i] == key[j])
            {
                return 1;
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
