#include <stdio.h>

void fibonacci(int n) {
    int first = 0, second = 1, next;
    printf("Fibonacci Series up to %d terms:\n", n);
    for(int i = 0; i < n; ++i) {
        if(i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d \t", next);  
    }
}
int main() {
    int num;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &num);
    if(num <=0 || !num) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    fibonacci(num);
    return 0;
}
