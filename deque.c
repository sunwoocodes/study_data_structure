//#if 0

#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 5

typedef int element;
typedef struct DequeType {
	element data[MAX_DEQUE_SIZE];
	int front; //Frint index
	int rear; //Last index
} DequeType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(DequeType* d) {
	d->front = d->rear = 0;
}

int is_full(DequeType* d) {
	return ((d->rear + 1) % MAX_DEQUE_SIZE == d->front);
}

int is_empty(DequeType* d) {
	return d->front == d->rear;
}

void add_rear(DequeType* d, element item) {
	if (is_full(d))
		error("Deque is full");
	//when data is added in deque, always we should check rear value
	d->rear = (d->rear + 1) % MAX_DEQUE_SIZE;
	return d->data[d->front];
}

element delete_front(DequeType* d) {
	if (is_empty(d))
		error("Deque is empty");
	//when data is delete from deque, always we should check front value
	d->front = (d->front + 1) % MAX_DEQUE_SIZE;
	return d->data[d->front];
}

void add_front(DequeType* d, element item) {
	if (is_full(d))
		error("Deque is full");
	d->data[d->front] = item;
	d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

element delete_rear(DequeType* d) {
	int prev = d->rear;
	if (is_empty(d))
		error("Deque is empty");
	d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return d->data[prev];
}

element get_rear(DequeType* d) {
	if (is_empty(d))
		error("Deque is empty");
	return d->data[d->rear];
}

element get_front(DequeType* d) {
	if (is_empty(d))
		error("Deque is empty");
	return d->data[(d->front + 1) % MAX_DEQUE_SIZE];
}

int main(int argc, const char * argv[]) {
	DequeType deque;
	init_deque(&deque);

	for (int i = 0; i < 3; i++)
		add_front(&deque, i);

	printf("\n%d", get_front(&deque));
	printf("\n%d", get_rear(&deque));

	for (int i = 0; i < 3; i++) {
		printf("\n%d", delete_rear(&deque));
	}

	return 0;
}

//#endif