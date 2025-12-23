#include<stdio.h>
#include<stdlib.h>

/*void bubbleSort(float *a, int n) {
    for(int i = 0; i < n - 1; i++) {
       for(int j = 0; j < n - i - 1; ++j)
            if(*(a + j) > *(a + j + 1)) {
                float temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
}*/

void selectionSort(float *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(*(a + i) > *(a + j)) {
                float temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            
            }
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
    if(arr == NULL) {
        printf("Memory allocation failed \n");
        return 1;
    }
    if(n == 1 || n < 0) {
        printf("Given no. of input cannot be sorted\n");
        exit(1);
    }
    for(int i = 0; i < n; ++i) {
        printf("Arr[%d] = ", i+1);
        scanf("%f", &arr[i]);
    }
    
    printf("Input completed\n");
    printf("--- Before Sorting ---\n");
    display(arr, n);
    if(n > 1) {
        selectionSort(arr, n);
    }
    printf("--- After Sorting ---\n");
    printf("=== Ascending order ===\n");
    display(arr, n);
    free(arr);
    return 0;
}