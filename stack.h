#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct listnode{
	char data;
	Listnode *next;
} Listnode;

typedef struct stack{
	Listnode *top;
} Stack;

void initStack(Stack *s){
	s->top = NULL;
}
bool stackfull(Stack *s){
	return 0;
}
bool stackempty(Stack *s){
	return (s->top == NULL);
}
void pushStack(Stack *s, char c){
	Listnode *current = (Listnode *)malloc(sizeof(Listnode));
	assert(current != NULL);
	current->data = c;
	current->next = s->top;
	s->top = current;
}
char popStack(Stack *s){
	if(stackempty(s)) return -1;

	Listnode *current = s->top;
	s->top = s->top->next;
	char c = current->data;
	free(current);
	return c;
}