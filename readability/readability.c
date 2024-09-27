#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string get_input (string str);
int count (const char *str, const int alpha);
float count_alpha(const char *str);

// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words
// Would you like them here or there? I would not like them here or there. I would not like them anywhere.

int main (void)
{
    string text = get_input("Text");

    int no_of_spaces = count(text, 32);
    if (no_of_spaces <= 100) {

        // count punctuation to find number of sentences
        int S = 0;

        S = S + count(text, 33) + count(text, 63) + count(text, 46);

        printf("%i\n", S);

        // divide no. of characters by number of spaces + 1
        float L = 0;

        L = L + (count_alpha(text) / (no_of_spaces++));

        printf("%f\n", L);

    }
    else
    {
        printf("I can only count to 100.");
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
int count (const char *str, const int alpha)
{
    int count = 0;

        for (int i = 0; str[i] !='\0'; i++)
    {
        if (str[i] == alpha) {
            count++;
        }
    }

    return count;
}

// loop through array
// if char increase count
float count_alpha(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            count++;
        }
    }

    return count;
}
