#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}


int isEmpty(struct Node* top) {
    return !top;
}


void push(struct Node** top, int data) {
    struct Node* node = newNode(data);
    node->next = *top;
    *top = node;
    printf("%d pushed to stack\n", data);
}


int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}


int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}


int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(stack));

    printf("%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(stack));

    return 0;
}