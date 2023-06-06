#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float discriminant, realPart, imaginaryPart;

    printf("Enter the values of a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        float sqrt_discriminant = sqrt(discriminant);
        float denominator = 2 * a;

        // Calculate real roots
        float root1 = (-b + sqrt_discriminant) / denominator;
        float root2 = (-b - sqrt_discriminant) / denominator;

        printf("Real roots:\n");
        printf("Root 1: %.2f\n", root1);
        printf("Root 2: %.2f\n", root2);
    } else {
        // Calculate imaginary roots
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);

        printf("Roots are imaginary:\n");
        printf("Root 1: %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("Root 2: %.2f - %.2fi\n", realPart, imaginaryPart);
    }

    return 0;
}
