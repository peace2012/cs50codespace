#include <stdio.h>
#include <string.h>

int main(void) {
    char result[100] = ""; // Ensure the array is large enough to hold the final string
    char digit[2]; // Temporary string to hold each digit

    // Example digits to concatenate
    for (int i = 1; i <= 3; i++) {
        sprintf(digit, "%i", i); // Convert digit to string
        strcat(result, digit); // Concatenate to result
    }

    printf("Result: %s\n", result);
    return 0;
}
