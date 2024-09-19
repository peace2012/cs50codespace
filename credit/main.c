// credit.c
#include <stdio.h>
#include <stdbool.h>
#include "card_validation.h"
#include "card_specs.h"

int main(void)
{

    long card_number = get_card_number(&card_number);

    int card_length = count_number_length(card_number);

    bool is_valid = is_valid_length(card_length);

    if (is_valid == true)
    {
        int sum_of_digits = calculate_digits(card_number, card_length);

        if (sum_of_digits % 10 == 0)
        {
            const char *card_type = type_of_card(card_number);
            printf("%s\n", card_type);
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}
