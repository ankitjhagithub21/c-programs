#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    double discriminant, root1, root2;

    printf("Enter the coefficients of the quadratic equation (a, b, and c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    // Check if the discriminant is positive, zero, or negative
    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two real and distinct roots: root1 = %.2lf and root2 = %.2lf\n", root1, root2);
    }
    else if (discriminant == 0)
    {
        root1 = -b / (2 * a);
        printf("One real root: root = %.2lf\n", root1);
    }
    else
    {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Complex roots: root1 = %.2lf + %.2lfi and root2 = %.2lf - %.2lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}
