#include <stdio.h>
#include <stdlib.h>

void prompt(char *c) {
    while (1) {
        printf("%s", c);
    }
}

int main(void) {
   prompt(":) ");

   return EXIT_SUCCESS;
}
