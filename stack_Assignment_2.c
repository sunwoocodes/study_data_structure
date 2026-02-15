#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

typedef struct StackType {
	char arr[SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	if (s->top == -1)
		return 1;
	return 0;
}

int is_full(StackType* s) {
	if (s->top == SIZE - 1)
		return 1;
	return 0;
}

int push(StackType* s, int value) {
	if (is_full(s)) {
		printf("Stack is full");
		exit(1);
	}
	printf("Push %c\n", value);
	s->arr[++(s->top)] = value;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		printf("Stack is empty");
		exit(1);
	}
	return s->arr[(s->top)--];
}

int pre(char* str) {
	StackType s;
	init(&s);
	char cleaned[SIZE];
	int j = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		cleaned[j++] = str[i];
	}
	cleaned[j] = '\0';

	int len = strlen(cleaned);
	for (int i = 0; i < len / 2; i++) {
		if (cleaned[i] == '(') {
			cleaned[i] = ')';
			push(&s, cleaned[i]);
		}
		else if (cleaned[i] == ')') {
			cleaned[i] = '(';
			push(&s, cleaned[i]);
		}
		else if (cleaned[i] == ']') {
			cleaned[i] = '[';
			push(&s, cleaned[i]);
		}
		else if (cleaned[i] == '[') {
			cleaned[i] = ']';
			push(&s, cleaned[i]);
		}
	}

	int start = len / 2;
	for (int i = start; i < len; i++) {
		if (cleaned[i] != pop(&s))
			return 0;
	}
	return 1;
}

int main() {
	char* test1 = "((()))";
	char* test2 = "([[]]]";

	printf("\n'%s' -> %s\n", test1, pre(test1) ? "True\n\n" : "False\n\n");
	printf("\n'%s' -> %s\n", test2, pre(test2) ? "True\n\n" : "False\n\n");
	return 0;
}

#endif