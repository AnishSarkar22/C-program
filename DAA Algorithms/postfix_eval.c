#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 50 /* for the max size of the stack */
#define POSTFIXSIZE 50 /* define the max number of characters in the postfix expression */

int stack[MAXSTACK];
int top = -1;

/* define push operation */
void push(int item) {
    if (top >= MAXSTACK - 1) {
        printf("stack overflow\n");
        return;
    } else {
        top = top + 1;
        stack[top] = item;
    }
}

/* define pop operation */
int pop() {
    int item;
    if (top < 0) {
        printf("stack underflow\n");
        return -1; // Return a default value to indicate an error
    } else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

/* define a function that is used to input the postfix expression and evaluate it */
void EvalPostfix(char postfix[]) {
    int i = 0;
    char ch;
    int val;
    int A, B;

    /* evaluate the postfix expression */
    while ((ch = postfix[i]) != '\0') {
        if (isdigit(ch)) {
            /* we saw an operand, push the digit onto the stack (ch - '0' is used to get the digit) */
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            /* we saw an operator, pop the top element A and the next-to-top element B from the stack and compute B operator A */
            A = pop();
            B = pop();
            switch (ch) {
                case '*':
                    val = B * A;
                    break;
                case '/':
                    val = B / A;
                    break;
                case '+':
                    val = B + A;
                    break;
                case '-':
                    val = B - A;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return;
            }
            /* push the value obtained above onto the stack */
            push(val);
        }
        i++;
    }
    if (top == 0) {
        printf("\nResult of expression evaluation: %d\n", pop());
    } else {
        printf("Invalid postfix expression\n");
    }
}

int main() {
    int i;

    /* declare a character array to store the postfix expression */
    char postfix[POSTFIXSIZE];
    printf("ASSUMPTION: There are only four operators(*, /, +, -) in an expression, and an operand is a single digit only.\n");
    printf("\nEnter the postfix expression,\npress right parenthesis ')' to end the expression: ");

    /* take input of the postfix expression from the user */
    for (i = 0; i <= POSTFIXSIZE - 1; i++) {
        scanf(" %c", &postfix[i]);
        if (postfix[i] == ')') {
            postfix[i] = '\0'; // Terminate the expression when ')' is encountered
            break;
        }
    }

    /* call the function to evaluate the postfix expression */
    EvalPostfix(postfix);
    return 0;
}
