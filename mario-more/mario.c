#include <cs50.h>
#include <stdio.h>

void print_hashes(int n);
void print_pyramid(int i, int height);

const int MIN_HEIGHT = 1;
const int MAX_HEIGHT = 8;

int main(void)
{
    // check height is between 1 and 8 //
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < MIN_HEIGHT || height > MAX_HEIGHT);

    // loop prints each line of pyramid //
    for (int i = 0; i < height; i++)
    {

        print_pyramid(i, height);
    }
}

// function to loop through printing required # //
void print_hashes(int n)
{
    for (int hash = 0; hash < n; hash++)
    {
        printf("#");
    }
}

// function to print pyramid //
void print_pyramid(int i, int height)
{
    // loop prints spaces before # //
    for (int space = height - i - 1; space > 0; space--)
    {
        printf(" ");
    }
    print_hashes(i);

    // all pyramids include # then two spaces//
    printf("#  ");
    print_hashes(i);

    // all include # then new line//
    printf("#\n");
}
