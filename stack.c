#include "stack.h"

void init(Stack* s) {
	s->size = INIT_SIZE;
	s->top = 0;
	s->array = malloc(s->size * sizeof(int));
	if (s->array == NULL) {
		printf("Error during stack allocation");
		abort();
	}
}

bool isEmpty(Stack* s) { return s->top <= 0; }

bool isFull(Stack* s) { return s->top >= s->size - 1; }

void resize(Stack* s) {
	s->size = s->size * 2;
	int* newArray = realloc(s->array, s->size * sizeof(int));
	if (newArray) {
		s->array = newArray;
	} else {
		printf("Error during stack realocation\n");
		abort();
	}
}

void push(Stack* s, int element) {
	if (isFull(s)) {
		resize(s);
	} else {
		s->array[s->top] = element;
		s->top++;
	}
}

void destroy(Stack* s) { free(s->array); }

int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Poping empty stack\n");
		destroy(s);
		exit(1);
	} else {
		s->top = s->top - 1;
		return s->array[s->top];
	}
}

