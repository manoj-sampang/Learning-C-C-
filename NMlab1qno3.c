/* Fixed point Iteration */
#include<stdio.h>
#include<math.h>

float function(float x) {
    return sin(x) + 3 * x - 2;
}

float g(float x) {
    return (2-sin(x))/3;      // original g(x)
}

float display(float a) {
    float x0, xn;
    int i = 1;
    x0 = a;

    printf("Iter\t     x0\t\t    x(n)\n");

    do {
        xn = g(x0);
        printf("%d\t   %f\t   %f\n", i, x0, xn);

        if (fabs(xn - x0) < 0.0001)   // stopping condition
            break;

        x0 = xn;     // update x0 for next iteration
        i++;

    } while(1);

    return xn;
}

int main() {
    float x;

    printf("--- Fixed Point Iteration Method ---\n");
    printf("Enter your initial guess x0 = ");
    scanf("%f", &x);

    // ONLY checking if g(x) is defined (since you said your method is correct)
    if (!isnan(g(x)) && !isinf(g(x))) {
        float root = display(x);
        printf("\nApproximate root = %f\n", root);
    }
    else {
        printf("Invalid guess or g(x) undefined.\n");
    }

    return 0;
}
