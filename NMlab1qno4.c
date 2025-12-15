#include <stdio.h>
#include <math.h>

float function(float x) {
    return x * log10(x) - 1.2;
}

float f_derivative(float x) {
    return log10(x) + 1 / log(10);
}

float newtonRaphson(float x) {
    float xn;
    int i = 1;

    do {
        xn = x - function(x) / f_derivative(x);
        printf("Iter %d: x = %f\n", i, xn);

        if (fabs(xn - x) < 0.0001)
            break;

        x = xn;
        i++;

    } while (1);

    return xn;
}

int main() {
    float x, root;

    printf("Enter the initial guess x0: ");
    scanf("%f", &x);

    if (x > 0 && !isnan(function(x)) && !isinf(f_derivative(x))) {
        root = newtonRaphson(x);
        printf("\nRoot = %.4f\n", root);
    } else {
        printf("Invalid Guess!!!\n");
    }

    return 0;
}
