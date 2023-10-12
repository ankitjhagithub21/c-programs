#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define a stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push element onto the stack.\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop from an empty stack.\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to return the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    }
    return 0;
}

// Function to convert infix to postfix expression
void infixToPostfix(char *infix, char *postfix) {
    struct Stack stack;
    initialize(&stack);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("Invalid expression (unmatched parenthesis).\n");
                exit(1);
            } else {
                pop(&stack); // Pop '('
            }
        } else {
            while (!isEmpty(&stack) && getPrecedence(token) <= getPrecedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
