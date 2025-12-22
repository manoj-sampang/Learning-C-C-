#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Stack operations */
void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

        // If '(' push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If ')', pop until '('
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }

        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
