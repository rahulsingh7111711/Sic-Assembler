#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - 4 * x - 9;
}

void regula_falsi(double a, double b, double tolerance, int max_iterations) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. No root or multiple roots in the given interval.\n");
        return;
    }

    double c = a; 
    int iteration = 0;

    printf("Iteration\t x0\t\t x1\t\t x2\n");
    printf("-----------------------------------------------------------------\n");

    while (iteration < max_iterations) {
        c = ((a*f(b)) - (b*f(a))) / (f(b) - f(a));

        printf("%d\t\t %.5f\t %.5f\t %.5f\n", iteration + 1, a, b, c);

        if (fabs(f(c)) < tolerance) {
            break;
        }

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    printf("-----------------------------------------------------------------\n");
    printf("The approximate root is = %.5f\n", c);
}

int main() {
    double a, b, tolerance;
    int max_iterations;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the first initial guess (x0): ");
    scanf("%lf", &a);
    printf("Enter the second initial guess (x1): ");
    scanf("%lf", &b);
    printf("Enter the tolerance value: ");
    scanf("%lf", &tolerance);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    regula_falsi(a, b, tolerance, max_iterations);

    return 0;
}
