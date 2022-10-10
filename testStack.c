#include "stack.h"

void testRegularPush();
void overlimitPush();
void popTest();
void overlimitPop();
void testIsEmpty();
void testIsFull();
void testStacks(Stack* s1, Stack* s2);

int main() {
    Stack s1;
	init(&s1);
    Stack s2;
    init(&s2);
	testStacks(&s1, &s2);
	return 0;
}

void testStacks(Stack* s1, Stack* s2){
    testIsEmpty(s1);
    testIsEmpty(s2);
	testRegularPush(s1);
    testRegularPush(s2);
    testIsFull(s1);
    testIsFull(s2);
	overlimitPush(s1);
    overlimitPush(s2);
	popTest(s1);
    popTest(s2);
    destroy(s2);
	overlimitPop(s1);
    destroy(s1);
    }
    
void testRegularPush(Stack* stack) {
	printf("\nTesting push function: \n");
    int pushNumber = 1;
    push(stack, pushNumber);
	printf("Regular push test successful, current max size = %ld, init max "
		   "size = %d\n\n",
		   stack -> size, INIT_SIZE);
}

void overlimitPush(Stack* stack) {
	printf("\nTesting push function over the max limit: \n");
	for (int i = 0; i < INIT_SIZE + 1; i++) {
		push(stack, i);
	}
	printf("Overlimit push test successful, current max size = %ld, init max "
		   "size = %d\n\n",
		   stack -> size, INIT_SIZE);
}

void popTest(Stack* stack) {
	printf("\nTesting pop function:\n");
	int result = pop(stack);
	if (result) {
		printf("Pop test successful\n\n");
	} else {
		printf("Pop test failed");
	}
}

void overlimitPop(Stack* stack) {
	printf("\nTesting pop function over the limit:\n");
	printf("WARNING if this function is active program should print `poping "
		   "empty stack` and terminate:\n");
    for (int i = 0; i < INIT_SIZE*2; i++) {
		pop(stack);
	}
	printf("Program did not terminate, overlimit pop test failed\n");
}

void testIsEmpty(Stack* stack) {
	printf("\nTesting isEmpty function:\n");
	if (isEmpty(stack)) {
		printf("Stack empty, test passed\n\n");
	} else {
		printf("Stack not empty, test failed\n\n");
	}
}

void testIsFull(Stack* stack) {
	printf("\nTesting isFull function:\n");
	for (int i = 0; stack -> top < (stack -> size)-1; i++) {
		push(stack, i);
	}
	if (isFull(stack)) {
		printf("Stack full, test successful\n\n");
	} else {
		printf("IsFull function test failed\n\n");
	}
}
