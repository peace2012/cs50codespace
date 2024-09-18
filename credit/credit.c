#include <cs50.h>
#include <stdio.h>

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
void get_card_number(number)
{
number = get_long("Number: ");
}

// isolate first two digits of the card number //
int first_two_digits (long number, int card_number_length)
{
    return int first_two digits = number / ((card_number_length-2)*10);
}

// count the number of digits in the cart number //
int count_number_length(long number)
{
    // initialize counter to 0 //
    int card_number_length = 0;

    // loop to divide number by 10 until 0 //
    while (number > 0)
    {
        number = number / 10;
        // increment the county in each iteraction //
        card_number_length++;
    }
return card_number_length
}
