#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

void enqueue(struct Queue* q, int data) {
    struct Node* node = newNode(data);
    
    if (q->rear == NULL) {
        q->front = q->rear = node;
        printf("%d enqueued to queue\n", data);
        return;
    }

    q->rear->next = node;
    q->rear = node;
    printf("%d enqueued to queue\n", data);
}


int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    int dequeued = temp->data;
    free(temp);
    return dequeued;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Front element is %d\n", peek(q));

    printf("%d dequeued from queue\n", dequeue(q));
    printf("Front element is now %d\n", peek(q));

    return 0;
}