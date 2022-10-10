#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 5

typedef struct {
	size_t size;
	size_t top;
	int* array;
} Stack;

void init(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, int element);
void destroy(Stack* s);
int pop(Stack* s);
