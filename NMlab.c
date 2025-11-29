//prgram to implement Bisection method
#include<stdio.h>
#include<math.h>
float function(float x) {
    return cos(x) - x * exp(x);
}
float calculateBisection(float n1, float n2) {
    float c;
    int i = 1;
    printf("Iter\t a\t b\t c\t f(c)\t\t New Interval \n");
    do {
        c = (n1 + n2)/2;
        if (function(n1)*function(c) < 0.0) {
            n2 = c;
            printf("%d\t %f\t %f\t %f\t %f\t\t [%.2f, %.2f]\n", i, n1, n2, c, function(c), n1, c);
        }
        else {
            n1 = c;
            printf("%d\t %f\t %f\t %f\t %f\t\t [%.2f, %.2f]\n", i, n1, n2, c, function(c), c, n2);
        }
    ++i;
    }while(fabs(n2-n1) > 0.0001);
    return c;
}

int main() {
    float x1, x2, root;
    printf("Enter the two guesses for the equation\n");
    printf("X1 = ");
    scanf("%f", &x1);
    printf("X2 = ");
    scanf("%f", &x2);
    printf("Checking Validity of the Points...\n");
    if(function(x1)*function(x2) < 0.0) {
        printf("Correct points Bisection method can be proceeded\n");
        root = calculateBisection(x1, x2);
        printf("Root of function:%.4f", root);
    }
    else {
        printf("Incorrect Points for Bisection method hence exiting...");
    }

    return 0;
}