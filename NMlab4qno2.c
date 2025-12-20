/*Gauss Seidal Method*/
#include<stdio.h>
#include<math.h>

#define F1(x, y, z) (17-y+2*z)/20
#define F2(x, y, z) (-18-3*x+z)/20
#define F3(x, y, z) (-25-2*x+3*y)/20

void gaussSeidal(float x, float y, float z) {
    float x0, y0, z0, e1, e2, e3;
    int i = 1;
    do {
        x0 = F1(x, y, z);
        
        y0 = F2(x0, y, z);
        
        z0 = F3(x0, y0, z);
       
        printf("Iter [%d] = [x, y, z] = [%.2f, %.2f, %.2f]\n", i, x0, y0, z0);
        e1 = fabs(x - x0);
       
        e2 = fabs(y - y0);
        
         e3 = fabs(z - z0);
        z = z0;
         x = x0;
         y = y0;

        
    }while(e1 > 0.0001|| e2 > 0.0001 || e3 > 0.0001);
    printf("Hence, [x, y, z] = [%.2f, %.2f, %.2f]\n", x0, y0, z0);
}
int main() {
    float x, y, z;
    printf("Enter initial guesses x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    printf("z = ");
    scanf("%f", &z);
    if(!isnan(F1(x, y, z)) && !isnan(F2(x, y, z)) && !isnan(F3(x, y, z))){
        gaussSeidal(x, y, z);
        printf("Gauss Seidal Method Completed!!\n");
    }
    else {
        printf("Invalid Guesses!!! Try again\n");
    }
    return 0;
}