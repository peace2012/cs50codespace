#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *word;
    int number;
} WordNumber;

WordNumber scrabble[] = {{"aeilnorstu", 1}, {"dg", 2}, {"bcmp", 3}, {"fhvwy", 4},
                         {"k", 5},          {"jx", 8}, {"qz", 10}};

int player_score(string input_name);
string get_input(string input_name);
bool is_string(const char *str);
string to_lowercase(char *str);
int get_score(const char *str, WordNumber array[], int length);

int main(void)
{
    // execute function to calculate individual players scores
    int p1_score = player_score("Player 1");
    int p2_score = player_score("Player 2");

    // logic to compare scores
    if (p1_score < p2_score)
    {
        printf("Player 2 wins!\n");
    }
    else if (p1_score == p2_score)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 1 wins!\n");
    }
}

// calculate individual players scores
int player_score(string input_name)
{
    string word = get_input(input_name);
    word = to_lowercase(word);
    int length = sizeof(scrabble) / sizeof(scrabble[0]);
    int score = get_score(word, scrabble, length);
    return score;
}

// gets string from player
string get_input(string input_name)
{
    string word = 0;
    do
    {
        word = get_string("%s: ", input_name);
    }
    while (is_string(word) == false);

    return word;
}

// checks user input is valid word
bool is_string(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}

// string to lowercase
string to_lowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

// loop through struct find input char in WordNumber array, get letter score, return total score
int get_score(const char *str, WordNumber array[], int length)
{
    int score = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; j < length; j++)
        {
            for (int k = 0; array[j].word[k] != '\0'; k++)
            {
                if (str[i] == array[j].word[k])
                {
                    score += array[j].number;
                }
            }
        }
    }
    return score;
}
