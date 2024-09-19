#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long get_card_number(long *number);

int count_number_length(long card_num);

int calculate_digits(long card_num, int num_len);

char *create_array(int array_type, long card_num, int num_len);
int *string_to_digits(char *input_array);

int first_two_digits(long number, int card_number_length);
char type_of_card(long card_number);

// char card_type[12];

int main(void)
{

    long card_number = get_card_number(&card_number);

    int card_number_length = count_number_length(card_number);

    if (card_number_length == 15 || card_number_length == 16)
    {

        int sum_of_digits = calculate_digits(card_number, card_number_length);

        if (sum_of_digits % 10 == 0)
        {
            char card_type[12];
            strcpy(card_type, type_of_card(card_number));
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

int calculate_digits(long card_num, int num_len)
{
    int total;

    char *first_array = create_array(2, card_num, num_len);

    if (first_array != NULL)
    {
        int first_array_length = strlen(first_array);

        int *first_integer_array = string_to_digits(first_array);

        if (first_integer_array != NULL)
        {
            free(first_array);

            for (int i = 0; i < first_array_length; i++)
            {
                if ((first_integer_array[i] * 2) < 10)
                {
                    total = total + (first_integer_array[i] * 2);
                }
                else
                {
                    total = total + ((first_integer_array[i] * 2) % 10) +
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

        if (second_integer_array != NULL)
        {
            free(second_array);

            for (int i = 0; i < second_array_length; i++)
            {
                total = total + second_integer_array[i];
            }
            free(second_integer_array);
        }
    }
    return total;
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
        // Handle memory allocation failure
        return NULL;
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
        // Handle memory allocation failure
        return NULL;
    }

    for (int i = 0; i < array_length; i++)
    {
        output_array[i] = input_array[i] - '0';
    }
    return output_array;
}

// function to multiply each digit by 2

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
    return first_two_digits = number / pow(10, card_number_length - 2);
}

char type_of_card(long card_number)
{
    char output[12];

    int card_length = count_number_length(card_number);
    int two_digits = first_two_digits(card_number, card_length);

    if (card_length == 15 && two_digits == 37)
    {
        strcpy(output, "AMEX");
    }
    else if (card_length == 16)
    {

        switch (two_digits)
        {
            case 22:
            case 55:
            case 51:
            case 52:
                strcpy(output, "MASTERCARD");
                break;
            case 41:
            case 40:
            case 49:
                strcpy(output, "VISA");
                break;
            default:
                strcpy(output, "INVALID");
        }
    }
    else
        strcpy(output, "INVALID");
    return output;
}
