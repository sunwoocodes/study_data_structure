#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

typedef struct StackType {
	char arr[SIZE];
	int top;
} StackType;

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

int push(StackType* s, char value) {
	if (is_full(s)) {
		printf("Stack is full\n");
		exit(1);
	}
	printf("Push: %c\n", value);
	s->arr[++(s->top)] = value;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		printf("Stack is empty\n");
		exit(1);
	}
	return s->arr[(s->top)--];
}

int pre(char* str) {
	StackType s;
	init(&s);
	char cleaned[SIZE];
	int j = 0;

	//1. 소문자로 변환 및 공백 제거
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			cleaned[j++] = tolower(str[i]);
		}
	}
	cleaned[j] = '\0';

	//2. 문자열 절반 스택에 push
	int len = strlen(cleaned);
	for (int i = 0; i < len / 2; i++) {
		push(&s, cleaned[i]);
	}

	//3. 문자열의 나머지 절반과 스택의 pop 값 비교
	//   길이가 홀수일 경우 중간 문자 무시
	int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;
	for (int i = start; i < len; i++) {
		if (cleaned[i] != pop(&s))
			return 0;
	}
	return 1;
}

int main() {
	char* test1 = "Now I won";
	char* test2 = "race car";

	printf("\n'%s' -> %s\n", test1, pre(test1) ? "True\n\n" : "False\n\n");
	printf("\n'%s' -> %s\n", test2, pre(test2) ? "True\n\n" : "False\n\n");

	return 0;
}