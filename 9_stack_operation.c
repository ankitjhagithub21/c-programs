#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100


struct Stack {
    int items[MAX_STACK_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}


bool isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}


bool isFull(struct Stack *stack) {
    return (stack->top == MAX_STACK_SIZE - 1);
}


void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow.\n");
    } else {
        stack->items[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}


int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is Underflow\n");
        return -1; 
    } else {
        int popped = stack->items[stack->top--];
        return popped;
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack)); 

    return 0;
}
