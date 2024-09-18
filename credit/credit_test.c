#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_card_number(long *number);

int main(void)
{
    long card_number;
    get_card_number(&card_number);
}

// function prompts user for card number //
long get_card_number(long *number)
{
*number = get_long("Number: ");
return *number;
}
