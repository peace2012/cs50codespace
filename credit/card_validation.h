#ifndef CARD_VALIDATION_H
#define CARD_VALIDATION_H

#include <stdbool.h>

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

#endif
