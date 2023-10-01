#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

int EvaluatePostfix(char expression[]);

// Function to perform an operation and return output.
int operation(char operation, int operand1, int operand2);

bool IsOperator(char C);

bool IsNumericDigit(char C);

// Declaring a Stack
int S[N];
int top = -1;

int main() {
    char expression[1024];
    printf("Enter Postfix Expression: ");
    scanf(" %[^\n]", expression);
    int result = EvaluatePostfix(expression);
    printf("Output = %d\n", result);
    return 0;
}

int EvaluatePostfix(char expression[]) {
    int length_expression = strlen(expression);

    for (int i = 0; i < length_expression; i++) {
        if (expression[i] == ' ' || expression[i] == ',')
            continue;
        else if (IsOperator(expression[i])) {
            if (top < 1) {
                printf("Invalid postfix expression\n");
                exit(1);
            }
            // Pop two operands.
            int operand2 = S[top];
            top--;
            int operand1 = S[top];
            top--;
            // Perform operation
            int result = operation(expression[i], operand1, operand2);
            // Push back result of operation on stack.
            S[++top] = result;
        } else if (IsNumericDigit(expression[i])) {
            // Extract the numeric operand from the string
            int operand = 0;
            while (i < length_expression && IsNumericDigit(expression[i])) {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            i--;

            if (top == N - 1) {
                printf("Stack Overflow\n");
                exit(1);
            }

            S[++top] = operand;
        }
    }
    return S[top];
}

bool IsNumericDigit(char C) {
    return (C >= '0' && C <= '9');
}

bool IsOperator(char C) {
    return (C == '+' || C == '-' || C == '*' || C == '/');
}

int operation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Division by zero\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            printf("Unexpected Error\n");
            exit(1);
    }
}