#include <stdio.h>



void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Swapped values inside swapByReference: a = %d, b = %d\n", *a, *b);
}

int main() {

    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Original values: a = %d, b = %d\n", num1, num2);


    swapByReference(&num1, &num2);
    printf("After swapByReference: a = %d, b = %d\n", num1, num2);

    return 0;
}
