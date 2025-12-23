#include<stdio.h>

void bubbleSort(float *a, int n) {
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(*(a + j) > *(a + j + 1)) {
                float temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }
}
void selectionSort(float *a, int n) {
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(*(a + i) > *(a + j)) {
                float temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}
void display(float *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%f\t ", *(a + i));
    }
    printf("\n");
}