#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    const int valid_lengths[3];
    const int amex_specs[1];
    const int mcard_specs[4];
    const int visa_specs[4];
} CardSpecs;

CardSpecs specs = {
        {13, 15, 16},
        {37},
        {22, 55, 51, 52},
        {40, 42, 41, 49}
    };

long get_card_number(long *number);

int count_number_length(long card_num);

int calculate_digits(long card_num, int num_len);

char *create_array(int array_type, long card_num, int num_len);
int *string_to_digits(char *input_array);

bool is_valid_length(int num_len);

int first_two_digits(long number, int card_number_length);
const char *type_of_card(long card_number);

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
            printf("INVALID agorithm\n");
        }
    }

    else
    {
        printf("INVALID length\n");
    }
}

int calculate_digits(long card_num, int num_len)
{

    int output = 0;

    char *first_array = create_array(2, card_num, num_len);

    if (first_array != NULL)
    {
        int first_array_length = strlen(first_array);

        int *first_integer_array = string_to_digits(first_array);

        free(first_array);

        if (first_integer_array != NULL)
        {

            for (int i = 0; i < first_array_length; i++)
            {
                if ((first_integer_array[i] * 2) < 10)
                {
                    output = output + (first_integer_array[i] * 2);
                }
                else
                {
                    output = output + ((first_integer_array[i] * 2) % 10) +
                             ((first_integer_array[i] * 2) / 10);
                }
            }
            free(first_integer_array);
        }
    }

    char *second_array = create_array(1, card_num, num_len);
    if (second_array != NULL)
    {

        int second_array_length = strlen(second_array);

        int *second_integer_array = string_to_digits(second_array);
        free(second_array);
        if (second_integer_array != NULL)
        {

            for (int i = 0; i < second_array_length; i++)
            {
                output = output + second_integer_array[i];
            }
            free(second_integer_array);
        }
    }
    return output;
}

// function prompts user for card number
long get_card_number(long *card_num)
{
    *card_num = get_long("Number: ");
    return *card_num;
}

// function to create an array using card number
char *create_array(int array_type, long card_num, int num_len)
{

    // initialise array length of card number
    char card_array[num_len + 1];

    // convert integers to string and place in array
    sprintf(card_array, "%li", card_num);

    // calculate length of new array
    int output_array_length = (strlen(card_array) / 2) + 1;

    // Allocate memory for the array
    char *output_array = malloc(output_array_length * sizeof(char));
    if (output_array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit the program
    }

    // place every other char from old array into new array
    int j = 0;
    for (int i = strlen(card_array) - array_type; i >= 0; i -= 2)
    {
        output_array[j] = card_array[i];
        j++;
    }
    // Add the null terminator
    output_array[j] = '\0';
    // You can now use new array as needed
    return output_array;
}

// function to change string to digits
int *string_to_digits(char *input_array)
{
    int array_length = strlen(input_array);
    int *output_array = malloc(array_length * sizeof(int));
    if (output_array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit the program
    }

    for (int i = 0; i < array_length; i++)
    {
        output_array[i] = input_array[i] - '0';
    }
    return output_array;
}

// count the number of digits in the card number //
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
    return first_two_digits = number / pow(10, card_number_length - 2);
}

bool is_valid_length(int num_len)
{

    const int valid_lengths_length = sizeof(valid_lengths) / sizeof(valid_lengths[0]);

    for (int i = 0; i < valid_lengths_length; i++)
    {
        if (num_len == valid_lengths[i])
        {
            return true;
        }
    }
    return false;
}

const char *type_of_card(long card_number)
{
    char output[12];

    int card_length = count_number_length(card_number);
    int card_digits = first_two_digits(card_number, card_length);

    const int amex_specs_length = sizeof(amex_specs) / sizeof(amex_specs[0]);

    for (int i = 0; i < amex_specs_length; i++)
    {
        if (card_digits == amex_specs[i])
        {
            return "AMEX";
        }
    }

    const int mcard_specs_length = sizeof(mcard_specs) / sizeof(mcard_specs[0]);

    for (int i = 0; i < mcard_specs_length; i++)
    {
        if (card_digits == mcard_specs[i])
        {
            return "MASTERCARD";
        }
    }

    const int visa_specs_length = sizeof(visa_specs) / sizeof(visa_specs[0]);

    for (int j = 0; j < visa_specs_length; j++)
    {
        if (card_digits == visa_specs[j])
        {
            return "VISA";
        }
    }

    return "INVALID card type";
}
