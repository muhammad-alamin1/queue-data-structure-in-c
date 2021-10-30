#include <stdio.h>

#define CAPACITY 5

typedef struct
{
    int data[CAPACITY + 1];
    int front, rear;
} Queue;

void enqueue(Queue *q, int item);
int dequeue(Queue *q);

int main()
{
    Queue my_queue;
    int item;

    my_queue.front = 0;
    my_queue.rear = 0;

    enqueue(&my_queue, 4);
    printf("Rear = %d\n", my_queue.rear);
    item = dequeue(&my_queue);
    printf("Front = %d\n", item);

    // enqueue call
    enqueue(&my_queue, 4);
    enqueue(&my_queue, 5);
    enqueue(&my_queue, 6);
    enqueue(&my_queue, 7);
    enqueue(&my_queue, 8);
    enqueue(&my_queue, 9); // Queue Full

    // dequeue call
    item = dequeue(&my_queue);
    item = dequeue(&my_queue);
    item = dequeue(&my_queue);
    item = dequeue(&my_queue);
    item = dequeue(&my_queue);
    printf("Front = %d\n", item);
    item = dequeue(&my_queue); // front = -1 EMPTY
    printf("Front = %d\n", item);


    return 0;
}

// enqueue
void enqueue(Queue *q, int item)
{
    if((q->rear + 1) % (CAPACITY + 1) == q->front)
    {
        printf("Queue is full.\n");
        return;
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % (CAPACITY + 1);
}

// dequeue
int dequeue(Queue *q)
{
    int item;

    if(q->rear == q->front)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    item = q->data[q->front];
    q->front = (q->front + 1) % (CAPACITY + 1);

    return item;
}
