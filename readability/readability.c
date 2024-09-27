#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_input (string str);
int count (const char *str, const int ascii_dec);

// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words
// Would you like them here or there? I would not like them here or there. I would not like them anywhere.

int main (void)
{
    string text = get_input("Text");

    int no_of_spaces = count(text, 32);
    if (no_of_spaces <= 100) {
        printf("less than 100 words\n");
    }
    else
    {
        printf("more than 100 words\n");
    }

    // int index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("%i\n", index);
}

// gets text input
string get_input (string str)
{
    string output = get_string("%s: ", str);

    return output;
}

// count the number of something in a string
int count (const char *str, const int ascii_dec)
{
    int count = 0;

        for (int i = 0; str[i] != "\0"; i++)
    {
        if (str[i] == character) {
            count++;
        }
    }

    return count;
}

// // count the number of sentences
// int get_sentences(const char *str)
// {
//     int count = 0;

//     for (int i = 0; str[i] != "\0"; i++)
//     {
//         if (str[i] == 33 || str[i] == 46 || str[i] == 63) {
//             count++;
//         }
//     }

//     return count;
// }
