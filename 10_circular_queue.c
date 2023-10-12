#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 5

// Define a structure for the circular queue
struct CircularQueue {
    int items[MAX_QUEUE_SIZE];
    int front, rear;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
bool isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1);
}

// Function to check if the circular queue is full
bool isFull(struct CircularQueue *queue) {
    return ((queue->front == 0 && queue->rear == MAX_QUEUE_SIZE - 1) || (queue->rear == (queue->front - 1) % (MAX_QUEUE_SIZE - 1)));
}

// Function to insert an element into the circular queue
void insert(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = queue->rear = 0;
        } else if (queue->rear == MAX_QUEUE_SIZE - 1 && queue->front != 0) {
            queue->rear = 0;
        } else {
            queue->rear++;
        }
        queue->items[queue->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to delete an element from the circular queue
int delete(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete from an empty queue.\n");
        return -1; // Return a sentinel value for an empty queue
    } else {
        int deleted = queue->items[queue->front];

        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else if (queue->front == MAX_QUEUE_SIZE - 1) {
            queue->front = 0;
        } else {
            queue->front++;
        }

        return deleted;
    }
}

int main() {
    struct CircularQueue queue;
    initialize(&queue);

    insert(&queue, 10);
    insert(&queue, 20);
    insert(&queue, 30);

    printf("Deleted: %d\n", delete(&queue));
    printf("Deleted: %d\n", delete(&queue));
    printf("Deleted: %d\n", delete(&queue));

    insert(&queue, 40);
    insert(&queue, 50);

    printf("Deleted: %d\n", delete(&queue));
    printf("Deleted: %d\n", delete(&queue));

    return 0;
}
