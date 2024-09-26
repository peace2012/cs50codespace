#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

string get_word (string player);
bool is_word(const char *str);

// // variable for number of players
// const int N = 2;

int main (void)
{
    string player_1_word = get_word("Player 1");
    string player_2_word = get_word("Player 2");


    // int player_1_score = 0;
    // int player_2_score = 0;

}

// function uses variable number of players
// runs a loop to request input word, outputs string

// gets string from player
string get_word (string player)
{
        string word = get_string("%s: ", player);
        if (is_word(word) == false) {
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

// string is an array
// compare each letter to an array of scrabble letters and scores
// output the integer found

// int get_score (const char *str)
// {

// }
