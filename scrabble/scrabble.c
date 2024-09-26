#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char *word;
    int number;
} WordNumber;

WordNumber scrabble[] = {{"aeilnorstu", 1}, {"dg", 2}, {"bcmp", 3}, {"fhvwy", 4}, {"k", 5}, {"jx", 8}, {"qz", 10}};

string get_word (string player);
bool is_word(const char *str);
string to_lowercase (char *str);
int get_score (const char *str, WordNumber array[], int length);

int main (void)
{
    string player_1_word = get_word("Player 1");

    player_1_word = to_lowercase(player_1_word);

    int length = sizeof(scrabble) / sizeof(scrabble[0]);
    int player_1_score = get_score(player_1_word, scrabble, length);
    printf("%i\n", player_1_score);
}

// function uses variable number of players
// runs a loop to request input word, outputs string

// gets string from player
string get_word (string player)
{
    string word = get_string("%s: ", player);
    if (is_word(word) == false)
    {
        fprintf(stderr, "Error enter valid word.\n");
        exit(1);
    }
    return word;
}

// checks user input is valid word
bool is_word(const char *str)
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
string to_lowercase (char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

// string is an array
// compare each letter to an array of scrabble letters and scores
// output the integer found

int get_score (const char *str, WordNumber array[], int length)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; j < length; j++)
        {
            for (int k = 0; array[j].word[k] != '\0'; k++) {
                if (str[i] == array[j].word[k])
                {
                return array[j].number;
                }
            }
        }
    }
    fprintf(stderr, "Error with calculating your score.")
    exit(1);
}

