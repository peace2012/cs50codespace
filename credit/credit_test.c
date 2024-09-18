#include <stdio.h>
#include <string.h>

int check_algorithm(long card_num, int num_len)
{
    // initialise array length of card number
    char card_array[num_len + 1];

    // convert integers to string and place in array
    sprintf(card_array, "%li", card_num);

    // calculate length of new array
    int _1array_length = ( strlen(card_array) / 2 ) + 1;

    // initialize new array
    char first_array[_1array_length];

    // place every other char from old array into new array
    int j = 0;
    for (int i = 1; i < strlen(card_array); i += 2)
    {
    first_array[j] = card_array[i];
    j++;
    }
    // Add the null terminator
    first_array[j] = '\0';
    // You can now use first_array as needed
}
