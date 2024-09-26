#include <stdio.h>
#include <cs50.h>

string get_word (int number);

// variable for number of players
const int N = 2;

int main (void)
{
    for (int i = 0; i < N; i++)
    {
        const get_word(i+=);
    }
}

// function uses variable number of players
// runs a loop to request input word, outputs string

string get_word (int number)
{
        string word = get_string("Player %i:", number++);
        return word;
}

// string is an array
// compare each letter to an array of scrabble letters and scores
// output the integer found

int compare (char letter)
{

}
