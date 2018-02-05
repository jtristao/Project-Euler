#ifndef _STACK_H_
#define _STACK_H_

typedef struct{
	int *vector, top;
}STACK;

STACK *stack_init();
void stack_push();
int stack_pop();
int stack_empty();
void stack_print();
void big_add();
void stack_reverse();
void stack_free();

#endif
