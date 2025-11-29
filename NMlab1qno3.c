/*Fixed point Iteration*/
#include<stdio.h>
#include<math.h>

float function(float x) {
    return exp(x) - x;
}
float g(float x) {
    return exp(x);
}

float display(float a) {
    float x0, xn;
    int i = 1;
    x0 = a;
    printf("Iter\t x0\t x(n)\n");
    
    do {
        xn = g(x0);
        if(fabs(x0 - xn) > 0.0001) {
            printf("%d\t %f\t %f\n", i, x0, xn);
            return xn;
        }
        else {
            x0 = xn;
            printf("%d\t %f\t %f\n", i, x0, xn);
        }
    }while(fabs(x0 - xn) > 0.0001);
    
}

int main() {
    float x;
    printf("--- Fixed Point Iteration Method ---\n");
    printf("Enter your initial guess x0 = ");
    scanf("%f", &x);
    
    return 0;
}

 