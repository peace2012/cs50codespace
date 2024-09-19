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

// valid card specifications according to structure
CardSpecs specs = {{13, 15, 16}, {37}, {22, 55, 51, 52}, {40, 42, 41, 49}};

long get_card_number(long *number);
int count_number_length(long card_num);
int calculate_digits(long card_num, int num_len);
char *create_array(int array_type, long card_num, int num_len);
int *string_to_digits(const char *input_array);
bool is_valid_length(int num_len);
int first_two_digits(long number, int card_number_length);
const char *type_of_card(long card_number);
bool check_card_type(int two_digits, const int *specs_array, int array_length);
int process_array(const char *array, bool double_values);

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

int calculate_digits(long card_num, int num_len)
{

    char *first_array = create_array(2, card_num, num_len);

    int first_total = process_array(first_array, true);
    free(first_array);

    char *second_array = create_array(1, card_num, num_len);

    int second_total = process_array(second_array, false);
    free(second_array);

    return first_total + second_total;
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
int *string_to_digits(const char *input_array)
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

    const int valid_lengths_length = sizeof(specs.valid_lengths) / sizeof(specs.valid_lengths[0]);

    for (int i = 0; i < valid_lengths_length; i++)
    {
        if (num_len == specs.valid_lengths[i])
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

    typedef struct {
    const char *name;
    const int *specs;
    int specs_length;
} CardType;

CardType card_types[] = {
    {"AMEX", specs.amex_specs, sizeof(specs.amex_specs) / sizeof(specs.amex_specs[0])},
    {"MASTERCARD", specs.mcard_specs, sizeof(specs.mcard_specs) / sizeof(specs.mcard_specs[0])},
    {"VISA", specs.visa_specs, sizeof(specs.visa_specs) / sizeof(specs.visa_specs[0])}
};

for (int i = 0; i < sizeof(card_types) / sizeof(card_types[0]); i++)
{
    if (check_card_type(card_digits, card_types[i].specs, card_types[i].specs_length))
    {
        return card_types[i].name;
    }
}

return "INVALID";
}

bool check_card_type(int two_digits, const int *specs_array, int array_length)
{
    for (int i = 0; i < array_length; i++)
    {
        if (two_digits == specs_array[i])
        {
            return true;
        }
    }
    return false;
}

int process_array(const char *array, bool double_values)
{
    if (array == NULL)
    {
        return 0;
    }

    int length = strlen(array);
    int *integer_array = string_to_digits(array);
    int output = 0;

    if (integer_array != NULL)
    {
        for (int i = 0; i < length; i++)
        {
            int value = integer_array[i];
            if (double_values)
            {
                value *= 2;
                if (value >= 10)
                {
                    value = (value % 10) + (value / 10);
                }
            }
            output += value;
        }
        free(integer_array);
    }

    return output;
}
