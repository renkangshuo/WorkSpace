#include <stdio.h>

int main() {
    int i = 10;

    switch (i) {
        case 10 : printf("10\n");
                  break;
        case 1 : printf("  \n");
                 break;
         default:
                 printf("break default\n");
                 break;
    }
}
