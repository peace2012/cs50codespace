#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// #define ARRAY_SIZE(arr)  (sizeof((arr)) / sizeof((arr)[0]))

int main (int argc, string argv[])
{
// if > 1 command line argument return error
    if (argc >= 2)
    {
        printf("Error - enter 1 key of 26 characters");
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
            printf("Error - key must be 26 characters");
            return 1;
        }

        else
        {
            // loop through array confirm key has 26 characters all alpha
            for (int i = 0; i <= key_length ; i++)
            {
                if (isalpha(key[i]) == 0)
                {
                    printf("Error - all 26 characters must be alphabetical");
                    return 1;
                }

                else
                {
                    CheckIfRepeated(key, key_length)
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

    qsort(key, key_length, sizeof(key[0]), CompareInts);

    for (int i = 1; i < )
}

int CompareInts (const void *p1, const void *p2)
{
    int i1 = *(const int *)p1;
    int i2 = *(const int *)p2;

    return (i1 - i2);
}
