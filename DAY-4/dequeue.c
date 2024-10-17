
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

void insertFront(struct Deque* deque, int data) {
    struct Node* node = newNode(data);
    
    if (isEmpty(deque)) {
        deque->front = deque->rear = node;
    } else {
        node->next = deque->front;
        deque->front->prev = node;
        deque->front = node;
    }
    printf("%d inserted at front\n", data);
}

void insertRear(struct Deque* deque, int data) {
    struct Node* node = newNode(data);
    
    if (isEmpty(deque)) {
        deque->front = deque->rear = node;
    } else {
        node->prev = deque->rear;
        deque->rear->next = node;
        deque->rear = node;
    }
    printf("%d inserted at rear\n", data);
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        return -1;
    }

    struct Node* temp = deque->front;
    int data = temp->data;

    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL; // Deque is empty
    } else {
        deque->front->prev = NULL;
    }

    free(temp);
    return data;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque underflow\n");
        return -1;
    }

    struct Node* temp = deque->rear;
    int data = temp->data;

    deque->rear = deque->rear->prev;

    if (deque->rear == NULL) {
        deque->front = NULL; // Deque is empty
    } else {
        deque->rear->next = NULL;
    }

    free(temp);
    return data;
}

int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->front->data;
}

int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->rear->data;
}

int main() {
    struct Deque* deque = createDeque();

    insertRear(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);

    printf("Front element: %d\n", getFront(deque));
    printf("Rear element: %d\n", getRear(deque));

    printf("%d removed from front\n", deleteFront(deque));
    printf("Front element: %d\n", getFront(deque));

    printf("%d removed from rear\n", deleteRear(deque));
    printf("Rear element: %d\n", getRear(deque));

    return 0;
}
