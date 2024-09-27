#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string get_input(string str);
int count(const char *str, const int alpha);
int count_alpha(const char *str);

int main(void)
{
    // get text string
    string text = get_input("Text");

    // count number of spaces in text string
    int no_of_spaces = count(text, ' ');

    // convert spaces to number of words
    float no_of_words = ++no_of_spaces;

    // total letters divided by total words *100
    float L = (count_alpha(text) / no_of_words) * 100;

    // count punctuation to find number of sentences
    int total_sentences = count(text, '!') + count(text, '?') + count(text, '.');

    // total sentences divided by total words *100
    float S = (total_sentences / no_of_words) * 100;

    // use formula to calculate result, round result to nearest integer
    int result = round(0.0588 * L - 0.296 * S - 15.8);

    // logic to determine printed output
    if (result <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}

// gets text input
string get_input(string str)
{
    string output = get_string("%s: ", str);
    return output;
}

// count specific alphanumeric characters in string
int count(const char *str, const int alpha)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == alpha)
        {
            count++;
        }
    }
    return count;
}

// count total alphanumeric characters in string
int count_alpha(const char *str)
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
