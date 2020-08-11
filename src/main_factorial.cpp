#include <stdio.h>
#include "Factorial.h"

int main() {
    printf("Factorial example:\n");
    int res = Factorial(0);
    printf("Factorial(0) = %d\n", Factorial(0));
    printf("Factorial(1) = %d\n", Factorial(1));
    printf("Factorial(2) = %d\n", Factorial(2));
    printf("Factorial(3) = %d\n", Factorial(3));
    printf("Factorial(4) = %d\n", Factorial(4));
    return 0;
}
