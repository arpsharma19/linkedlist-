#include <stdio.h>
#include <stdlib.h>

// Queue structure
struct queue {
    int front, rear, size;
    int *arr;
};

// Stack structure using two queues
struct stack {
    struct queue q1;
    struct queue q2;
};

// Function to initialize the queue
void init_queue(struct queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));
}

// Function to check if the queue is empty
int is_empty(struct queue *q) {
    return q->front == -1;
}

// Function to enqueue an element to the queue
void enqueue(struct queue *q, int data) {
    if (q->rear == q->size - 1) {
        printf("Queue is full.\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = data;
}

// Function to dequeue an element from the queue
int dequeue(struct queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) { // If last element is dequeued
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return data;
}

// Function to initialize the stack
void init_stack(struct stack *s, int size) {
    init_queue(&s->q1, size);
    init_queue(&s->q2, size);
}

// Function to push an element onto the stack
void push(struct stack *s, int data) {
    enqueue(&s->q2, data);  // Insert the new element into q2

    // Move all elements from q1 to q2
    while (!is_empty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap q1 and q2 so that q1 becomes the main queue
    struct queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;  // q2 is now empty and ready for next use
}

// Function to pop an element from the stack
int pop(struct stack *s) {
    if (is_empty(&s->q1)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return dequeue(&s->q1);
}

// Function to get the top element of the stack
int top(struct stack *s) {
    if (is_empty(&s->q1)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->q1.arr[s->q1.front];
}

// Main function to test stack operations
int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    struct stack s;
    init_stack(&s, size);

    // Push elements to the stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 13);
    push(&s, 44);
    push(&s, 24);

    // Check the top element
    printf("Top element: %d\n", top(&s));  // Should print 30

    // Pop elements from the stack
    printf("Popped: %d\n", pop(&s));  // Should print 30
    printf("Popped: %d\n", pop(&s));  // Should print 20

    return 0;
}
