/*Implementation of Gauss Jacobi Theorem*/
#include<stdio.h>
#include<math.h>

#define F1(x, y, z) (17-y+2*z)/20
#define F2(x, y, z) (-18-3*x+z)/20
#define F3(x, y, z) (25+2*x-3*y)/-20

void gaussJacobi(float x, float y, float z) {
    float x0, y0, z0, e1, e2, e3;
    int i = 1;
    do {
        x0 = F1(x, y, z);
        y0 = F2(x, y, z);
        z0 = F3(x, y, z);

        e1 = fabs(x - x0);
        e2 = fabs(y - y0);
        e3 = fabs(z - z0);

        printf("Iter [%d] = [x, y, z] = [%.2f, %.2f, %.2f]\n", i, x0, y0, z0);
        x = x0;
        y = x0;
        z = z0;
        ++i;

    }while(e1 > 0.0001 && e2 > 0.0001 && e3 > 0.0001);
    printf("Here the value of x, y & z are x = %.2f\n y = %.2f\n z = %.2f\n", x0, y0, z0);


}
int main() {
    float x1, y1, z1;
    printf("Enter any 3 initial guesses\n x = ");
    scanf("%f", &x1);
    printf("y = ");
    scanf("%f", &y1);
    printf("z = ");
    scanf("%f", &z1);
    if(!isnan(F1(x1, y1, z1)) && !isnan(F2(x1, y1, z1)) && !isnan(F3(x1, y1, z1))) {
        gaussJacobi(x1, y1, z1);
        printf("Gauss Jacobi Method Completed\n");
    }
    else {
        printf("Incorrect guesses!! Try again\n");
    }
    return 0;
}
