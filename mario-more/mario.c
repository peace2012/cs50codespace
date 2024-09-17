#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // initiates integer h or height of the pyramid//
    int h;

    // do while loop verifying the int is between 1 and 8//
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    /*loop repeats for height of the pyramid
    each loop will print one line of the pyramid*/
    for (int i = 0; i < h; i++)
    {

        /*loop repeats the spaces before the first # sign
        a decreasing sequence*/
        for (int j = h - i - 1; j > 0; j--)
        {
            printf(" ");
        }
        /*loop prints the required number of # in the left side of pyramid
        an increasing sequence from 0 to the height of pyramid less 1*/
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // all pyramids include the character # followed by two spaces//
        printf("#  ");

        /*loop prints the required number of # to the right side of the pyramid
        an increasing sequence as with the # on the left side*/
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }

        // all pyramids include the character # then a new line//
        printf("#\n");
    }
}
