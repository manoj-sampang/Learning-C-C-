/*Dynamic Memory Allocation using malloc, calloc, and realloc*/
/*#include<stdio.h>
#include<stdlib.h>

void display(float *p, int n) {
    int i;
    printf("--- Dispalying the inserted data ---\n");
    for(i = 0; i < n; ++i) {
        printf("A[%d] = %.2f\n", i+1, *(p+i));
    }
}

float input(int i) {
    float r;
    printf("A[%d] = ", i+1);
    scanf("%f", &r);
    return r;
}
void useMalloc(int n, int choice) {
    if(choice == 3) {
        printf("Firstly allocating memory using malloc so, we can reallocate it afterwards\n");
    }
    float *dptr;
    int i;
    dptr = (float*)malloc(n * sizeof(float));
    for(i = 0; i < n; ++i) {
        dptr[i] = input(i);
    }
    display(dptr, n);
    if(choice == 3) {
        printf("Again, New allocation (Reallocation) \n");
        printf("Enter new size of memory to be allocated = ");
        scanf("%d", &n);
        float *rptr;
        rptr = (float*)realloc(dptr, n * sizeof(float));
        for(i = 0; i < n; ++i) {
            rptr[i] = input(i);
        }
        display(rptr, n);
        free(rptr);
    }
    
    free(dptr);
} 
void useCalloc(int n) {
    int i;
    float *dptr;
    dptr = (float*)calloc(n, sizeof(float));
    for(i = 0; i < n; ++i) {
        dptr[i] = input(i);
    }
    display(dptr, n);
    free(dptr);
}


int main() {
    int n, choose;
    
    do {
        printf("1. Memory allocation using Malloc\n");
        printf("2. Memory allocation using Calloc\n");
        printf("3. Memory reallocation using Realloc\n");
        printf("4. Exit\n");
        scanf("%d", &choose);
        printf("Enter the size of memory allocation = ");
        scanf("%d", &n);
        switch(choose) {
            case 1: 
                printf("=== USING MALLOC FUNCTION ===\n");
                useMalloc(n, choose);
                break;
            case 2:
                printf("=== USING CALLOC FUNCTION ===\n");
                useCalloc(n);
                break;
            case 3:
                printf("=== USING REALLOC FUNCTION ===\n");
                useMalloc(n, choose);
                break;
            case 4: 
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid Input!! Please try again!\n");
        }

    }while(1);
    
}*/
/* Dynamic Memory Allocation using malloc, calloc, and realloc */

#include <stdio.h>
#include <stdlib.h>   

void display(float *p, int n) {
    int i;
    float avg, sum = 0;

    printf("--- Displaying the inserted data with it's sum and average---\n");
    for(i = 0; i < n; ++i) {
        printf("A[%d] = %.2f\n", i+1, *(p+i));
        sum += *(p+i);
    }
    avg = sum/n;
    printf("Sum: %.2f\n", sum);
    printf("Average: %.2f\n", avg);
}

float input(int i) {
    float r;
    printf("A[%d] = ", i+1);
    scanf("%f", &r);
    return r;
}

void useMalloc(int n, int choice) {
    if(choice == 3) {
        printf("Firstly allocating memory using malloc, so we can reallocate it afterwards\n");
    }

    float *dptr;
    int i;

    dptr = (float*) malloc(n * sizeof(float));

    for(i = 0; i < n; ++i) {
        dptr[i] = input(i);
    }

    display(dptr, n);

    if(choice == 3) {
        printf("Again, New allocation (Reallocation) \n");
        printf("Enter new size of memory to be allocated = ");
        scanf("%d", &n);

        float *rptr;
        rptr = (float*) realloc(dptr, n * sizeof(float));

        for(i = 0; i < n; ++i) {
            rptr[i] = input(i);
        }

        display(rptr, n);
        free(rptr);
        return;
    }

    free(dptr);
}

void useCalloc(int n) {
    int i;
    float *dptr;

    dptr = (float*) calloc(n, sizeof(float));

    for(i = 0; i < n; ++i) {
        dptr[i] = input(i);
    }

    display(dptr, n);
    free(dptr);
}

int main() {
    int n, choose;

    do {
        printf("=== Also calculates Sum and Average ===\n");
        printf("1. Memory allocation using Malloc\n");
        printf("2. Memory allocation using Calloc\n");
        printf("3. Memory reallocation using Realloc\n");
        printf("4. Exit\n");

        scanf("%d", &choose);

        if(choose == 4) {
            printf("Exiting...");
            return 0;
        }

        printf("Enter the size of memory allocation = ");
        scanf("%d", &n);

        switch(choose) {
            case 1:
                printf("=== USING MALLOC FUNCTION ===\n");
                useMalloc(n, choose);
                break;

            case 2:
                printf("=== USING CALLOC FUNCTION ===\n");
                useCalloc(n);
                break;

            case 3:
                printf("=== USING REALLOC FUNCTION ===\n");
                useMalloc(n, choose);
                break;

            default:
                printf("Invalid Input!! Please try again!\n");
        }

    } while(1);

    return 0;
}
