/*#include <stdio.h>

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
}*/
/*using recursion*/
#include<stdio.h>

int get_n(int n) {
    return n;
}
int nth = 1;
void fibonacci(int a, int b, int n, int fixed) {
    int next;
    if(n < fixed - 1 && n != 0) {
        next = a + b;
        a = b;
        b = next;
        n--;
        printf("%d\t ", next);
    }
    else {
        printf("%d\t %d\t ", a, b);
        n--;
        n--;
    }
    if(n != 0) {
    fibonacci(a, b, n, fixed);
    }
    else {
        printf("\n");
    }
}

int nth_fibonacci(int term) {
    int a = 0;
    int b = 1;
    next = a+b;
    for(int i = 0; i < term-2; ++i) {
        next = a+b;
        a = b;
        b = next;
    }
    return next;
}

int main() {
    int num, term;
    printf("Fibonacci using Recursion\n");
    printf("Enter no. of terms for the Fibonacci series(Integers): ");
    scanf("%d", &num);
    if(num > 0) {
        fibonacci(0, 1, num, num);
    }
    printf("Completion of the fibonacci Series till '%d' Term(s)\n", num);
    printf(" === Find nth fibonacci Term === \n");
    printf("Enter the term you want to display: ");
    scanf("%d", &term);
    if(!term || term > 0) {
        
    }
    return 0;

}