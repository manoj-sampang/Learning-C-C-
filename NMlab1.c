/*code to implement false position method*/
/*#include <stdio.h>
#include <math.h>

float function(float x) {
    return pow(x, 3) - x - 1;
}

void display(float a, float b) {
    float c;
    int i = 1;

    printf("Iter\t a\t\t b\t\t c\t\t f(c)\t\t New Interval\n");

    do {
        c = ((a * function(b)) - (b * function(a))) / (function(b) - function(a));

        if (function(c) * function(a) < 0.0) {
            printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\t [%.6f, %.6f]\n",
                i, a, b, c, function(c), a, c);
            b = c;
        }
        else {
            printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\t [%.6f, %.6f]\n",
                i, a, b, c, function(c), c, b);
            a = c;
        }

        i++;
    } while (fabs(a - b) > 0.0001);
}

float calculateFalsePosition(float a, float b) {
    float c;

    do {
        c = ((b * function(a)) - (a * function(b))) / (function(a) - function(b));

        if (function(c) * function(a) < 0.0) {
            b = c;
        } else {
            a = c;
        }
    } while (fabs(a - b) > 0.0001);

    return c;
}

int main() {
    float a, b, root;

    printf("--- False Position Method ---\n");
    printf("Enter two guesses for the equation\n");
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);

    if (function(a) * function(b) < 0.0) {
        display(a, b);
        root = calculateFalsePosition(a, b);
        printf("\nRoot = %.6f\n", root);
    }
    else {
        printf("Invalid guesses! Try again.\n");
    }

    return 0;
}
*/
#include<stdio.h>
#include<math.h>
double f(double x) {
    return pow(x, 3) - x - 1;
}
double false_position(double a, double b, double tol, int max_iter) {
// Implement the false position method to find the root of the function
    double fa = f(a);
    double fb = f(b);
    double c, fc;
    int iter = 0;
    printf("Iteration\t a\t\t b\t\t c\t\t f(c)\t\t New Interval\n");
        do {
            c= (a*fb-b*fa)/(fb-fa);
            fc = f(c);
            if (fc*fa>0)
            {
                a=c;
                fa=fc;
                printf("%d\t\t %f\t %f\t %f\t %f\t [%.2f, %.2f]\n"
                , iter, a, b, c, fc, a, c);
            }
            else{
                b=c;
                fb=fc;
                printf("%d\t\t %f\t %f\t %f\t %f\t [%.2f, %.2f]\n"
            , iter, a, b, c, fc, c, b);
            }
            iter++;
        } while (fabs(fc) > tol && iter < max_iter);
    return c;
}
int main() {
// Example usage
    double x,y;
    printf("enter the initial guess x: \n");
    scanf("%lf",&x);
    printf("enter the initia guess y: \n");
    scanf("%lf",&y);
if (f(x)*f(y)<0)
{
    double root = false_position(x, y, 0.0001, 100);
    printf("The root is: %f\n"
    , root);
}
else{
    printf("wrong guess try again");
}
    return 0;
}