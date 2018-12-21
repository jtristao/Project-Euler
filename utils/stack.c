#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

STACK *stack_init(){
	STACK *aux;

	aux = (STACK *)malloc(sizeof(STACK));
	if(aux){
		aux->top = 0;	
		aux->vector = (int *)malloc(sizeof(int));
		return aux;
	}else{
		printf("malloc failed");
		return NULL;	
	}
}

void stack_push(STACK *s, int x){
	s->vector = (int *)realloc(s->vector, sizeof(int) * (s->top+1));
	s->vector[s->top] = x;
	s->top++;
}

int stack_pop(STACK *s){
	if(stack_empty(s) == 1)
		return s->vector[--(s->top)];
	else
		return 0;
}

int stack_total(STACK *s){
	return s->top+1;
}

int stack_empty(STACK *s){
	if(s->top == 0)
		return 0;
	return 1;
}

void stack_copy(STACK *dest, STACK *src){
	stack_reset(dest);
	for(int i = 0; i < src->top; i++){
		stack_push(dest, src->vector[i]);
	}
}

void stack_print(STACK *s){
       for(int i = 0; i < s->top; i++)
               printf("%d", s->vector[i]);
       printf("\n");
}

void stack_reverse(STACK **a){
	STACK *b, *aux;

	b = stack_init();
	while((*a)->top != 0)
		stack_push(b, stack_pop(*a));
	
	aux = *a;
	*a = b;
	
	stack_free(aux);
}

void stack_reset(STACK *s){
	s->top = 0;
}

void stack_free(STACK *a){
	free(a->vector);
	free(a);
}

void big_add(STACK *a, STACK *b, STACK **c){
       STACK *copy_a, *copy_b;
       int s, extra, limit;
       
       // Preserve the old stack;
       copy_a = stack_init();
       copy_b = stack_init();
       stack_copy(copy_a, a);
       stack_copy(copy_b, b);

       // Clear c
       stack_reset(*c);

       extra = 0;
       //check wich number stack is bigger
       if(a->top > b->top)
               limit = a->top;
        else
               limit = b->top;
       
       while(limit > 0){       
               s = stack_pop(copy_a) + stack_pop(copy_b);
               s+=extra;
               if(s > 9){
                       stack_push(*c, s%10);
                       extra = 1;
               }else{
                       stack_push(*c, s);
                       extra = 0;
               }
               limit--;
       }
       if(extra)
               stack_push(*c, extra);
       
       stack_reverse(c);

       stack_free(copy_a);
       stack_free(copy_b);
}
