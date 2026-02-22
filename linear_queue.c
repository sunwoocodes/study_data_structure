#if 0

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue {
	int front; //Frint index
	int rear; //Last index
	int data[MAX];
} Queue;

void init(Queue* q) {
	q->front = q->rear = -1;
}

int is_full(Queue* q) {
	if (q->rear == MAX - 1)
		return 1;
	return 0;
}

int is_empty(Queue* q) {
	if (q->front == q->rear)
		return 1;
	return 0;
}

void enqueue(Queue* q, int item) {
	if (is_full(q)) {
		printf("Error: Queue is full");
		exit(1);
	}
	q->data[++(q->rear)] = item;
}

int dequeue(Queue* q) {
	if (is_empty(q)) {
		printf("Error: Queue is empty");
		exit(1);
	}
	return q->data[++(q->front)];
}

int main() {
	Queue q;
	init(&q);

	enqueue(&q, 3);
	enqueue(&q, 2);
	enqueue(&q, 1);

	printf("%d", dequeue(&q));
	printf("%d", dequeue(&q));
	printf("%d", dequeue(&q));
	printf("\n");

	return 0;
}

#endif