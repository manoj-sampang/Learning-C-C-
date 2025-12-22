#include <stdio.h>
#include <ctype.h>

#define MAX 100

char opStack[MAX];
int topOp = -1;

int valStack[MAX];
int topVal = -1;

int values[52] = {0};
int used[52] = {0};

void pushOp(char ch) { opStack[++topOp] = ch; }
char popOp() { return opStack[topOp--]; }

void pushVal(int x) { valStack[++topVal] = x; }
int popVal() { return valStack[topVal--]; }

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

int varIndex(char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 'a';
    if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
    return -1;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    /* Infix → Postfix */
    while ((ch = infix[i++]) != '\0') {

        if (isalpha(ch)) {
            postfix[k++] = ch;
            used[varIndex(ch)] = 1;
        }

        else if (ch == '(')
            pushOp(ch);

        else if (ch == ')') {
            while (opStack[topOp] != '(')
                postfix[k++] = popOp();
            popOp();
        }

        else {
            while (topOp != -1 &&
                   precedence(opStack[topOp]) >= precedence(ch))
                postfix[k++] = popOp();
            pushOp(ch);
        }
    }

    while (topOp != -1)
        postfix[k++] = popOp();

    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    /* Input values */
    for (i = 0; i < 52; i++) {
        if (used[i]) {
            char v = (i < 26) ? i + 'a' : i - 26 + 'A';
            printf("Enter value of %c: ", v);
            scanf("%d", &values[i]);
        }
    }

    /* Evaluate Postfix */
    i = 0;
    while ((ch = postfix[i++]) != '\0') {

        if (isalpha(ch))
            pushVal(values[varIndex(ch)]);
        else {
            int b = popVal();
            int a = popVal();

            switch (ch) {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
            }
        }
    }

    printf("Final Result = %d\n", popVal());
    return 0;
}
