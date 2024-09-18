#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_card_number(long *number);
int count_number_length(long number);
int first_two_digits (long number, int card_number_length);
int type_of_card(long card_number);

int main(void)
{
    long card_number;

    // take input from user //
    get_card_number(&card_number);

    // check card type using length and first two digits //
    int card_type_code = type_of_card(card_number);
    printf("%i",card_type_code);







// if type of card and algorithm are the same return value//
// if they are different return invalid //


}



// function to indicate if card is Visa, MCard, Amex or Invalid //


// function prompts user for card number //
long get_card_number(long *number)
{
*number = get_long("Number: ");
return *number;
}

// count the number of digits in the cart number //
int count_number_length(long number)
{
    int card_number_length = 0;
    while (number > 0)
    {
        number = number / 10;
        card_number_length++;
    }
return card_number_length
}

// isolate first two digits of the card number //
int first_two_digits (long number, int card_number_length)
{
    int first_two_digits;
    return first_two_digits = number / pow(10, card_number_length-2);
}

int type_of_card(long card_number)
{
int card_length = count_number_length(card_number);
int first_two_digits = first_two_digits(card_number, card_length);

if ( card_length == 15 && first_two_digits == 37 )
{
    return 1;
}
else if ( card_length == 16 )
{
    switch(first_two_digits)
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
