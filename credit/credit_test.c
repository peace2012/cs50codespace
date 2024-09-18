#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int number = 123456;
    int digit = (number / 10000) % 10;
    printf("%i\n", digit);
}
