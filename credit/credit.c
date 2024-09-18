#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

long get_card_number(long *number);

void check_algorithm(long card_num, int num_len);

int count_number_length(long card_num);
int first_two_digits (long number, int card_number_length);
int type_of_card(long card_number);


int main(void)
{
    long card_number = get_card_number(&card_number);

    int card_number_length = count_number_length(card_number);

     check_algorithm(card_number, card_number_length);

    // check card type using length and first two digits //

    // int card_type_code = type_of_card(card_number);
    // printf("%i\n",card_type_code);


// if type of card and algorithm are the same return value//
// if they are different return invalid //


}

// function prompts user for card number
long get_card_number(long *card_num)
{
*card_num = get_long("Number: ");
return *card_num;
}

// algorithm //

// function to take every other digit and multiply by 2 //

void check_algorithm(long card_num, int num_len)
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
    printf("%s\n", first_array);
}

// count the number of digits in the cart number //
int count_number_length(long card_num)
{
    int card_number_length = 0;
    while (card_num > 0)
    {
        card_num = card_num / 10;
        card_number_length++;
    }
return card_number_length;
}

// isolate first two digits of the card number //
int first_two_digits(long number, int card_number_length)
{
    int first_two_digits;
    return first_two_digits = number / pow(10, card_number_length-2);
}

int type_of_card(long card_number)
{
int card_length = count_number_length(card_number);
int two_digits = first_two_digits(card_number, card_length);

if ( card_length == 15 && two_digits == 37 )
{
    return 1;
}
else if ( card_length == 16 )
{
    switch(two_digits)
    {
        case 22:
        case 55:
        case 51:
        case 52:
        return 2;
        break;
        case 41:
        case 40:
        case 49:
        return 3;
        break;
        default:
        return 4;
    }
} else return 4;
}
