#include <cs50.h>
#include <stdio.h>

string get_input(string str);

// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words
// Would you like them here or there? I would not like them here or there. I would not like them anywhere.

int main (void)
{
    string text = get_input("Text");
    printf("%i\n", text[5]);

    // int index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("%i\n", index);
}

// gets text input
string get_input(string str)
{
    string output = get_string("%s: ", str);

    return output;
}
