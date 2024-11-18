#include <stdio.h>
#include <math.h>

float f(float x) {
    return (x * x * x) - (x * x) - 1; 
}

float g(float x) {
    return 1 / sqrt(1 + x); 
}

int main() {
    int maxIteration, i = 1;
    float x0, x1, mid, x, EPSILON;
    printf("Name: MANSI AGARWAL \nRoll No: 11 \nSection: C\n\n");
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIteration);
    printf("Enter the initial guesses x0 and x1: ");
    scanf("%f %f", &x0, &x1);
    printf("Enter tolerence value :");
    scanf("%f",&EPSILON);
    if (f(x0) * f(x1) > 0) {
        printf("Invalid interval\n");
        return 0;
    }
    mid = (x0 + x1) / 2; 
    // Perform the iteration process
    while (i <= maxIteration) {
        x = g(x0);
        if (fabs(x - x0) < EPSILON) {
            printf("Converged after %d iterations. Approximate root: %f\n", i, x);
            return 0;
        }
        printf("Iteration %d: x = %f\n", i, x);  
        x0 = x; 
        i++;  
    }
    printf("Reached maximum iterations. Approximate root: %f\n", x);
    return 0;
}
