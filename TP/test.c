#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("%c\n", ('A' + 'B' - (2 * '@')) % 26 + '@');
    return 0;
}