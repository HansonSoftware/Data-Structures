#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

/*
 * Queue is a data structure that stores a sequence of elements and allows adding
 * and removing elements in a first-in, first-out (FIFO) manner.
 */
typedef struct Queue {
    int data[QUEUE_SIZE];
    int head;
    int tail;
} Queue;

/*
 * createQueue creates a new empty queue and returns a pointer to it.
 */
Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

/*
 * enqueue adds an element to the back of the queue. If the queue is full, the
 * function has no effect.
 */
void enqueue(Queue *queue, int value) {
    if ((queue->tail + 1) % QUEUE_SIZE != queue->head) {
        queue->data[queue->tail] = value;
        queue->tail = (queue->tail + 1) % QUEUE_SIZE;
    }
}

/*
 * dequeue removes the element at the front of the queue and returns it. If the
 * queue is empty, the function returns -1.
 */
int dequeue(Queue *queue) {
    if (queue->head != queue->tail) {
        int value = queue->data[queue->head];
        queue->head = (queue->head + 1) % QUEUE_SIZE;
        return value;
    }
    return -1;
}

/*
 * peek retrieves the element at the front of the queue without removing it. If the
 * queue is empty, the function returns -1.
 */
int peek(Queue *queue) {
    if (queue->head != queue->tail) {
        return queue->data[queue->head];
    }
    return -1;
}

/*
 * isEmpty returns 1 if the queue is empty, and 0 otherwise.
 */
int isEmpty(Queue *queue) {
    return queue->head == queue->tail;
}

int main() {
    Queue *queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    printf("%d\n", peek(queue));  // prints 1
    printf("%d\n", dequeue(queue));  // prints 1
    printf("%d\n", dequeue(queue));  // prints 2
    printf("%d\n", isEmpty(queue));  // prints 1
    return 0;
}
