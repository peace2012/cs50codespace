#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

string get_word (string player);

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

string get_word (string player)
{
        string word = get_string("%s: ", player);
        if (word != NULL)
        {
            return word;
        }
        else
        {
            fprintf(stderr, "Please enter a word.\n");
            exit(1);
        }

}

// string is an array
// compare each letter to an array of scrabble letters and scores
// output the integer found

// int compare (char letter)
// {

// }
