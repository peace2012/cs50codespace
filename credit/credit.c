#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_number_length(long number)
int first_two_digits (long number, int card_number_length)

int main(void)
{
 long card_number;
    // take input from user //



}



// function indicate if card is Visa, MCard, Amex or Invalid //
int type_of_card()
{
// starts with correct characters //
do
{
    get_card_number(card_number);
}
while (card_number !== )

// is correct length for card type //

}

// function prompts user for card number //
void get_card_number(long number)
{
number = get_long("Number: ");
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
