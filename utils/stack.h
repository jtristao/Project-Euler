#ifndef _STACK_H_
#define _STACK_H_

/********************************************************
	Implementation of a stack using a array of integers.
	Useful for big numbers problems.
********************************************************/

typedef struct{
	int *vector, top;
}STACK;

// Start a empty stack and return its address
STACK *stack_init();

// Insert a new element in the stack
void stack_push(STACK *s, int x);

// Remove a element from the stack
int stack_pop(STACK *s);

int stack_total(STACK *s);

// Check if the stack is empty
int stack_empty(STACK *s);

// Print the values in the stack
void stack_print(STACK *s);

void stack_copy(STACK *dest, STACK *src);

// Reverse the postion of the elements in the stack -> O(n)
void stack_reverse(STACK **s);

// Reset the stack
void stack_reset(STACK *s);

// Free the memeory used in the stack
void stack_free(STACK *s);

// -------------------------------------------------------------------------------------------------

// Add the contents of a,b and stores in c
void big_add(STACK *a, STACK *b, STACK **c);

#endif
