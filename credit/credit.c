#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long get_card_number(long *number);

char* create_array(int array_type,long card_num, int num_len);
int* string_to_digits(char input_array);

int count_number_length(long card_num);
int first_two_digits (long number, int card_number_length);
int type_of_card(long card_number);


int main(void)
{
    long card_number = get_card_number(&card_number);

    int card_number_length = count_number_length(card_number);

    char *first_array = create_array(0, card_number, card_number_length);
    int *first_integer_array = string_to_digits(*first_array);
    if (first_integer_array !=NULL)
    {
        free(first_array);

        for (int i = 0; i < array_length; i++)
            {
                first_integer_array[i] = first_integer_array[i] * 2;
            }


         free(first_integer_array);
    }

    // take each digit in the array, multiply by 2 and put it back in the array

    // extract it again and then add all numbers in the array

    char *second_array = create_array(1, card_number, card_number_length);
    if (second_array !=NULL)
    {
        printf("%s\n", second_array);
        free(second_array);
    }

    // extract each digit in the array
    // add them together with the total from the first array


}

// function prompts user for card number
long get_card_number(long *card_num)
{
*card_num = get_long("Number: ");
return *card_num;
}

// algorithm //

// function to take every other digit and multiply by 2

// function to create an array using card number
char* create_array(int array_type,long card_num, int num_len)
{

    // initialise array length of card number
    char card_array[num_len + 1];

    // convert integers to string and place in array
    sprintf(card_array, "%li", card_num);

    // calculate length of new array
    int output_array_length = ( strlen(card_array) / 2 ) + 1;

        // Allocate memory for the array
    char *output_array = malloc(output_array_length * sizeof(char));
    if (output_array == NULL)
    {
        // Handle memory allocation failure
        return NULL;
    }

    // place every other char from old array into new array
    int j = 0;
    for (int i = array_type; i < strlen(card_array); i += 2)
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
int* string_to_digits(char *input_array)
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




    // // Define arrays
    // char first_array[new_array_length];
    // char second_array[new_array_length];
    // char *ARRAY_NAME;

    // // Choose array based on array_type
    // switch (array_type) {
    //     case 0:
    //         ARRAY_NAME = first_array;
    //         break;
    //     case 1:
    //         ARRAY_NAME = second_array;
    //         break;
    // }
