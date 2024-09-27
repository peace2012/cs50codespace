#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_input(string str);
int get_sentences(const char *str);

// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words
// Would you like them here or there? I would not like them here or there. I would not like them anywhere.

int main (void)
{
    string text = get_input("Text");

    int S = 

    printf("%i\n", S);

    // int index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("%i\n", index);
}

// gets text input
string get_input(string str)
{
    string output = get_string("%s: ", str);

    return output;
}

// count the number of sentences
int get_sentences(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != "\0"; i++)
    {
        if (str[i] == 33 || str[i] == 46 || str[i] == 63) {
            count++;
        }
    }

    return count;
}
