#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/*
 * Stack is a data structure that stores a sequence of elements and allows adding
 * and removing elements in a last-in, first-out (LIFO) manner.
 */
typedef struct Stack {
    int data[STACK_SIZE];
    int top;
} Stack;

/*
 * createStack creates a new empty stack and returns a pointer to it.
 */
Stack *createStack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

/*
 * push adds an element to the top of the stack. If the stack is full, the
 * function has no effect.
 */
void push(Stack *stack, int value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->top++;
        stack->data[stack->top] = value;
    }
}

/*
 * pop removes the element at the top of the stack and returns it. If the stack
 * is empty, the function returns -1.
 */
int pop(Stack *stack) {
    if (stack->top >= 0) {
        int value = stack->data[stack->top];
        stack->top--;
        return value;
    }
    return -1;
}

/*
 * peek retrieves the element at the top of the stack without removing it. If the
 * stack is empty, the function returns -1.
 */
int peek(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return -1;
}

/*
 * isEmpty returns 1 if the stack is empty, and 0 otherwise.
 */
int isEmpty(Stack *stack) {
    return stack->top < 0;
}

int main() {
    Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);
    printf("%d\n", peek(stack));  // prints 2
    printf("%d\n", pop(stack));  // prints 2
    printf("%d\n", pop(stack));  // prints 1
    printf("%d\n", isEmpty(stack));  // prints 1
    return 0;
}