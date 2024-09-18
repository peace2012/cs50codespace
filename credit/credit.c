#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_number_length(long number)
int first_two_digits (long number, int card_number_length)

int main(void)
{
 long card_number;
    // take input from user //
    get_card_number(&card_number);


// if type of card and algorithm are the same return value//
// if they are different return invalid //


}



// function to indicate if card is Visa, MCard, Amex or Invalid //
string type_of_card(long card_number)
{

switch

}

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
