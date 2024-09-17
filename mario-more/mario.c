#include <cs50.h>
#include <stdio.h>

int h;
int main(void) {

    do {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
}
