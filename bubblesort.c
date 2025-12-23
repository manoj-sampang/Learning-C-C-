#include<stdio.h>
#include<stdlib.h>

void bubbleSort(float *a, int n) {
    //ascending order
    for(int i = 0; i < n/2; ++i) {
        if(*(a+i) > (*a+i+1)) {
            float temp;
            temp = *(a+i);
            *(a+i) = *(a+i+1);
            *(a+i+1) = temp;
        }
    }
}

void display(float *a, int n) {
    printf("Displaying the Arrays\n");
    for (int i = 0; i < n; ++i) {
        printf("%f\t ", *(a+i));
    }
    printf("\n");
}

int main() {
    float *arr;
    int n;
    printf("Give the no. of array you want to insert = ");
    scanf("%d", &n);
    arr = (float*)malloc(n*sizeof(float));
    for(int i = 0; i < n; ++i) {
        printf("Arr[%d] = ", i+1);
        scanf("%f", &arr[i]);
    }
    
    printf("Input completed\n");
    printf("--- Before Sorting ---\n");
    display(arr, n);
    printf("=== Ascending order ===\n");
    if(n > 0 && !n) {
        bubbleSort(arr, n);
    }
    printf("--- After Sorting ---\n");
    display(arr, n);
    free(arr);
    return 0;
}