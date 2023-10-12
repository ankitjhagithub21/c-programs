#include <stdio.h>


void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Swapped values inside swapByValue: a = %d, b = %d\n", a, b);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Original values: a = %d, b = %d\n", num1, num2);

    // Swap by value (passing copies of the values)
    swapByValue(num1, num2);
    printf("After swapByValue: a = %d, b = %d\n", num1, num2);

    return 0;
}
