/*Write a program to implement basic operation of Circular queue:*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;   
 
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}   
int isFull(CircularQueue *q) {
    if((q->front == 0 && q->rear == MAX - 1) || (q->rear == (q->front - 1) % (MAX - 1))) {
        return 1;
    }
    return 0;
}
int isEmpty(CircularQueue *q) {
    if(q->front == -1) {
        return 1;
    }
    return 0;
}
void enqueue(CircularQueue *q, int value) {
    if(isFull(q)) { 
        printf("Queue is full!\n");
        return;
    }           
    if(isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
}
int dequeue(CircularQueue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return item;
}
void display(CircularQueue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");            
        return;
    }          
    printf("Circular Queue elements: \n");                  
    int i = q->front;
    while(1) {
        printf("%d ", q->items[i]);                 
        if(i == q->rear) {
            break;
        }       

        i = (i + 1) % MAX;
    }
    printf("\n");               
}     

int main() {

    CircularQueue q;
    initQueue(&q);
    int choice, value;

    while(1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if(value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
