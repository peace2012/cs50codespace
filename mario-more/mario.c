#include <cs50.h>
#include <stdio.h>

int main(void) {

//initiates integer h or height of the pyramid//
    int h;

//do while loop verifying the int is between 1 and 8//
    do {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

/*loop repeats for height of the pyramid
each loop will print one line of the pyramid*/
    for (int i = 0; i < h; i++) {

/*loop repeats the spaces before the first # sign

        for (int j = h-i-1; j > 0; j--) {
            printf(" ");
        }

        for (int k = 0; k < i; k++) {
            printf("#");
        }

        printf("#  ");

        for (int l = 0; l < i; l++) {
            printf("#");
        }

        printf("#\n");

    }
}
