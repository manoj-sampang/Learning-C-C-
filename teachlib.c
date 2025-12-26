#include <stdio.h>

void fibonacci(int n) {
    int a = 0;
    int b = 1;
    int next;
    printf("%d\t %d\t ",a, b);
    for(int i = 0; i < n - 2; ++ i) {
        next = a + b;
        a = b;
        b = next;
        printf("%d\t ", next);
    }
}