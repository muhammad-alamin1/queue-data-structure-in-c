#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

bool is_full();
bool is_empty();
void print_queue();
void enqueue(int item);
int dequeue();

int my_queue[CAPACITY];
int front = 0, rear = -1, total_item = 0;

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    print_queue();
    enqueue(60); // queue is full
    printf("Dequeue item : %d\n", dequeue());
    print_queue();
    enqueue(70);
    print_queue(); // circular queue concept

    return 0;
}

// is array full
bool is_full()
{
    if(total_item == CAPACITY)
        return true;
    return false;
}

// array is empty
bool is_empty()
{
    if(total_item == 0)
        return true;
    return false;
}

// print
void print_queue()
{
    printf("Queue : ");
    for(int i = 0; i < CAPACITY; i++)
    {
        printf("%d ", my_queue[i]);
    }
    printf("\n");
}

// enqueue
void enqueue(int item)
{
    if(is_full())
    {
        printf("Sorry, the Queue is full.\n");
        return;
    }
    rear = (rear + 1) % CAPACITY;
    my_queue[rear] = item;
    total_item++;
}

// dequeue
int dequeue()
{
    int front_item;

    if(is_empty())
    {
        printf("Sorry! the queue is empty.\n");
        return -1;
    }
    front_item = my_queue[front];
    my_queue[front] = -1;
    front = (front + 1) % CAPACITY;
    total_item--;

    return front_item;
}
